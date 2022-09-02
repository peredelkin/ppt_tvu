#include "init.h"
#include "spi.h"

void spi4_init() {
	BITS_SPI_TypeDef *spi_bits = (BITS_SPI_TypeDef*) SPI5;
	spi_bits->CR1.bit.CPHA = SPI_CPHA_SECOND;
	spi_bits->CR1.bit.CPOL = SPI_CPOL_IDLE_LOW;
	spi_bits->CR1.bit.MSTR = SPI_MSTR_MASTER;
	spi_bits->CR1.bit.BR = SPI_BR_FPCLK_128;
	spi_bits->CR1.bit.LSBFIRST = SPI_LSBFIRST_MSB_FIRST;
	spi_bits->CR1.bit.SSI = SPI_SSI_NSEL;
	spi_bits->CR1.bit.SSM = SPI_SSM_ENA;
	spi_bits->CR1.bit.RXONLY = SPI_RXONLY_DIS;
	spi_bits->CR1.bit.DFF = SPI_DFF_8;
	spi_bits->CR1.bit.CRCNEXT = SPI_CRCNEXT_DATA_PHASE;
	spi_bits->CR1.bit.BIDIOE = SPI_BIDIOE_RX;
	spi_bits->CR1.bit.BIDIMODE = SPI_BIDIMODE_UNIDIR;

	spi_bits->CR2.bit.RXDMAEN = SPI_RXDMAEN_DIS;
	spi_bits->CR2.bit.TXDMAEN = SPI_TXDMAEN_DIS;
	spi_bits->CR2.bit.SSOE = SPI_SSOE_DIS;
	spi_bits->CR2.bit.FRF = SPI_FRF_MOTOROLA;
	spi_bits->CR2.bit.ERRIE = SPI_ERRIE_DIS;
	spi_bits->CR2.bit.RXNEIE = SPI_RXNEIE_DIS;
	spi_bits->CR2.bit.TXEIE = SPI_TXEIE_DIS;

	spi_bits->I2SCFGR.all = 0;
	spi_bits->I2SPR.all = 0;
}

int main(void) {
	rcc_init();
	gpio_init();
	spi4_init();
	SPI5->CR1 |= SPI_CR1_SPE;
	while(1) {
		if(SPI5->SR & SPI_SR_TXE) {
			SPI5->DR = 0x0F;
		}
	}
	return 0;
}
