/*
 * spi_dma.c
 *
 *  Created on: 6 мая 2022 г.
 *      Author: Ruslan
 */

#include "spi.h"

//инициализация SPI
void spi_bus_init(SPI_BUS_TypeDef *bus, SPI_TypeDef *spi) {
	bus->spi = (BITS_SPI_TypeDef*) spi;

	bus->nss.pin = NULL;
	bus->nss.leading_delay_usec = 0;
	bus->nss.trailing_delay_usec = 0;
	bus->nss.next_frame_delay_usec = 0;

	bus->done = true;

	bus->message.data.pointer = NULL;

	bus->message.data.service.tx.stub = 0;
	bus->message.data.service.tx.counter = 0;
	bus->message.data.service.tx.done = true;

	bus->message.data.service.rx.stub = 0;
	bus->message.data.service.rx.counter = 0;
	bus->message.data.service.rx.done = true;

	bus->message.service.counter = 0;
	bus->message.service.count = 0;
}

//Настройка SPI
void spi_bus_configure(SPI_BUS_TypeDef *bus, CFG_REG_SPI_TypeDef *cfg) {
	while(bus->done == false);
	//выключение SPI перед настройкой
	bus->spi->CR1.bit.SPE = 0;

	//настройка SPI
	bus->spi->CR1.all = cfg->CR1.all;
	bus->spi->CR2.all = cfg->CR2.all;

	//настройка NSS и таймингов
	bus->nss.pin = cfg->NSS;
	bus->nss.leading_delay_usec = cfg->LD_USEC;
	bus->nss.trailing_delay_usec = cfg->TD_USEC;
	bus->nss.next_frame_delay_usec = cfg->NFD_USEC;

	//включение SPI после настройки
	bus->spi->CR1.bit.SPE = 1;
}

//NSS off
void spi_bus_nss_off(SPI_BUS_TypeDef *bus) {
	//опустить NSS
	gpio_output_bit_setup(bus->nss.pin, GPIO_STATE_OFF);
	//подождать после опускания NSS
	sys_timer_delay(0, bus->nss.leading_delay_usec);
}

//NSS on
void spi_bus_nss_on(SPI_BUS_TypeDef *bus) {
	//подождать перед поднятием NSS
	sys_timer_delay(0, bus->nss.trailing_delay_usec);
	//поднять NSS
	gpio_output_bit_setup(bus->nss.pin, GPIO_STATE_ON);
	//подождать после поднятия NSS
	sys_timer_delay(0, bus->nss.next_frame_delay_usec);
}

//разрешение прерываний
void spi_bus_interrupt_enable(SPI_BUS_TypeDef *bus) {
	//настройки SPI, содержащие биты разрешения прерываний
	SPI_CR2_REG CR2;
	//прочесть настройки
	CR2.all = bus->spi->CR2.all;
	//разрешить прерывание "буфер приема не пуст"
	CR2.bit.RXNEIE = 1;
	//разрешить прерывание "буфер передачи пуст"
	CR2.bit.TXEIE = 1;
	//записать настройки
	bus->spi->CR2.all = CR2.all;
}

//старт приема/передачи фрейма
void spi_bus_transfer_start(SPI_BUS_TypeDef *bus) {
	spi_bus_nss_off(bus);
	spi_bus_interrupt_enable(bus);
}

//стоп приема/передачи фрейма
void spi_bus_transfer_stop(SPI_BUS_TypeDef *bus) {
	spi_bus_nss_on(bus);
}

//Обработчик прерывания SPI
void SPI_BUS_IRQHandler(SPI_BUS_TypeDef *bus) {
	if (bus->spi->SR.bit.RXNE) {
		if (bus->spi->CR2.bit.RXNEIE) {
			if(bus->message.data.pointer[bus->message.service.counter].rx == NULL) {
				bus->message.data.service.rx.stub = (uint8_t) (bus->spi->DR.all);
			} else {
				bus->message.data.pointer[bus->message.service.counter].rx[bus->message.data.service.rx.counter] = (uint8_t) (bus->spi->DR.all);
			}
			bus->message.data.service.rx.counter++;
			if(bus->message.data.service.rx.counter >= bus->message.data.pointer[bus->message.service.counter].count) {
				bus->spi->CR2.bit.RXNEIE = 0;
				bus->message.data.service.rx.done = true;
			}
		}
	}

	if (bus->spi->SR.bit.TXE) {
		if (bus->spi->CR2.bit.TXEIE) {
			if(bus->message.data.pointer[bus->message.service.counter].tx == NULL) {
				(bus->spi->DR.all) = (uint16_t) (bus->message.data.service.tx.stub);
			} else {
				(bus->spi->DR.all) = (uint16_t) (bus->message.data.pointer[bus->message.service.counter].tx[bus->message.data.service.tx.counter]);
			}
			bus->message.data.service.tx.counter++;
			if(bus->message.data.service.tx.counter >= bus->message.data.pointer[bus->message.service.counter].count) {
				bus->spi->CR2.bit.TXEIE = 0;
				bus->message.data.service.tx.done = true;
			}
		}
	}

	if((bus->message.data.service.rx.done) && (bus->message.data.service.tx.done)) {
		spi_bus_transfer_stop(bus);
		bus->message.service.counter++;
		if(bus->message.service.counter >= bus->message.service.count) {
			bus->done = true;
			//TODO: колбек или еще что-то по окончании приема/передачи сообщений
		} else {
			spi_bus_transfer_start(bus);
		}
	}
}

