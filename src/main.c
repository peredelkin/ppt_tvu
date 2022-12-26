#include "init.h"
#include "gpio.h"
#include "spi.h"
#include "spi_settings.h"
#include "parity.h"
#include "tic12400.h"
#include "tic12400_settings.h"
#include "ncv7608.h"
#include "dac7562.h"

gpio_pin_t bgr_led[3] = {
		GPIO_PIN(GPIOH, GPIO_PIN_10),
		GPIO_PIN(GPIOH, GPIO_PIN_11),
		GPIO_PIN(GPIOH, GPIO_PIN_12)
};

SPI_BUS_TypeDef SPI_AIO_Bus;
SPI_BUS_TypeDef SPI_DIO_Bus;

void TIM2_IRQHandler() {
	sys_timer_irq_handler();
}

void SPI2_IRQHandler() {
	SPI_BUS_IRQHandler(&SPI_AIO_Bus);
}

void SPI4_IRQHandler() {
	SPI_BUS_IRQHandler(&SPI_DIO_Bus);
}

SPI_BUS_DATA_TypeDef tic124_spi_bus_data_control_array[TIC12400_FRAME_COUNT];

void tic124_spi_bus_data_control_array_fill(void) {
	for(int i = 0; i < TIC12400_FRAME_COUNT; i++) {
		tic124_spi_bus_data_control_array[i].tx = (uint8_t*)&tic124_tx_frame[i].all;
		tic124_spi_bus_data_control_array[i].rx = (uint8_t*)&tic124_rx_frame[i].all;
		tic124_spi_bus_data_control_array[i].count = 4;
	}
}

void tic124_start_normal_operation(void) {
	while(SPI_DIO_Bus.done == false);

	TIC12400_CONFIG_REG config;
	//чтение настроек
	config.all = tic124_settings_const.CONFIG.all;
	//изменение настроек
	config.bit.poll_en = 0x1; /*Polling enabled*/
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
	spi_bus_transfer(&SPI_DIO_Bus, &tic124_spi_bus_data_control_array[TIC12400_CONFIG], 1, SPI_BYTE_ORDER_REVERSE);
}

uint8_t tic12400_digital_input[10];
uint16_t tic12400_analog_input[6];

void tic12400_stat_read() {
	spi_bus_transfer(&SPI_DIO_Bus, &tic124_spi_bus_data_control_array[TIC12400_IN_STAT_COMP], 1, SPI_BYTE_ORDER_REVERSE);
	spi_bus_transfer(&SPI_DIO_Bus, &tic124_spi_bus_data_control_array[TIC12400_ANA_STAT1], 3, SPI_BYTE_ORDER_REVERSE);
	while(SPI_DIO_Bus.done == false);

	TIC12400_IN_STAT_COMP_REG in_stat_comp;

	in_stat_comp.all = tic124_rx_frame[TIC12400_IN_STAT_COMP].bit.data;

	tic12400_digital_input[0] = in_stat_comp.bit.inc_8;		//DI1
	tic12400_digital_input[1] = in_stat_comp.bit.inc_9;		//DI2
	tic12400_digital_input[2] = in_stat_comp.bit.inc_10;	//DI3
	tic12400_digital_input[3] = in_stat_comp.bit.inc_11;	//DI4
	tic12400_digital_input[4] = in_stat_comp.bit.inc_12;	//DI5
	tic12400_digital_input[5] = in_stat_comp.bit.inc_13;	//DI6
	tic12400_digital_input[6] = in_stat_comp.bit.inc_14;	//DI7
	tic12400_digital_input[7] = in_stat_comp.bit.inc_15;	//DI8
	tic12400_digital_input[8] = in_stat_comp.bit.inc_19;	//DI9
	tic12400_digital_input[9] = in_stat_comp.bit.inc_20;	//DI10

	TIC12400_ANA_STAT_REG ana_stat;

	ana_stat.all = tic124_rx_frame[TIC12400_ANA_STAT1].bit.data;
	tic12400_analog_input[0] = ana_stat.bit.in0_ana;	//NTC5
	tic12400_analog_input[1] = ana_stat.bit.in1_ana;	//NTC6

	ana_stat.all = tic124_rx_frame[TIC12400_ANA_STAT2].bit.data;
	tic12400_analog_input[2] = ana_stat.bit.in0_ana;	//NTC4
	tic12400_analog_input[3] = ana_stat.bit.in1_ana;	//NTC1

	ana_stat.all = tic124_rx_frame[TIC12400_ANA_STAT3].bit.data;
	tic12400_analog_input[4] = ana_stat.bit.in0_ana;	//NTC3
	tic12400_analog_input[5] = ana_stat.bit.in1_ana;	//NTC2
}

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

int main(void) {
	rcc_init();
	nvic_init();
	system_timer_init();
	gpio_init();

	spi_bus_init(&SPI_AIO_Bus, SPI2);
	spi_bus_configure(&SPI_AIO_Bus, &spi_dac7562_cfg);

	spi_bus_init(&SPI_DIO_Bus, SPI4);
	spi_bus_configure(&SPI_DIO_Bus, &spi_ncv7608_cfg);

	/*
	spi_bus_configure(&SPI_DIO_Bus, &spi_tic12400_cfg);

	//сброс tic12400
	sys_timer_delay(1, 0);
	gpio_output_bit_setup(&GPO_Reset_DI_App, GPIO_STATE_ON);
	sys_timer_delay(1, 0);
	gpio_output_bit_setup(&GPO_Reset_DI_App, GPIO_STATE_OFF);
	sys_timer_delay(1, 0);

	tic124_tx_frame_fill();

	tic124_spi_bus_data_control_array_fill();

	spi_bus_transfer(&SPI_DIO_Bus, &tic124_spi_bus_data_control_array[TIC12400_CONFIG], 25, SPI_BYTE_ORDER_REVERSE);

	spi_bus_transfer(&SPI_DIO_Bus, &tic124_spi_bus_data_control_array[TIC12400_CONFIG], 25, SPI_BYTE_ORDER_REVERSE);

	tic124_start_normal_operation();

	tic12400_stat_read();
	*/

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

	uint16_t dac_data = 0;

	while(1) {
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
	}
	return 0;
}
