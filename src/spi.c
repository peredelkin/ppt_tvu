/*
 * spi_dma.c
 *
 *  Created on: 6 мая 2022 г.
 *      Author: Ruslan
 */

#include "spi.h"

//Обработчик прерывания SPI
void SPI_IRQHandler(SPI_BUS_TypeDef *bus) {
	if (bus->trx.spi->CR2.bit.RXNEIE) {
		if (bus->trx.spi->SR.bit.RXNE) {
			if(bus->trx.rx.data == NULL) {
				bus->trx.rx.stub = (uint8_t) (bus->trx.spi->DR.all);
			} else {
				bus->trx.rx.data[bus->trx.rx.counter] = (uint8_t) (bus->trx.spi->DR.all);
			}
			bus->trx.rx.counter++;
			if(bus->trx.rx.counter >= bus->trx.count) {
				bus->trx.spi->CR2.bit.RXNEIE = 0;
				bus->trx.rx.done = true;
			}
		}
	}

	if (bus->trx.spi->CR2.bit.TXEIE) {
		if (bus->trx.spi->SR.bit.TXE) {
			if(bus->trx.tx.data == NULL) {
				(bus->trx.spi->DR.all) = (uint16_t) (bus->trx.tx.stub);
			} else {
				(bus->trx.spi->DR.all) = (uint16_t) (bus->trx.tx.data[bus->trx.tx.counter]);
			}
			bus->trx.tx.counter++;
			if(bus->trx.tx.counter >= bus->trx.count) {
				bus->trx.spi->CR2.bit.TXEIE = 0;
				bus->trx.tx.done = true;
			}
		}
	}

	if((bus->trx.rx.done) && (bus->trx.tx.done)) {
		//следующее сообщение
	}
}

//инициализация SPI
void spi_bus_init(SPI_BUS_TypeDef *bus, SPI_TypeDef *spi) {
	bus->trx.spi = (BITS_SPI_TypeDef*)spi;

	bus->trx.tx.data = NULL;
	bus->trx.tx.counter = 0;
	bus->trx.tx.done = true;

	bus->trx.rx.data = NULL;
	bus->trx.rx.counter = 0;
	bus->trx.rx.done = true;

	bus->trx.count = 0;

	bus->trx.nss.pin = NULL;
	bus->trx.nss.leading_delay_usec = 0;
	bus->trx.nss.trailing_delay_usec = 0;
	bus->trx.nss.inter_word_delay_usec = 0;
}

//Настройка SPI

//прием/передача
void spi_trx_transfer(SPI_BUS_TypeDef *bus, void *tx, void *rx, size_t size) {

}

//освобождение шины
void spi_trx_free(SPI_BUS_TypeDef *bus) {

}




