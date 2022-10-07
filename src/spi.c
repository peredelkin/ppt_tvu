/*
 * spi_dma.c
 *
 *  Created on: 6 мая 2022 г.
 *      Author: Ruslan
 */

#include "spi.h"

void SPI_IRQHandler(SPI_BUS_TypeDef *bus) {
	if(bus->spi->SR.bit.RXNE) {
		if(bus->rx.counter == bus->last) {
			bus->rx.data[bus->rx.counter] = bus->spi->DR.all;
			bus->spi->CR2.bit.RXNEIE = SPI_RXNEIE_DIS;
			bus->rx.busy = false;
		} else {
			bus->rx.data[bus->rx.counter++] = bus->spi->DR.all;
		}
	}

	if(bus->spi->SR.bit.TXE) {
		if(bus->tx.counter == bus->last) {
			bus->spi->DR.all = bus->tx.data[bus->tx.counter];
			bus->spi->CR2.bit.TXEIE = SPI_TXEIE_DIS;
			bus->tx.busy = false;
		} else {
			bus->spi->DR.all = bus->tx.data[bus->tx.counter++];
		}
	}
}
