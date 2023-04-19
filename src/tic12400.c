/*
 * tic12400.c
 *
 *  Created on: 5 апр. 2022 г.
 *      Author: Ruslan
 */

#include "tic12400.h"


void tic12400_init(tic12400_t* tic,
		SPI_BUS_TypeDef* spi_bus,
		const CFG_REG_SPI_TypeDef* spi_cfg,
		const TIC12400_SETTINGS_TypeDef* tic_settings) {
	tic->spi_bus = spi_bus;
	tic->spi_cfg = spi_cfg;
	tic->tic_settings = tic_settings;
	tic->spi_control.tx = (uint8_t*)&tic->tx_frame.all;
	tic->spi_control.rx = (uint8_t*)&tic->rx_frame.all;
	tic->spi_control.count = TIC12400_FRAME_SIZE;
}

void tic124_spi_bus_configure(tic12400_t* tic) {
	spi_bus_configure(tic->spi_bus, tic->spi_cfg);
}

/*
#define TIC124_TX_FRAME_FILL(FRAME,RW,ADDR,DATA)\
		FRAME.all = 0;\
		FRAME.bit.rw = RW;\
		FRAME.bit.addr = ADDR;\
		FRAME.bit.data = DATA;\
		FRAME.bit.par = calc_parity(FRAME.all, 32, PARITY_ODD)
*/

void tic124_tx_frame_fill(tic12400_t* tic, uint32_t rw, uint32_t addr, uint32_t data) {
	tic->tx_frame.all = 0;
	tic->tx_frame.bit.rw = rw;
	tic->tx_frame.bit.addr = addr;
	tic->tx_frame.bit.data = data;
	tic->tx_frame.bit.par = calc_parity(tic->tx_frame.all, 32, PARITY_ODD);
}

void tic12400_handler(void* tic);

void tic12400_fill_mode_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_MODE, tic->tic_settings->MODE.all);
}

void tic12400_fill_matrix_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_MATRIX, tic->tic_settings->MATRIX.all);
}

void tic12400_fill_thresmap_cfg2_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_THRESMAP_CFG2, tic->tic_settings->THRESMAP_CFG2.all);
}

void tic12400_fill_thresmap_cfg1_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_THRESMAP_CFG1, tic->tic_settings->THRESMAP_CFG1.all);
}

void tic12400_fill_thresmap_cfg0_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_THRESMAP_CFG0, tic->tic_settings->THRESMAP_CFG0.all);
}

void tic12400_fill_thres_cfg4_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_THRES_CFG4, tic->tic_settings->THRES_CFG4.all);
}

void tic12400_fill_thres_cfg3_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_THRES_CFG3, tic->tic_settings->THRES_CFG3.all);
}

void tic12400_fill_thres_cfg2_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_THRES_CFG2, tic->tic_settings->THRES_CFG2.all);
}

void tic12400_fill_thres_cfg1_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_THRES_CFG1, tic->tic_settings->THRES_CFG1.all);
}

void tic12400_fill_thres_cfg0_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_THRES_CFG0, tic->tic_settings->THRES_CFG0.all);
}

void tic12400_fill_int_en_cfg4_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_INT_EN_CFG4, tic->tic_settings->INT_EN_CFG4.all);
}

void tic12400_fill_int_en_cfg3_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_INT_EN_CFG3, tic->tic_settings->INT_EN_CFG3.all);
}

void tic12400_fill_int_en_cfg2_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_INT_EN_CFG2, tic->tic_settings->INT_EN_CFG2.all);
}

void tic12400_fill_int_en_cfg1_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_INT_EN_CFG1, tic->tic_settings->INT_EN_CFG1.all);
}

void tic12400_fill_int_en_cfg0_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_INT_EN_CFG0, tic->tic_settings->INT_EN_CFG0.all);
}

void tic12400_fill_int_en_comp2_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_INT_EN_COMP2, tic->tic_settings->INT_EN_COMP2.all);
}

void tic12400_fill_int_en_comp1_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_INT_EN_COMP1, tic->tic_settings->INT_EN_COMP1.all);
}

void tic12400_fill_thres_comp_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_THRES_COMP, tic->tic_settings->THRES_COMP.all);
}

void tic12400_fill_ccp_cfg1_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_CCP_CFG1, tic->tic_settings->CCP_CFG1.all);
}

void tic12400_fill_ccp_cfg0_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_CCP_CFG0, tic->tic_settings->CCP_CFG0.all);
}

void tic12400_fill_wc_cfg1_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_WC_CFG1, tic->tic_settings->WC_CFG1.all);
}

void tic12400_fill_wc_cfg0_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_WC_CFG0, tic->tic_settings->WC_CFG0.all);
}

void tic12400_fill_cs_select_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_CS_SELECT, tic->tic_settings->CS_SELECT.all);
}

void tic12400_fill_in_en_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_IN_EN, tic->tic_settings->IN_EN.all);
}

void tic12400_fill_config_settings_write(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 1, TIC12400_CONFIG, tic->tic_settings->CONFIG.all);
}

void tic12400_fill_int_stat_read(tic12400_t* tic) {
	tic124_tx_frame_fill(tic, 0, TIC12400_INT_STAT, 0);
}

void tic12400_callback_transfer(tic12400_t* tic) {
	spi_bus_callback_transfer(tic->spi_bus, &tic->spi_control, 1, SPI_BYTE_ORDER_REVERSE, &tic12400_handler, tic);
}

void tic12400_spi_bus_free(tic12400_t* tic) {
	spi_bus_free(tic->spi_bus);
}

void tic124_start_normal_operation(tic12400_t* tic) {
	TIC12400_CONFIG_REG config;
	config.all = tic->tic_settings->CONFIG.all;
	config.bit.trigger  = 0x1; /*Start TIC12400-Q1 to normal operation*/
	tic124_tx_frame_fill(tic, 1, TIC12400_CONFIG, config.all);
	tic12400_callback_transfer(tic);
}

void tic12400_mode_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_int_stat_read(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_matrix_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_mode_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_thresmap_cfg2_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_matrix_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_thresmap_cfg1_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_thresmap_cfg2_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_thresmap_cfg0_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_thresmap_cfg1_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_thres_cfg4_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_thresmap_cfg0_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_thres_cfg3_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_thres_cfg4_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_thres_cfg2_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_thres_cfg3_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_thres_cfg1_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_thres_cfg2_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_thres_cfg0_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_thres_cfg1_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_int_en_cfg4_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_thres_cfg0_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_int_en_cfg3_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_int_en_cfg4_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_int_en_cfg2_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_int_en_cfg3_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_int_en_cfg1_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_int_en_cfg2_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_int_en_cfg0_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_int_en_cfg1_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_int_en_comp2_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_int_en_cfg0_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_int_en_comp1_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_int_en_comp2_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_thres_comp_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_int_en_comp1_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_ccp_cfg1_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_thres_comp_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_ccp_cfg0_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_ccp_cfg1_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_wc_cfg1_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_ccp_cfg0_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_wc_cfg0_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_wc_cfg1_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_cs_select_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_wc_cfg0_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_in_en_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_cs_select_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {

	}
}

void tic12400_config_handler(tic12400_t* tic) {
	if(tic->int_stat.bit.por) {
		tic12400_fill_in_en_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {
		tic12400_spi_bus_free(tic);
	}
}

void tic12400_int_stat_handler(tic12400_t* tic) {
	tic->int_stat_last.all = tic->int_stat.all;
	tic->int_stat.all = tic->rx_frame.bit.data;
	if(tic->int_stat.bit.por) {
		tic12400_fill_config_settings_write(tic);
		tic12400_callback_transfer(tic);
	} else {
		if(tic->int_stat_last.bit.por) {
			tic124_start_normal_operation(tic);
		} else {
			tic12400_spi_bus_free(tic);
		}
	}
}

uint32_t tic12400_tx_frame_addr_read(tic12400_t* tic) {
	return tic->tx_frame.bit.addr;
}

void tic12400_handler(void* tic) {
	switch(tic12400_tx_frame_addr_read(tic)) {
	case TIC12400_INT_STAT: tic12400_int_stat_handler(tic);
		break;
	case TIC12400_CONFIG: tic12400_config_handler(tic);
		break;
	case TIC12400_IN_EN: tic12400_in_en_handler(tic);
		break;
	case TIC12400_CS_SELECT: tic12400_cs_select_handler(tic);
		break;
	case TIC12400_WC_CFG0: tic12400_wc_cfg0_handler(tic);
		break;
	case TIC12400_WC_CFG1: tic12400_wc_cfg1_handler(tic);
		break;
	case TIC12400_CCP_CFG0: tic12400_ccp_cfg0_handler(tic);
		break;
	case TIC12400_CCP_CFG1: tic12400_ccp_cfg1_handler(tic);
		break;
	case TIC12400_THRES_COMP: tic12400_thres_comp_handler(tic);
		break;
	case TIC12400_INT_EN_COMP1: tic12400_int_en_comp1_handler(tic);
		break;
	case TIC12400_INT_EN_COMP2: tic12400_int_en_comp2_handler(tic);
		break;
	case TIC12400_INT_EN_CFG0: tic12400_int_en_cfg0_handler(tic);
		break;
	case TIC12400_INT_EN_CFG1: tic12400_int_en_cfg1_handler(tic);
		break;
	case TIC12400_INT_EN_CFG2: tic12400_int_en_cfg2_handler(tic);
		break;
	case TIC12400_INT_EN_CFG3: tic12400_int_en_cfg3_handler(tic);
		break;
	case TIC12400_INT_EN_CFG4: tic12400_int_en_cfg4_handler(tic);
		break;
	case TIC12400_THRES_CFG0: tic12400_thres_cfg0_handler(tic);
		break;
	case TIC12400_THRES_CFG1: tic12400_thres_cfg1_handler(tic);
		break;
	case TIC12400_THRES_CFG2: tic12400_thres_cfg2_handler(tic);
		break;
	case TIC12400_THRES_CFG3: tic12400_thres_cfg3_handler(tic);
		break;
	case TIC12400_THRES_CFG4: tic12400_thres_cfg4_handler(tic);
		break;
	case TIC12400_THRESMAP_CFG0: tic12400_thresmap_cfg0_handler(tic);
		break;
	case TIC12400_THRESMAP_CFG1: tic12400_thresmap_cfg1_handler(tic);
		break;
	case TIC12400_THRESMAP_CFG2: tic12400_thresmap_cfg2_handler(tic);
		break;
	case TIC12400_MATRIX: tic12400_matrix_handler(tic);
		break;
	case TIC12400_MODE: tic12400_mode_handler(tic);
		break;
	default:
		break;
	}
}

void tic12400_int_stat_read(tic12400_t* tic) {
	tic12400_fill_int_stat_read(tic);
	spi_bus_transfer(tic->spi_bus, &tic->spi_control, 1, SPI_BYTE_ORDER_REVERSE, &tic12400_handler, tic);
}




