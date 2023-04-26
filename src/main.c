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

tic12400_t tic12400_Q1;

//dac7562
SPI_BUS_TypeDef SPI2_Bus;

//tic12400
//ncv7608
SPI_BUS_TypeDef SPI4_Bus;

void task_timer_irq_handler() {
	if (TIM5->SR & TIM_SR_UIF) {
		TIM5->SR = ~TIM_SR_UIF;
		if(gpio_input_bit_read(&GPI_Int_DI_App)) {
			gpio_output_bit_setup(&bgr_led[2], GPIO_STATE_ON);
		} else {
			gpio_output_bit_setup(&bgr_led[2], GPIO_STATE_OFF);

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

typedef struct {
	TIC12400_DEVICE_ID_REG DEVICE_ID;
	TIC12400_INT_STAT_REG INT_STAT;
} tic12400_data_t;

tic12400_data_t tic12400_data_array;
uint8_t tic12400_addr_array[2];

void tic12400_Q1_status_handler(tic12400_t *tic) {
	if(tic->tx_frame.bit.addr == tic12400_addr_array[1]) {
		((uint32_t*)&tic12400_data_array)[1] = tic->rx_frame.bit.data;
		tic12400_bus_free(tic);
	} else {
		tic12400_reg_read_from_callback(tic, (uint32_t*)&tic12400_data_array, &tic12400_addr_array[1], 1);
	}
}

void tic12400_Q1_status_callback(void *tic) {
	tic12400_Q1_status_handler(tic);
}

int main(void) {
	rcc_init();
	nvic_init();
	system_timer_init();
	gpio_init();

	spi_bus_init(&SPI2_Bus, SPI2);
	spi_bus_init(&SPI4_Bus, SPI4);

	tic12400_init(&tic12400_Q1, &SPI4_Bus, &spi_tic12400_cfg);

	tic12400_Q1.status_callback = &tic12400_Q1_status_callback;
	tic12400_Q1.status_callback_argument = &tic12400_Q1;

	tic12400_spi_bus_configure(&tic12400_Q1);

	//task_timer_init();

	sys_timer_delay(1, 0);
	gpio_output_bit_setup(&GPO_Reset_DI_App, GPIO_STATE_ON);
	sys_timer_delay(1, 0);
	gpio_output_bit_setup(&GPO_Reset_DI_App, GPIO_STATE_OFF);

	tic12400_addr_array[0] = TIC12400_DEVICE_ID;
	tic12400_addr_array[1] = TIC12400_INT_STAT;

	while (1) {
		sys_timer_delay(0, 50000);
		if (gpio_input_bit_read(&GPI_Int_DI_App)) {
			gpio_output_bit_setup(&bgr_led[2], GPIO_STATE_ON);
		} else {
			gpio_output_bit_setup(&bgr_led[2], GPIO_STATE_OFF);
			tic12400_reg_read(&tic12400_Q1, (uint32_t*)&tic12400_data_array, &tic12400_addr_array[0], 1);
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
