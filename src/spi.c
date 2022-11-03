/*
 * spi_dma.c
 *
 *  Created on: 6 мая 2022 г.
 *      Author: Ruslan
 */

#include "spi.h"

//Обработчик прерывания SPI
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

void spi_bus_transfer(SPI_BUS_TypeDef *bus, void *tx, void *rx, size_t size) {
	//подождать освобождения шины
	while(bus->busy);
	//занять шину
	bus->busy = true;

	//настройка передачи
	bus->tx.data = (uint8_t*)tx;
	bus->tx.counter = 0;
	bus->tx.done = false;

	//настройка приема
	bus->rx.data = (uint8_t*)rx;
	bus->rx.counter = 0;
	bus->rx.done = false;

	//количество байт
	bus->count = size;

	//включить SPI
	bus->spi->CR1.bit.SPE = 1;

	//опустить NSS
	gpio_output_bit_setup(bus->nss.pin, GPIO_STATE_OFF);
	//подождать после NSS
	sys_timer_delay(0, bus->nss.leading_delay_usec);

	//разрешить прерывание RXNE
	bus->spi->CR2.bit.RXNEIE = 1;
	//разрешить прерывание TXE
	bus->spi->CR2.bit.TXEIE = 1;
}

