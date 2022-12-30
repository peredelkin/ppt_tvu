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

uint8_t tic12400_digital_input[10];
uint16_t tic12400_analog_input[6];

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
	spi_bus_init(&SPI_DIO_Bus, SPI4);

	spi_bus_configure(&SPI_AIO_Bus, &spi_dac7562_cfg);

	//spi_bus_configure(&SPI_DIO_Bus, &spi_ncv7608_cfg);

	//spi_bus_configure(&SPI_DIO_Bus, &spi_tic12400_cfg);


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

	while(1) {
		/*
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
	}
	return 0;
}
