/*
 * tic12400.c
 *
 *  Created on: 5 апр. 2022 г.
 *      Author: Ruslan
 */

#include "tic12400.h"

void tic12400_tx_data_transposition(tic12400_trx_t* trx) {
	uint8_t* tx_data = (uint8_t*)&(trx->tx_frame);
	trx->tx_data[0] = tx_data[3];
	trx->tx_data[1] = tx_data[2];
	trx->tx_data[2] = tx_data[1];
	trx->tx_data[3] = tx_data[0];
}

void tic12400_rx_data_transposition(tic12400_trx_t* trx) {
	uint8_t* rx_data = (uint8_t*)&(trx->rx_frame);
	rx_data[3] = trx->rx_data[0];
	rx_data[2] = trx->rx_data[1];
	rx_data[1] = trx->rx_data[2];
	rx_data[0] = trx->rx_data[3];
}

/*
void tic12400_rx_data_transposition(tic12400_trx_t* trx) {

}

void tic12400_trx_data(tic12400_trx_t* trx) {

}
*/

//обработчик обхода регистров
void tic12400_handler() {
	uint8_t tic_reg_addr = 0;
	switch(tic_reg_addr) {
		default:
			break;
		case TIC12400_DEVICE_ID:
			break;
		case TIC12400_INT_STAT:
			break;
		case TIC12400_CRC:
			break;
		case TIC12400_IN_STAT_MISC:
			break;
		case TIC12400_IN_STAT_COMP:
			break;
		case TIC12400_IN_STAT_ADC0:
			break;
		case TIC12400_IN_STAT_ADC1:
			break;
		case TIC12400_IN_STAT_MATRIX0:
			break;
		case TIC12400_IN_STAT_MATRIX1:
			break;
		case TIC12400_ANA_STAT0:
			break;
		case TIC12400_ANA_STAT1:
			break;
		case TIC12400_ANA_STAT2:
			break;
		case TIC12400_ANA_STAT3:
			break;
		case TIC12400_ANA_STAT4:
			break;
		case TIC12400_ANA_STAT5:
			break;
		case TIC12400_ANA_STAT6:
			break;
		case TIC12400_ANA_STAT7:
			break;
		case TIC12400_ANA_STAT8:
			break;
		case TIC12400_ANA_STAT9:
			break;
		case TIC12400_ANA_STAT10:
			break;
		case TIC12400_ANA_STAT11:
			break;
		case TIC12400_ANA_STAT12:
			break;
		case TIC12400_CONFIG:
			break;
		case TIC12400_IN_EN:
			break;
		case TIC12400_CS_SELECT:
			break;
		case TIC12400_WC_CFG0:
			break;
		case TIC12400_WC_CFG1:
			break;
		case TIC12400_CCP_CFG0:
			break;
		case TIC12400_CCP_CFG1:
			break;
		case TIC12400_THRES_COMP:
			break;
		case TIC12400_INT_EN_COMP1:
			break;
		case TIC12400_INT_EN_COMP2:
			break;
		case TIC12400_INT_EN_CFG0:
			break;
		case TIC12400_INT_EN_CFG1:
			break;
		case TIC12400_INT_EN_CFG2:
			break;
		case TIC12400_INT_EN_CFG3:
			break;
		case TIC12400_INT_EN_CFG4:
			break;
		case TIC12400_THRES_CFG0:
			break;
		case TIC12400_THRES_CFG1:
			break;
		case TIC12400_THRES_CFG2:
			break;
		case TIC12400_THRES_CFG3:
			break;
		case TIC12400_THRES_CFG4:
			break;
		case TIC12400_THRESMAP_CFG0:
			break;
		case TIC12400_THRESMAP_CFG1:
			break;
		case TIC12400_THRESMAP_CFG2:
			break;
		case TIC12400_MATRIX:
			break;
		case TIC12400_MODE:
			break;
	}
}




