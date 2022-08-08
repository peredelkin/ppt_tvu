/*
 * tic124000.h
 *
 *  Created on: 5 апр. 2022 г.
 *      Author: Ruslan
 */

#ifndef INC_TIC12400_H_
#define INC_TIC12400_H_


#include <stdint.h>
#include <stdbool.h>

#include "tic12400_reg.h"

#define TIC12400_REG_MAP_SIZE (47 * TIC12400_REG_SIZE)
#define TIC12400_FRAME_SIZE 4

// tic12400_
// TIC12400_

//0x1h DEVICE_ID
//0x2h INT_STAT
//0x3h CRC
//0x4h IN_STAT_MISC
//0x5h IN_STAT_COMP
//0x6h-7h IN_STAT_ADC0, IN_STAT_ADC1
//0x8h-9h IN_STAT_MATRIX0, IN_STAT_MATRIX1
//0xAh-16h ANA_STAT0- ANA_STAT12
//0x1Ah CONFIG
//0x1Bh IN_EN
//0x1Ch CS_SELECT
//0x1Dh-1Eh WC_CFG0, WC_CFG1
//0x1Fh-20h CCP_CFG0, CCP_CFG1
//0x21h THRES_COMP
//0x22h-23h INT_EN_COMP1, INT_EN_COMP2
//0x24h INT_EN_CFG0
//0x25h-28h INT_EN_CFG1- INT_EN_CFG4
//0x29h-2Dh THRES_CFG0- THRES_CFG4
//0x2Eh-30h THRESMAP_CFG0- THRESMAP_CFG2
//0x31h MATRIX
//0x32h MODE

enum TIC12400_ADDR {
	TIC12400_RESERVED0,

	TIC12400_DEVICE_ID,
	TIC12400_INT_STAT,
	TIC12400_CRC,
	TIC12400_IN_STAT_MISC,
	TIC12400_IN_STAT_COMP,
	TIC12400_IN_STAT_ADC0,
	TIC12400_IN_STAT_ADC1,
	TIC12400_IN_STAT_MATRIX0,
	TIC12400_IN_STAT_MATRIX1,
	TIC12400_ANA_STAT0,
	TIC12400_ANA_STAT1,
	TIC12400_ANA_STAT2,
	TIC12400_ANA_STAT3,
	TIC12400_ANA_STAT4,
	TIC12400_ANA_STAT5,
	TIC12400_ANA_STAT6,
	TIC12400_ANA_STAT7,
	TIC12400_ANA_STAT8,
	TIC12400_ANA_STAT9,
	TIC12400_ANA_STAT10,
	TIC12400_ANA_STAT11,
	TIC12400_ANA_STAT12,

	TIC12400_RESERVED23,
	TIC12400_RESERVED24,
	TIC12400_RESERVED25,

	TIC12400_CONFIG,
	TIC12400_IN_EN,
	TIC12400_CS_SELECT,
	TIC12400_WC_CFG0,
	TIC12400_WC_CFG1,
	TIC12400_CCP_CFG0,
	TIC12400_CCP_CFG1,
	TIC12400_THRES_COMP,
	TIC12400_INT_EN_COMP1,
	TIC12400_INT_EN_COMP2,
	TIC12400_INT_EN_CFG0,
	TIC12400_INT_EN_CFG1,
	TIC12400_INT_EN_CFG2,
	TIC12400_INT_EN_CFG3,
	TIC12400_INT_EN_CFG4,
	TIC12400_THRES_CFG0,
	TIC12400_THRES_CFG1,
	TIC12400_THRES_CFG2,
	TIC12400_THRES_CFG3,
	TIC12400_THRES_CFG4,
	TIC12400_THRESMAP_CFG0,
	TIC12400_THRESMAP_CFG1,
	TIC12400_THRESMAP_CFG2,
	TIC12400_MATRIX,
	TIC12400_MODE
};

//TIC12400 47 Registers
#pragma pack(push, 1)
typedef struct {
	tic12400_dev_id_t dev_id;
	tic12400_int_stat_t int_stat;
	tic12400_crc_t crc;
	tic12400_in_stat_misc_t in_stat_misc;
	tic12400_in_stat_comp_t in_stat_comp;
	tic12400_in_stat_adc0_t in_stat_adc0;
	tic12400_in_stat_adc1_t in_stat_adc1;
	tic12400_in_stat_matrix0_t in_stat_matrix0;
	tic12400_in_stat_matrix1_t in_stat_matrix1;
	tic12400_ana_stat_t ana_stat[13];
	tic12400_config_t config;
	tic12400_in_en_t in_en;
	tic12400_cs_select_t cs_select;
	tic12400_wc_cfg0_t wc_cfg0;
	tic12400_wc_cfg1_t wc_cfg1;
	tic12400_ccp_cfg0_t ccp_cfg0;
	tic12400_ccp_cfg1_t ccp_cfg1;
	tic12400_thres_comp_t thres_comp;
	tic12400_int_en_comp1_t int_en_comp1;
	tic12400_int_en_comp2_t int_en_comp2;
	tic12400_int_en_cfg0_t int_en_cfg0;
	tic12400_int_en_cfg1_t int_en_cfg1;
	tic12400_int_en_cfg2_t int_en_cfg2;
	tic12400_int_en_cfg3_t int_en_cfg3;
	tic12400_int_en_cfg4_t int_en_cfg4;
	tic12400_thres_cfg_t thres_cfg[5];
	tic12400_thresmap_cfg0_t thresmap_cfg0;
	tic12400_thresmap_cfg1_t thresmap_cfg1;
	tic12400_thresmap_cfg2_t thresmap_cfg2;
	tic12400_matrix_t matrix;
	tic12400_mode_t mode;
} tic12400_reg_map_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_reg_map_t) == TIC12400_REG_MAP_SIZE, "Invalid size of tic12400_reg_map_t!");

//структура фрейма передачи
#pragma pack(push, 1)
typedef struct {
	unsigned par : 1;
	unsigned data : 24;
	unsigned addr : 6;
	unsigned rw : 1;
} tic12400_tx_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_tx_t) == TIC12400_FRAME_SIZE, "Invalid size of tic12400_tx_t!");

//структура фрейма приема
#pragma pack(push, 1)
typedef struct {
	unsigned par : 1;
	unsigned data : 24;
	unsigned oi : 1;
	unsigned temp : 1;
	unsigned vs_th : 1;
	unsigned ssc : 1;
	unsigned par_fail : 1;
	unsigned spi_fail : 1;
	unsigned por : 1;
} tic12400_rx_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_rx_t) == TIC12400_FRAME_SIZE, "Invalid size of tic12400_rx_t!");

//общая структура приема передачи tic12400
#pragma pack(push, 1)
typedef struct {
	tic12400_tx_t tx_frame;
	uint8_t tx_data[4];
	tic12400_rx_t rx_frame;
	uint8_t rx_data[4];
} tic12400_trx_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_trx_t) == (4*TIC12400_FRAME_SIZE), "Invalid size of tic12400_trx_t!");

//extern const tic12400_addr_t tic12400_addr;

#endif /* INC_TIC12400_H_ */
