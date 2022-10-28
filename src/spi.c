/*
 * spi_dma.c
 *
 *  Created on: 6 мая 2022 г.
 *      Author: Ruslan
 */

#include "spi.h"

void SPI_IRQHandler(SPI_BUS_TypeDef *bus) {
	if (bus->spi->CR2.bit.RXNEIE) {
		if (bus->spi->SR.bit.RXNE) {
			bus->rx.data[bus->rx.counter] = (uint8_t) (bus->spi->DR.all);
			bus->rx.counter++;
			if(bus->rx.counter >= bus->count) {
				bus->spi->CR2.bit.RXNEIE = 0;
				bus->rx.done = true;
			}
		}
	}

	if (bus->spi->CR2.bit.TXEIE) {
		if (bus->spi->SR.bit.TXE) {
			(bus->spi->DR.all) = (uint16_t) (bus->tx.data[bus->tx.counter]);
			bus->tx.counter++;
			if(bus->tx.counter >= bus->count) {
				bus->spi->CR2.bit.TXEIE = 0;
				bus->tx.done = true;
			}
		}
	}

	if((bus->rx.done) && (bus->tx.done)) {
		if(bus->callback != NULL) {
			bus->callback(bus);
		}
	}
}
