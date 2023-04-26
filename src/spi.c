/*
 * spi_dma.c
 *
 *  Created on: 6 мая 2022 г.
 *      Author: Ruslan
 */

#include "spi.h"

//объявление функций
void spi_bus_transfer_start(SPI_BUS_TypeDef *bus);

//инициализация SPI
void spi_bus_init(SPI_BUS_TypeDef *bus, SPI_TypeDef *spi) {
	bus->spi = (BITS_SPI_TypeDef*) spi;

	bus->nss.pin = NULL;
	bus->nss.leading_delay_usec = 0;
	bus->nss.trailing_delay_usec = 0;
	bus->nss.next_frame_delay_usec = 0;

	bus->callback = NULL;
	bus->callback_argument = NULL;

	bus->done = true;

	bus->frame.data = NULL;

	bus->frame.data_service.tx.stub = 0;
	bus->frame.data_service.tx.counter = 0;
	bus->frame.data_service.tx.done = true;

	bus->frame.data_service.rx.stub = 0;
	bus->frame.data_service.rx.counter = 0;
	bus->frame.data_service.rx.done = true;

	bus->frame_service.counter = 0;
	bus->frame_service.count = 0;
}

//Ожидает освобождения шины
void spi_bus_wait(SPI_BUS_TypeDef *bus) {
	while(bus->done == false);
}

//Ожидает освобождения шины и сразу занимает
void spi_bus_wait_and_take(SPI_BUS_TypeDef *bus) {
	spi_bus_wait(bus);
	bus->done = false;
}

//Освобождение шины
void spi_bus_free(SPI_BUS_TypeDef* bus) {
	bus->callback = NULL;
	bus->callback_argument = NULL;
	bus->done = true;
}

//Настройка SPI
void spi_bus_configure(SPI_BUS_TypeDef *bus, const CFG_REG_SPI_TypeDef *cfg) {
	//ожидание особождении шины
	spi_bus_wait_and_take(bus);

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

	//освобождение шины
	spi_bus_free(bus);
}

//Настройка и запуск приема/передачи
void spi_bus_transfer(
		SPI_BUS_TypeDef* bus,
		SPI_BUS_DATA_TypeDef* frame_control_array_pointer,
		size_t frame_control_array_amount,
		spi_byte_order_t frame_byte_order,
		spi_bus_callback callback,
		void* callback_argument) {

	bus->frame.data = frame_control_array_pointer;
	bus->frame_service.count = frame_control_array_amount;
	bus->frame_service.counter = 0;
	bus->frame.data_service.byte_order = frame_byte_order;

	bus->callback = callback;
	bus->callback_argument = callback_argument;

	spi_bus_transfer_start(bus);
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

//сброс сервисных переменных для приема/передачи
void spi_bus_transfer_start_service(SPI_BUS_SERVICE_TypeDef *service) {
	service->stub = 0;
	service->counter = 0;
	service->done = false;
}

//старт приема/передачи фрейма
void spi_bus_transfer_start(SPI_BUS_TypeDef *bus) {
	spi_bus_transfer_start_service(&(bus->frame.data_service.tx));
	spi_bus_transfer_start_service(&(bus->frame.data_service.rx));
	spi_bus_nss_off(bus);
	spi_bus_interrupt_enable(bus);
}

//стоп приема/передачи фрейма
void spi_bus_transfer_stop(SPI_BUS_TypeDef *bus) {
	spi_bus_nss_on(bus);
}

//чтение в заглушку
void spi_bus_read_to_stub(SPI_BUS_TypeDef *bus) {
	bus->frame.data_service.rx.stub = (uint8_t) (bus->spi->DR.all);
}

//чтение во фрейм
void spi_bus_read_to_frame_data(SPI_BUS_TypeDef *bus, size_t frame_n, size_t data_n) {
	if(bus->frame.data_service.byte_order == SPI_BYTE_ORDER_REVERSE) {
		size_t reverse_data_n = bus->frame.data[frame_n].count - (data_n + 1);
		bus->frame.data[frame_n].rx[reverse_data_n] = bus->spi->DR.all;
	} else {
		bus->frame.data[frame_n].rx[data_n] = bus->spi->DR.all;
	}
}

//чтение завершено
void spi_bus_read_done(SPI_BUS_TypeDef *bus) {
	bus->spi->CR2.bit.RXNEIE = 0;
	bus->frame.data_service.rx.done = true;
}

//запись из заглушки
void spi_bus_write_from_stub(SPI_BUS_TypeDef *bus) {
	(bus->spi->DR.all) = (uint16_t) (bus->frame.data_service.tx.stub);
}

//запись из фрейма
void spi_bus_write_from_frame_data(SPI_BUS_TypeDef *bus, size_t frame_n, size_t data_n) {
	if(bus->frame.data_service.byte_order == SPI_BYTE_ORDER_REVERSE) {
		size_t reverse_data_n = bus->frame.data[frame_n].count - (data_n + 1);
		(bus->spi->DR.all) = bus->frame.data[frame_n].tx[reverse_data_n];
	} else {
		(bus->spi->DR.all) = bus->frame.data[frame_n].tx[data_n];
	}
}

//запись завершена
void spi_bus_write_done(SPI_BUS_TypeDef *bus) {
	bus->spi->CR2.bit.TXEIE = 0;
	bus->frame.data_service.tx.done = true;
}

//Обработчик прерывания SPI
void SPI_BUS_IRQHandler(SPI_BUS_TypeDef *bus) {
	if (bus->spi->SR.bit.RXNE) {
		if (bus->spi->CR2.bit.RXNEIE) {
			if(bus->frame.data[bus->frame_service.counter].rx == NULL) {
				spi_bus_read_to_stub(bus);
			} else {
				spi_bus_read_to_frame_data(bus, bus->frame_service.counter, bus->frame.data_service.rx.counter);
			}
			bus->frame.data_service.rx.counter++;
			if(bus->frame.data_service.rx.counter >= bus->frame.data[bus->frame_service.counter].count) {
				spi_bus_read_done(bus);
			}
		}
	}

	if (bus->spi->SR.bit.TXE) {
		if (bus->spi->CR2.bit.TXEIE) {
			if(bus->frame.data[bus->frame_service.counter].tx == NULL) {
				spi_bus_write_from_stub(bus);
			} else {
				spi_bus_write_from_frame_data(bus, bus->frame_service.counter, bus->frame.data_service.tx.counter);
			}
			bus->frame.data_service.tx.counter++;
			if(bus->frame.data_service.tx.counter >= bus->frame.data[bus->frame_service.counter].count) {
				spi_bus_write_done(bus);
			}
		}
	}

	if((bus->frame.data_service.rx.done) && (bus->frame.data_service.tx.done)) {
		spi_bus_transfer_stop(bus);
		bus->frame_service.counter++;
		if(bus->frame_service.counter >= bus->frame_service.count) {
			if(bus->callback) {
				bus->callback(bus->callback_argument);
			} else {
				spi_bus_free(bus);
			}
		} else {
			spi_bus_transfer_start(bus);
		}
	}
}

