/*
 * tic12400.c
 *
 *  Created on: 5 апр. 2022 г.
 *      Author: Ruslan
 */

#include "tic12400.h"

void tic12400_handler(void *tic);

void tic12400_wait(tic12400_t *tic) {
	while(tic->done == false);
}

void tic12400_bus_wait_and_take(tic12400_t *tic) {
	spi_bus_wait_and_take(tic->spi_bus);
	tic->done = false;
}

void tic12400_bus_free(tic12400_t *tic) {
	tic->done = true;
	spi_bus_free(tic->spi_bus);
}

void tic12400_transfer(tic12400_t *tic) {
	spi_bus_transfer(tic->spi_bus, &tic->spi_control, 1, SPI_BYTE_ORDER_REVERSE, &tic12400_handler, tic);
}

void tic124_tx_frame_fill(tic12400_t *tic, uint32_t rw, uint32_t addr, uint32_t data) {
	tic->tx_frame.all = 0;
	tic->tx_frame.bit.rw = rw;
	tic->tx_frame.bit.addr = addr;
	tic->tx_frame.bit.data = data;
	tic->tx_frame.bit.par = calc_parity(tic->tx_frame.all, 32, PARITY_ODD);
}

bool tic12400_rx_frame_parity_check(tic12400_t *tic) {
	int par = tic->rx_frame.bit.par;
	tic->rx_frame.bit.par = 0;
	tic->rx_frame.bit.par = calc_parity(tic->rx_frame.all, 32, PARITY_ODD);
	return ((par) == (tic->rx_frame.bit.par));
}

void tic12400_tx_handler(tic12400_t *tic) {
	if (tic->sequential.data) {
		tic->sequential.index++;
		if (tic->sequential.index < tic->sequential.count) {
			tic124_tx_frame_fill(tic, 1, tic->sequential.addr[tic->sequential.index],
					tic->sequential.data[tic->sequential.index]);
			tic12400_transfer(tic);
		} else {
			tic12400_bus_free(tic);
		}
	} else {
		tic12400_bus_free(tic);
	}
}

void tic12400_rx_handler(tic12400_t *tic) {
	if (tic->sequential.data) {
		tic->sequential.data[tic->sequential.index] = tic->rx_frame.bit.data;
		tic->sequential.index++;
		if (tic->sequential.index < tic->sequential.count) {
			tic124_tx_frame_fill(tic, 0, tic->sequential.addr[tic->sequential.index], 0);
			tic12400_transfer(tic);
		} else {
			tic12400_bus_free(tic);
		}
	} else {
		tic12400_bus_free(tic);
	}
}

void tic12400_tx_rx_handler(tic12400_t *tic) {
	if (tic->tx_frame.bit.rw) {
		tic12400_tx_handler(tic);
	} else {
		tic12400_rx_handler(tic);
	}
}

void tic12400_status_callback_handler(tic12400_t *tic) {
	if (tic->status_callback) {
		tic->status_callback(tic->status_callback_argument);
	} else {
		tic12400_tx_rx_handler(tic);
	}
}

void tic12400_rx_frame_status_handler(tic12400_t *tic) {
	if (tic->status_mask.all & tic->rx_frame.all) {
		tic12400_status_callback_handler(tic);
	} else {
		tic12400_tx_rx_handler(tic);
	}
}

void tic12400_rx_frame_parity_handler(tic12400_t *tic) {
	if (tic12400_rx_frame_parity_check(tic)) {
		tic12400_rx_frame_status_handler(tic);
	} else {
		tic12400_status_callback_handler(tic);
	}
}

void tic12400_handler(void *tic) {
	tic12400_rx_frame_parity_handler(tic);
}

void tic12400_init(tic12400_t *tic, SPI_BUS_TypeDef *spi_bus, const CFG_REG_SPI_TypeDef *spi_cfg) {
	tic->spi_bus = spi_bus;
	tic->spi_cfg = spi_cfg;

	tic->spi_control.tx = (uint8_t*) &tic->tx_frame.all;
	tic->spi_control.rx = (uint8_t*) &tic->rx_frame.all;
	tic->spi_control.count = TIC12400_FRAME_SIZE;

	tic->tx_frame.all = 0;
	tic->rx_frame.all = 0;

	//TODO: вынести отдельно
	tic->status_mask.bit.oi = 0x1; //Other Interrupt
	tic->status_mask.bit.temp = 0x1; //Temperature Event
	tic->status_mask.bit.vs_th = 0x0; //VS Threshold Crossing
	tic->status_mask.bit.ssc = 0x0; //Switch State Change
	tic->status_mask.bit.par_fail = 0x1; //Parity Fail
	tic->status_mask.bit.spi_fail = 0x1; //SPI Error
	tic->status_mask.bit.por = 0x1; //Power-on Reset

	tic->status_callback = NULL;
	tic->status_callback_argument = NULL;

	tic->sequential.count = 0;
	tic->sequential.index = 0;
	tic->sequential.addr = NULL;
	tic->sequential.data = NULL;

	tic->done = true;
}

void tic12400_spi_bus_configure(tic12400_t *tic) {
	spi_bus_configure(tic->spi_bus, tic->spi_cfg);
}

void tic12400_reg_read(tic12400_t *tic, uint32_t *data, const uint8_t *addr, uint8_t count) {
	tic12400_bus_wait_and_take(tic);
	tic->sequential.count = count;
	tic->sequential.index = 0;
	tic->sequential.addr = addr;
	tic->sequential.data = data;
	tic124_tx_frame_fill(tic, 0, addr[tic->sequential.index], 0);
	tic12400_transfer(tic);
}

void tic12400_reg_read_from_callback(tic12400_t *tic, uint32_t *data, const uint8_t *addr, uint8_t count) {
	tic->sequential.count = count;
	tic->sequential.index = 0;
	tic->sequential.addr = addr;
	tic->sequential.data = data;
	tic124_tx_frame_fill(tic, 0, addr[tic->sequential.index], 0);
	tic12400_transfer(tic);
}

void tic12400_reg_write(tic12400_t *tic, uint32_t *data, const uint8_t *addr, uint8_t count) {
	tic12400_bus_wait_and_take(tic);
	tic->sequential.count = count;
	tic->sequential.index = 0;
	tic->sequential.addr = addr;
	tic->sequential.data = data;
	tic124_tx_frame_fill(tic, 1, tic->sequential.addr[tic->sequential.index], tic->sequential.data[tic->sequential.index]);
	tic12400_transfer(tic);
}

void tic12400_reg_write_from_callback(tic12400_t *tic, uint32_t *data, const uint8_t *addr, uint8_t count) {
	tic->sequential.count = count;
	tic->sequential.index = 0;
	tic->sequential.addr = addr;
	tic->sequential.data = data;
	tic124_tx_frame_fill(tic, 1, tic->sequential.addr[tic->sequential.index], tic->sequential.data[tic->sequential.index]);
	tic12400_transfer(tic);
}

