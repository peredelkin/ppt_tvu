/*
 * tic12400.c
 *
 *  Created on: 5 апр. 2022 г.
 *      Author: Ruslan
 */

#include "tic12400.h"
//TODO: расставить функции в порядке вызова для функций инициализации масссивов и расставить в порядке регистров tic12400

void tic124_spi_bus_configure(tic12400_t* tic) {
	spi_bus_configure(tic->spi_bus, tic->spi_cfg);
}

#define TIC124_TX_FRAME_FILL(FRAME,ADDR)\
		FRAME[TIC12400_##ADDR].bit.rw = 0;\
		FRAME[TIC12400_##ADDR].bit.addr = TIC12400_##ADDR;\
		FRAME[TIC12400_##ADDR].bit.data = 0;\
		FRAME[TIC12400_##ADDR].bit.par = calc_parity(FRAME[TIC12400_##ADDR].all, 32, PARITY_ODD)

#define TIC124_SETTINGS_TX_FRAME_FILL(FRAME,CFG,ADDR)\
		FRAME[TIC12400_##ADDR].bit.rw = 1;\
		FRAME[TIC12400_##ADDR].bit.addr = TIC12400_##ADDR;\
		FRAME[TIC12400_##ADDR].bit.data = CFG->ADDR.all;\
		FRAME[TIC12400_##ADDR].bit.par = calc_parity(FRAME[TIC12400_##ADDR].all, 32, PARITY_ODD)

void tic124_tx_frame_fill(tic12400_t* tic) {
	TIC124_TX_FRAME_FILL(tic->tx_frame,RESERVED0);

	TIC124_TX_FRAME_FILL(tic->tx_frame,DEVICE_ID);
	TIC124_TX_FRAME_FILL(tic->tx_frame,INT_STAT);
	TIC124_TX_FRAME_FILL(tic->tx_frame,CRC);
	TIC124_TX_FRAME_FILL(tic->tx_frame,IN_STAT_MISC);
	TIC124_TX_FRAME_FILL(tic->tx_frame,IN_STAT_COMP);
	TIC124_TX_FRAME_FILL(tic->tx_frame,IN_STAT_ADC0);
	TIC124_TX_FRAME_FILL(tic->tx_frame,IN_STAT_ADC1);
	TIC124_TX_FRAME_FILL(tic->tx_frame,IN_STAT_MATRIX0);
	TIC124_TX_FRAME_FILL(tic->tx_frame,IN_STAT_MATRIX1);
	TIC124_TX_FRAME_FILL(tic->tx_frame,ANA_STAT0);
	TIC124_TX_FRAME_FILL(tic->tx_frame,ANA_STAT1);
	TIC124_TX_FRAME_FILL(tic->tx_frame,ANA_STAT2);
	TIC124_TX_FRAME_FILL(tic->tx_frame,ANA_STAT3);
	TIC124_TX_FRAME_FILL(tic->tx_frame,ANA_STAT4);
	TIC124_TX_FRAME_FILL(tic->tx_frame,ANA_STAT5);
	TIC124_TX_FRAME_FILL(tic->tx_frame,ANA_STAT6);
	TIC124_TX_FRAME_FILL(tic->tx_frame,ANA_STAT7);
	TIC124_TX_FRAME_FILL(tic->tx_frame,ANA_STAT8);
	TIC124_TX_FRAME_FILL(tic->tx_frame,ANA_STAT9);
	TIC124_TX_FRAME_FILL(tic->tx_frame,ANA_STAT10);
	TIC124_TX_FRAME_FILL(tic->tx_frame,ANA_STAT11);
	TIC124_TX_FRAME_FILL(tic->tx_frame,ANA_STAT12);

	TIC124_TX_FRAME_FILL(tic->tx_frame,RESERVED23);
	TIC124_TX_FRAME_FILL(tic->tx_frame,RESERVED24);
	TIC124_TX_FRAME_FILL(tic->tx_frame,RESERVED25);

	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,CONFIG);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,IN_EN);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,CS_SELECT);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,WC_CFG0);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,WC_CFG1);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,CCP_CFG0);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,CCP_CFG1);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,THRES_COMP);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,INT_EN_COMP1);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,INT_EN_COMP2);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,INT_EN_CFG0);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,INT_EN_CFG1);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,INT_EN_CFG2);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,INT_EN_CFG3);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,INT_EN_CFG4);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,THRES_CFG0);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,THRES_CFG1);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,THRES_CFG2);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,THRES_CFG3);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,THRES_CFG4);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,THRESMAP_CFG0);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,THRESMAP_CFG1);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,THRESMAP_CFG2);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,MATRIX);
	TIC124_SETTINGS_TX_FRAME_FILL(tic->tx_frame,tic->tic_settings,MODE);
}

void tic124_spi_control_fill(tic12400_t* tic) {
	for(int i = 0; i < TIC12400_FRAME_COUNT; i++) {
		tic->spi_control[i].tx = (uint8_t*)&tic->tx_frame[i].all;
		tic->spi_control[i].rx = (uint8_t*)&tic->rx_frame[i].all;
		tic->spi_control[i].count = TIC12400_FRAME_SIZE;
	}
}

void tic124_start_normal_operation(tic12400_t* tic) {
	spi_bus_wait_done(tic->spi_bus);

	TIC12400_CONFIG_REG config;
	//чтение настроек
	config.all = tic->tic_settings->CONFIG.all;
	//изменение настроек
	config.bit.poll_en = 0x1; /*Polling enabled*/ //Нужно ли?
	config.bit.trigger = 0x1; /*Start TIC12400-Q1 to normal operation*/

	//формирование фрейма
	tic->tx_frame[TIC12400_CONFIG].bit.rw = 1;
	tic->tx_frame[TIC12400_CONFIG].bit.addr = TIC12400_CONFIG;
	tic->tx_frame[TIC12400_CONFIG].bit.data = config.all;
	//сброс четности
	tic->tx_frame[TIC12400_CONFIG].bit.par = 0;
	//расчет четности
	tic->tx_frame[TIC12400_CONFIG].bit.par = calc_parity(tic->tx_frame[TIC12400_CONFIG].all, 32, PARITY_ODD);
	//старт приема/передачи
	spi_bus_transfer(tic->spi_bus, &tic->spi_control[TIC12400_CONFIG], 1, SPI_BYTE_ORDER_REVERSE, NULL, NULL);
}

void tic12400_int_stat_read(tic12400_t* tic) {
	spi_bus_transfer(tic->spi_bus, &tic->spi_control[TIC12400_INT_STAT], 1, SPI_BYTE_ORDER_REVERSE, NULL, NULL);
}

void tic12400_configure(tic12400_t* tic) {
	spi_bus_transfer(tic->spi_bus, &tic->spi_control[TIC12400_CONFIG], 25, SPI_BYTE_ORDER_REVERSE, NULL, NULL);
}

void tic12400_in_stat_comp_handler(void* tic) {
	((tic12400_t*)tic)->in_stat_comp->all = ((tic12400_t*)tic)->rx_frame[TIC12400_IN_STAT_COMP].bit.data;
}

void tic12400_in_stat_comp_read(tic12400_t* tic) {
	spi_bus_transfer(tic->spi_bus, &tic->spi_control[TIC12400_IN_STAT_COMP], 1, SPI_BYTE_ORDER_REVERSE,
			&tic12400_in_stat_comp_handler, tic);
}

void tic12400_ana_stat_handler(void* tic) {
	for(int n=0; n < 13; n++) {
		((tic12400_t*)tic)->ana_stat[n].all = ((tic12400_t*)tic)->rx_frame[TIC12400_ANA_STAT0 + n].bit.data;
	}
}

void tic12400_ana_stat_read(tic12400_t* tic) {
	spi_bus_transfer(tic->spi_bus, &tic->spi_control[TIC12400_ANA_STAT0], 13, SPI_BYTE_ORDER_REVERSE,
			&tic12400_ana_stat_handler, tic);
}
