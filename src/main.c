#include "init.h"
#include "gpio.h"
#include "spi.h"
#include "parity.h"
#include "tic12400.h"

const CFG_REG_SPI_TypeDef spi_tic12400_cfg = SPI_CFG(
		SPI_CPHA_SECOND,
		SPI_CPOL_IDLE_LOW,
		SPI_MSTR_MASTER,
		SPI_BR_FPCLK_128,
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

void spi_bus_init(SPI_BUS_TypeDef *bus, SPI_TypeDef *spi, const CFG_REG_SPI_TypeDef *cfg, uint8_t *rx_buffer, uint8_t *tx_buffer) {
	bus->spi = (BITS_SPI_TypeDef*)spi;

	bus->spi->CR1.bit.SPE = SPI_SPE_DIS;

	bus->spi->CR1.all = cfg->CR1.all;
	bus->spi->CR2.all = cfg->CR2.all;

	bus->nss = cfg->NSS;

	bus->rx.data = rx_buffer;
	bus->rx.counter = 0;
	bus->rx.busy = false;

	bus->tx.data = tx_buffer;
	bus->tx.counter = 0;
	bus->tx.busy = false;
}

int main(void) {
	rcc_init();
	gpio_init();
	spi_bus_init(&SPI_DIO_Bus, SPI4, &spi_tic12400_cfg, spi_dio_bus_rx_buffer, spi_dio_bus_tx_buffer);
	while(1);
	return 0;
}
