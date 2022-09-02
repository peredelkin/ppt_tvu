#include "init.h"
#include "spi.h"

const CFG_BITS_SPI_TypeDef spi_tic12400_cfg = SPI_CFG(
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
		SPI_TXEIE_DIS);

void spi4_init() {
	BITS_SPI_TypeDef *spi_bits = (BITS_SPI_TypeDef*) SPI5;
	spi_bits->CR1.all = spi_tic12400_cfg.CR1.all;
	spi_bits->CR2.all = spi_tic12400_cfg.CR2.all;
}

int main(void) {
	rcc_init();
	gpio_init();
	spi4_init();
	while(1);
	return 0;
}
