/*
 * spi_dma.c
 *
 *  Created on: 6 мая 2022 г.
 *      Author: Ruslan
 */

#include "spi.h"

//инициализация SPI
void spi_bus_init(SPI_BUS_TypeDef *bus, SPI_TypeDef *spi) {
	bus->trx.spi = (BITS_SPI_TypeDef*) spi;

	bus->trx.tx.stub = 0;
	bus->trx.tx.data = NULL;
	bus->trx.tx.counter = 0;
	bus->trx.tx.done = true;

	bus->trx.rx.stub = 0;
	bus->trx.rx.data = NULL;
	bus->trx.rx.counter = 0;
	bus->trx.rx.done = true;

	bus->trx.count = 0;

	bus->trx.nss.pin = NULL;
	bus->trx.nss.leading_delay_usec = 0;
	bus->trx.nss.trailing_delay_usec = 0;
	bus->trx.nss.next_frame_delay_usec = 0;

	bus->message = NULL;
	bus->message_counter = 0;
	bus->message_count = 0;

	bus->done = true;
}

//Настройка SPI
void spi_bus_configure(SPI_BUS_TypeDef *bus, CFG_REG_SPI_TypeDef *cfg) {
	while(bus->done == false);
	//выключение SPI перед настройкой
	bus->trx.spi->CR1.bit.SPE = 0;

	//настройка SPI
	bus->trx.spi->CR1.all = cfg->CR1.all;
	bus->trx.spi->CR2.all = cfg->CR2.all;

	//настройка NSS и таймингов
	bus->trx.nss.pin = cfg->NSS;
	bus->trx.nss.leading_delay_usec = cfg->LD_USEC;
	bus->trx.nss.trailing_delay_usec = cfg->TD_USEC;
	bus->trx.nss.next_frame_delay_usec = cfg->NFD_USEC;

	//включение SPI после настройки
	bus->trx.spi->CR1.bit.SPE = 1;
}

//NSS off
void spi_bus_nss_off(SPI_BUS_TypeDef *bus) {
	//опустить NSS
	gpio_output_bit_setup(bus->trx.nss.pin, GPIO_STATE_OFF);
	//подождать после опускания NSS
	sys_timer_delay(0, bus->trx.nss.leading_delay_usec);
}

//NSS on
void spi_bus_nss_on(SPI_BUS_TypeDef *bus) {
	//подождать перед поднятием NSS
	sys_timer_delay(0, bus->trx.nss.trailing_delay_usec);
	//поднять NSS
	gpio_output_bit_setup(bus->trx.nss.pin, GPIO_STATE_ON);
	//подождать после поднятия NSS
	sys_timer_delay(0, bus->trx.nss.next_frame_delay_usec);
}

//старт передачи
void spi_bus_transfer_start(SPI_BUS_TypeDef *bus) {
	//опустить NSS
	spi_bus_nss_off(bus);
	//настройки SPI, содержащие биты разрешения прерываний
	SPI_CR2_REG CR2;
	//прочесть настройки
	CR2.all = bus->trx.spi->CR2.all;
	//разрешить прерывание "буфер приема не пуст"
	CR2.bit.RXNEIE = 1;
	//разрешить прерывание "буфер передачи пуст"
	CR2.bit.TXEIE = 1;
	//записать настройки
	bus->trx.spi->CR2.all = CR2.all;
}

//прием/передача
void spi_bus_transfer(SPI_BUS_TypeDef *bus, void *tx, void *rx, size_t count) {
	//настройка передачи
	bus->trx.tx.data = tx;
	bus->trx.tx.counter = 0;
	bus->trx.tx.done = false;
	//настройка приема
	bus->trx.rx.data = rx;
	bus->trx.rx.counter = 0;
	bus->trx.rx.done = false;
	//количество байт приема/передачи
	bus->trx.count = count;
	//запустить прием/передачу
	spi_bus_transfer_start(bus);
}

//начать прием/передачу сообщений
void spi_start_message_transfer(SPI_BUS_TypeDef *bus) {
	while(bus->done == false);
	bus->done = false;
	spi_bus_transfer(bus,
			bus->message[0].tx_data,
			bus->message[0].rx_data,
			bus->message[0].data_count);
}

//прием/передача сообщения
void spi_bus_message_transfer(SPI_BUS_TypeDef *bus) {
	spi_bus_transfer(bus,
			bus->message[bus->message_counter].tx_data,
			bus->message[bus->message_counter].rx_data,
			bus->message[bus->message_counter].data_count);
}

//Обработчик прерывания SPI
void SPI_BUS_IRQHandler(SPI_BUS_TypeDef *bus) {
	if (bus->trx.spi->SR.bit.RXNE) {
		if (bus->trx.spi->CR2.bit.RXNEIE) {
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

	if (bus->trx.spi->SR.bit.TXE) {
		if (bus->trx.spi->CR2.bit.TXEIE) {
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
	//прием/передача закончены
	if((bus->trx.rx.done) && (bus->trx.tx.done)) {
		//поднять NSS
		spi_bus_nss_on(bus);
		//инкремент индекса сообщений
		bus->message_counter++;
		//если все сообщения переданы
		if(bus->message_counter >= bus->message_count) {
			bus->done = true;
			//TODO: колбек или еще что-то по окончании приема/передачи сообщений
		} else {
			//передача следующего сообщения
			spi_bus_message_transfer(bus);
		}
	}
}

