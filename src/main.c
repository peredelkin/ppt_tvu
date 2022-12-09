#include "init.h"
#include "gpio.h"
#include "spi.h"
#include "parity.h"
#include "tic12400.h"
#include "tic12400_settings.h"

gpio_pin_t bgr_led[3] = {
		GPIO_PIN(GPIOH, GPIO_PIN_10),
		GPIO_PIN(GPIOH, GPIO_PIN_11),
		GPIO_PIN(GPIOH, GPIO_PIN_12)
};

void TIM2_IRQHandler() {
	sys_timer_irq_handler();
}

const CFG_REG_SPI_TypeDef spi_tic12400_cfg = SPI_CFG(
		SPI_CPHA_SECOND,
		SPI_CPOL_IDLE_LOW,
		SPI_MSTR_MASTER,
		SPI_BR_FPCLK_64,
		SPI_LSBFIRST_MSB_FIRST,
		SPI_SSI_NSEL,
		SPI_SSM_ENA,
		SPI_RXONLY_DIS,
		SPI_DFF_8,
		SPI_CRCEN_DIS,
		SPI_BIDIOE_RX,
		SPI_BIDIMODE_UNIDIR,
		SPI_RXDMAEN_DIS,
		SPI_TXDMAEN_DIS,
		SPI_SSOE_DIS,
		SPI_FRF_MOTOROLA,
		SPI_ERRIE_DIS,
		GPO_CS_DI_App,
		1,
		1,
		1);

/*
const CFG_REG_SPI_TypeDef spi_spi5_cfg = SPI_CFG(
		SPI_CPHA_SECOND,
		SPI_CPOL_IDLE_LOW,
		SPI_MSTR_MASTER,
		SPI_BR_FPCLK_64,
		SPI_LSBFIRST_MSB_FIRST,
		SPI_SSI_NSEL,
		SPI_SSM_ENA,
		SPI_RXONLY_DIS,
		SPI_DFF_8,
		SPI_CRCEN_DIS,
		SPI_BIDIOE_RX,
		SPI_BIDIMODE_UNIDIR,
		SPI_RXDMAEN_DIS,
		SPI_TXDMAEN_DIS,
		SPI_SSOE_DIS,
		SPI_FRF_MOTOROLA,
		SPI_ERRIE_DIS,
		GPO_CS_SPI5_App,
		1,
		1,
		1);
*/

SPI_BUS_TypeDef SPI_DIO_Bus;

SPI_BUS_DATA_TypeDef tic124_settings_spi_bus_data_control_array[25];

void tic124_settings_spi_bus_data_control_array_fill(void) {
	for(int i = 0; i < 25; i++) {
		tic124_settings_spi_bus_data_control_array[i].tx = (uint8_t*)&tic124_settings_tx_frame[i].all;
		tic124_settings_spi_bus_data_control_array[i].rx = (uint8_t*)&tic124_settings_rx_frame[i].all;
		tic124_settings_spi_bus_data_control_array[i].count = 4;
	}
}

void tic124_start_normal_operation() {
	while(SPI_DIO_Bus.done == false);

	TIC12400_CONFIG_REG config;
	config.all = tic124_settings_tx_frame[0].bit.data;
	config.bit.poll_en = 0x1; /*Polling enabled*/
	config.bit.trigger = 0x1; /*Start TIC12400-Q1 to normal operation*/
	tic124_settings_tx_frame[0].bit.data = config.all;

	spi_bus_transfer(&SPI_DIO_Bus, tic124_settings_spi_bus_data_control_array, 1, SPI_BYTE_ORDER_REVERSE);
}

void tic124_stop_normal_operation() {

}

void SPI4_IRQHandler() {
	SPI_BUS_IRQHandler(&SPI_DIO_Bus);
}

void led_blink() {
	while(1) {
		sys_timer_delay(1, 0);
		gpio_output_bit_setup(bgr_led, GPIO_STATE_OFF);
		sys_timer_delay(1, 0);
		gpio_output_bit_setup(bgr_led, GPIO_STATE_ON);
	}
}

int main(void) {
	rcc_init();
	nvic_init();
	system_timer_init();
	gpio_init();
	//включение буферов 3 сокета
	gpio_output_bit_setup(&GPO_OE_App, GPIO_STATE_OFF);

	spi_bus_init(&SPI_DIO_Bus, SPI4);
	spi_bus_configure(&SPI_DIO_Bus, &spi_tic12400_cfg);

	sys_timer_delay(1, 0);

	tic124_settings_tx_frame_fill();

	tic124_settings_spi_bus_data_control_array_fill();

	spi_bus_transfer(&SPI_DIO_Bus, tic124_settings_spi_bus_data_control_array, 25, SPI_BYTE_ORDER_REVERSE);

	spi_bus_transfer(&SPI_DIO_Bus, tic124_settings_spi_bus_data_control_array, 25, SPI_BYTE_ORDER_REVERSE);

	tic124_start_normal_operation();

	while(SPI_DIO_Bus.done == false);
	SPI_DIO_Bus.spi->CR1.bit.SPE = 0;

	led_blink();
	while(1);
	return 0;
}
