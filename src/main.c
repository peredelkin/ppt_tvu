#include "init.h"
#include "gpio.h"
#include "spi.h"
#include "parity.h"
#include "tic12400.h"

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
		SPI_RXNEIE_DIS,
		SPI_TXEIE_DIS,
		GPO_CS_DI_App);

SPI_BUS_TypeDef SPI_DIO_Bus;
uint8_t spi_dio_bus_rx_buffer[4];
uint8_t spi_dio_bus_tx_buffer[4];

void SPI4_IRQHandler() {
	SPI_IRQHandler(&SPI_DIO_Bus);
}

void spi_bus_init(
		SPI_BUS_TypeDef *bus,
		SPI_TypeDef *spi,
		const CFG_REG_SPI_TypeDef *cfg,
		uint8_t *rx_buffer,
		uint8_t *tx_buffer,
		SPI_BUS_Callback_TypeDef callback) {
	bus->spi = (BITS_SPI_TypeDef*)spi;

	bus->spi->CR1.bit.SPE = SPI_SPE_DIS;

	bus->spi->CR1.all = cfg->CR1.all;
	bus->spi->CR2.all = cfg->CR2.all;

	bus->nss = cfg->NSS;

	bus->rx.data = rx_buffer;
	bus->rx.counter = 0;
	bus->rx.done = true;

	bus->tx.data = tx_buffer;
	bus->tx.counter = 0;
	bus->tx.done = true;

	bus->count = 0;

	bus->callback = callback;

	bus->done = true;
}

void tic12400_wc_cfg0_write(SPI_BUS_TypeDef *spi_bus) {
	while(spi_bus->done == false);
	TIC12400_WC_CFG0_REG WC_CFG0;
	WC_CFG0.all = 0;
	WC_CFG0.bit.wc_in8_in9 = 1;

	TIC12400_TX_FRAME tx_data;
	tx_data.bit.rw = 1;
	tx_data.bit.addr = TIC12400_WC_CFG0;
	tx_data.bit.data = WC_CFG0.all;
	tx_data.bit.par = calc_parity(tx_data.all, 32, PARITY_ODD);

	spi_bus->tx.data[0] = tx_data.byte[3];
	spi_bus->tx.data[1] = tx_data.byte[2];
	spi_bus->tx.data[2] = tx_data.byte[1];
	spi_bus->tx.data[3] = tx_data.byte[0];

	spi_bus->spi->CR1.bit.SPE = 1;
	sys_timer_delay(0, 2);
	gpio_output_bit_setup(spi_bus->nss, GPIO_STATE_OFF);
	sys_timer_delay(0, 1);

	spi_bus->rx.counter = 0;
	spi_bus->rx.done = false;

	spi_bus->tx.counter = 0;
	spi_bus->tx.done = false;

	spi_bus->count = 4;
	spi_bus->done = false;

	spi_bus->spi->CR2.bit.RXNEIE = 1;
	spi_bus->spi->CR2.bit.TXEIE = 1;
}

void tic12400_callback(void *SPI_BUS) {
	SPI_BUS_TypeDef *spi_bus = SPI_BUS;

	TIC12400_WC_CFG0_REG WC_CFG0;
	TIC12400_RX_FRAME rx_data;

	rx_data.byte[0] = spi_bus->rx.data[3];
	rx_data.byte[1] = spi_bus->rx.data[2];
	rx_data.byte[2] = spi_bus->rx.data[1];
	rx_data.byte[3] = spi_bus->rx.data[0];

	WC_CFG0.all = rx_data.bit.data;

	sys_timer_delay(0, 1);
	gpio_output_bit_setup(spi_bus->nss, GPIO_STATE_ON);
	sys_timer_delay(0, 2);

	spi_bus->spi->CR1.bit.SPE = 0;
	spi_bus->done = true;
}

void led_link() {
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

	sys_timer_delay(0, 10000);
	gpio_output_bit_setup(&GPO_Reset_DI_App, GPIO_STATE_ON);
	sys_timer_delay(0, 10000);
	gpio_output_bit_setup(&GPO_Reset_DI_App, GPIO_STATE_OFF);
	sys_timer_delay(0, 10000);

	spi_bus_init(&SPI_DIO_Bus, SPI4, &spi_tic12400_cfg, spi_dio_bus_rx_buffer, spi_dio_bus_tx_buffer, &tic12400_callback);

	//tic12400_wc_cfg0_write(&SPI_DIO_Bus);

	while(1){
		tic12400_wc_cfg0_write(&SPI_DIO_Bus);
	}

	led_link();
	while(1);
	return 0;
}
