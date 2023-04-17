/*
 * tic12400.c
 *
 *  Created on: 5 апр. 2022 г.
 *      Author: Ruslan
 */

#include "tic12400.h"

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
