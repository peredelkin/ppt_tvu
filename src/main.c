#include "init.h"
#include "gpio.h"
#include "spi.h"
#include "spi_settings.h"
#include "tic12400.h"
#include "tic12400_settings.h"
#include "ncv7608.h"
#include "dac7562.h"

gpio_pin_t bgr_led[3] = {
		GPIO_PIN(GPIOH, GPIO_PIN_10),
		GPIO_PIN(GPIOH, GPIO_PIN_11),
		GPIO_PIN(GPIOH, GPIO_PIN_12)
};

//dac7562
SPI_BUS_TypeDef SPI2_Bus;

//tic12400
//ncv7608
SPI_BUS_TypeDef SPI4_Bus;

void tic12400_int_stat_read(SPI_BUS_TypeDef* spi_bus);

void task_timer_irq_handler() {
	if (TIM5->SR & TIM_SR_UIF) {
		TIM5->SR = ~TIM_SR_UIF;
		if(gpio_input_bit_read(&GPI_Int_DI_App)) {
			gpio_output_bit_setup(&bgr_led[2], GPIO_STATE_ON);
		} else {
			gpio_output_bit_setup(&bgr_led[2], GPIO_STATE_OFF);
			tic12400_int_stat_read(&SPI4_Bus);
		}
	}
}

void task_timer_init() {
	TIM5->PSC = (90 - 1);
	TIM5->ARR = 1000000;
	TIM5->DIER = TIM_DIER_UIE;
	TIM5->CR1 = TIM_CR1_CEN;
}

void TIM2_IRQHandler() {
	sys_timer_irq_handler();
}

void TIM5_IRQHandler() {
	task_timer_irq_handler();
}

void SPI2_IRQHandler() {
	SPI_BUS_IRQHandler(&SPI2_Bus);
}

void SPI4_IRQHandler() {
	SPI_BUS_IRQHandler(&SPI4_Bus);
}

void tic12400_int_stat_read(SPI_BUS_TypeDef* spi_bus) {
	spi_bus_transfer(spi_bus, &tic124_spi_bus_data_control_array[TIC12400_INT_STAT], 1, SPI_BYTE_ORDER_REVERSE, NULL, NULL);
}

void tic12400_configure(SPI_BUS_TypeDef* spi_bus) {
	spi_bus_transfer(spi_bus, &tic124_spi_bus_data_control_array[TIC12400_CONFIG], 25, SPI_BYTE_ORDER_REVERSE, NULL, NULL);
}

void tic124_start_normal_operation(SPI_BUS_TypeDef* spi_bus) {
	while(spi_bus->done == false);

	TIC12400_CONFIG_REG config;
	//чтение настроек
	config.all = tic124_settings_const.CONFIG.all;
	//изменение настроек
	config.bit.poll_en = 0x1; /*Polling enabled*/ //Нужно ли?
	config.bit.trigger = 0x1; /*Start TIC12400-Q1 to normal operation*/

	//формирование фрейма
	tic124_tx_frame[TIC12400_CONFIG].bit.rw = 1;
	tic124_tx_frame[TIC12400_CONFIG].bit.addr = TIC12400_CONFIG;
	tic124_tx_frame[TIC12400_CONFIG].bit.data = config.all;
	//сброс четности
	tic124_tx_frame[TIC12400_CONFIG].bit.par = 0;
	//расчет четности
	tic124_tx_frame[TIC12400_CONFIG].bit.par = calc_parity(tic124_tx_frame[TIC12400_CONFIG].all, 32, PARITY_ODD);
	//старт приема/передачи
	spi_bus_transfer(spi_bus, &tic124_spi_bus_data_control_array[TIC12400_CONFIG], 1, SPI_BYTE_ORDER_REVERSE, NULL, NULL);
}

uint8_t tic12400_di[48];
uint16_t tic12400_ai[26];

void tic12400_in_stat_comp_handler(void* rx_frame) {
	TIC12400_IN_STAT_COMP_REG in_stat_comp;

	in_stat_comp.all = ((TIC12400_RX_FRAME*)rx_frame)[TIC12400_IN_STAT_COMP].bit.data;

	for(int n=0; n < 24; n++) {
		((uint16_t*)tic12400_di)[n] = (in_stat_comp.all & (1 << n)) ? 1 : 256;
	}
}

void tic12400_in_stat_comp_read(SPI_BUS_TypeDef* spi_bus, SPI_BUS_DATA_TypeDef* spi_bus_data_control_array) {
	spi_bus_transfer(spi_bus, &spi_bus_data_control_array[TIC12400_IN_STAT_COMP], 1, SPI_BYTE_ORDER_REVERSE,
			&tic12400_in_stat_comp_handler, (void*)tic124_rx_frame);
}

void tic12400_ana_stat_handler(void* rx_frame) {
	TIC12400_ANA_STAT_REG ana_stat;

	for(int n=0; n < 13; n++) {
		ana_stat.all = ((TIC12400_RX_FRAME*)rx_frame)[TIC12400_ANA_STAT0 + n].bit.data;
		((uint32_t*)tic12400_ai)[n] = (ana_stat.bit.in1_ana << 16) | ana_stat.bit.in0_ana;
	}
}

void tic12400_ana_stat_read(SPI_BUS_TypeDef* spi_bus, SPI_BUS_DATA_TypeDef* spi_bus_data_control_array) {
	spi_bus_transfer(spi_bus, &spi_bus_data_control_array[TIC12400_ANA_STAT0], 13, SPI_BYTE_ORDER_REVERSE,
			&tic12400_ana_stat_handler, (void*)tic124_rx_frame);
}

void tic12400_stat_read(SPI_BUS_TypeDef* spi_bus) {
	tic12400_in_stat_comp_read(spi_bus, tic124_spi_bus_data_control_array);
	tic12400_ana_stat_read(spi_bus, tic124_spi_bus_data_control_array);
}

int main(void) {
	rcc_init();
	nvic_init();
	system_timer_init();
	gpio_init();

	spi_bus_init(&SPI2_Bus, SPI2);
	spi_bus_init(&SPI4_Bus, SPI4);

	spi_bus_configure(&SPI4_Bus, &spi_tic12400_cfg);
	tic124_tx_frame_fill(tic124_tx_frame, &tic124_settings_const);
	tic124_spi_bus_data_control_array_fill(tic124_spi_bus_data_control_array, tic124_tx_frame, tic124_rx_frame);

	//task_timer_init();

	sys_timer_delay(1, 0);
	gpio_output_bit_setup(&GPO_Reset_DI_App, GPIO_STATE_ON);
	sys_timer_delay(1, 0);
	gpio_output_bit_setup(&GPO_Reset_DI_App, GPIO_STATE_OFF);

	while (1) {
		sys_timer_delay(0, 50000);
		if (gpio_input_bit_read(&GPI_Int_DI_App)) {
			gpio_output_bit_setup(&bgr_led[2], GPIO_STATE_ON);
			tic12400_stat_read(&SPI4_Bus);
		} else {
			gpio_output_bit_setup(&bgr_led[2], GPIO_STATE_OFF);
			tic12400_configure(&SPI4_Bus);
			tic12400_int_stat_read(&SPI4_Bus);
			tic124_start_normal_operation(&SPI4_Bus);
		}
	}
	return 0;
}

/*
//spi_bus_configure(&SPI_DIO_Bus, &spi_tic12400_cfg);

//spi_bus_configure(&SPI_DIO_Bus, &spi_ncv7608_cfg);

//DO
NCV7608_TX_FRAME_REG ncv7608_tx;
NCV7608_RX_FRAME_REG ncv7608_rx;
SPI_BUS_DATA_TypeDef ncv7608_spi_bus_data_control_array = {
		.tx = (uint8_t*)&ncv7608_tx.all,
		.rx = (uint8_t*)&ncv7608_rx.all,
		.count = 2
};


//AO
DAC7562_TX_FRAME_REG DAC7562_VREF_ENABLE = {
		.cmd_addr.bit.cmd = 0x7,
		.cmd_addr.bit.addr = 0x0,
		.data.all = 0x1
};

DAC7562_TX_FRAME_REG DAC7562_GAIN_1_ALL = {
		.cmd_addr.bit.cmd = 0x0,
		.cmd_addr.bit.addr = 0x2,
		.data.all = 0x3
};

DAC7562_TX_FRAME_REG DAC7562_WRITE_AND_UPDATE_DAC_A = {
		.cmd_addr.bit.cmd = 3,
		.cmd_addr.bit.addr = 0,
		.data.all = 32768
};

DAC7562_TX_FRAME_REG DAC7562_WRITE_AND_UPDATE_DAC_B = {
		.cmd_addr.bit.cmd = 3,
		.cmd_addr.bit.addr = 1,
		.data.all = 32768
};

SPI_BUS_DATA_TypeDef dac7562_spi_bus_data_control_array[4];

spi_bus_configure(&SPI_AIO_Bus, &spi_dac7562_cfg);

gpio_output_bit_setup(&GPO_nCLR_App, GPIO_STATE_OFF);
sys_timer_delay(0, 100);
gpio_output_bit_setup(&GPO_nCLR_App, GPIO_STATE_ON);
sys_timer_delay(0, 100);

dac7562_spi_bus_data_control_array[0].tx = (uint8_t*)&DAC7562_VREF_ENABLE;
dac7562_spi_bus_data_control_array[0].rx = NULL;
dac7562_spi_bus_data_control_array[0].count = 3;

dac7562_spi_bus_data_control_array[1].tx = (uint8_t*)&DAC7562_GAIN_1_ALL;
dac7562_spi_bus_data_control_array[1].rx = NULL;
dac7562_spi_bus_data_control_array[1].count = 3;

dac7562_spi_bus_data_control_array[2].tx = (uint8_t*)&DAC7562_WRITE_AND_UPDATE_DAC_A;
dac7562_spi_bus_data_control_array[2].rx = NULL;
dac7562_spi_bus_data_control_array[2].count = 3;

dac7562_spi_bus_data_control_array[3].tx = (uint8_t*)&DAC7562_WRITE_AND_UPDATE_DAC_B;
dac7562_spi_bus_data_control_array[3].rx = NULL;
dac7562_spi_bus_data_control_array[3].count = 3;

spi_bus_transfer(&SPI_AIO_Bus, dac7562_spi_bus_data_control_array, 4, SPI_BYTE_ORDER_REVERSE);

while(SPI_AIO_Bus.done == false);

sys_timer_delay(0, 100);
gpio_output_bit_setup(&GPO_nLDAC_App, GPIO_STATE_OFF);
sys_timer_delay(0, 100);
gpio_output_bit_setup(&GPO_nLDAC_App, GPIO_STATE_ON);


		ncv7608_tx.bit.driver_2_ena = ncv7608_tx.bit.driver_1_ena;
		ncv7608_tx.bit.driver_1_ena = ncv7608_tx.bit.driver_3_ena;
		ncv7608_tx.bit.driver_3_ena = ncv7608_tx.bit.driver_4_ena;
		ncv7608_tx.bit.driver_4_ena = ncv7608_tx.bit.driver_8_ena;
		ncv7608_tx.bit.driver_8_ena = ncv7608_tx.bit.driver_7_ena;
		ncv7608_tx.bit.driver_7_ena = ncv7608_tx.bit.driver_5_ena;
		ncv7608_tx.bit.driver_5_ena = ncv7608_tx.bit.driver_6_ena;
		ncv7608_tx.bit.driver_6_ena = !ncv7608_tx.bit.driver_2_ena;
		spi_bus_transfer(&SPI_DIO_Bus, &ncv7608_spi_bus_data_control_array, 1, SPI_BYTE_ORDER_NORMAL);
		sys_timer_delay(0, 100000);


 */
