/*
 * tic12400_reg.h
 *
 *  Created on: 29 апр. 2022 г.
 *      Author: Ruslan
 */

#ifndef INC_TIC12400_REG_H_
#define INC_TIC12400_REG_H_

#include "tic12400_data.h"

#define TIC12400_REG_CTRL_SIZE 1
#define TIC12400_REG_SIZE (TIC12400_DATA_SIZE + TIC12400_REG_CTRL_SIZE)

//структура поля управления данными
#pragma pack(push, 1)
typedef struct {
	unsigned read : 1;
	unsigned read_done : 1;
	unsigned write : 1;
	unsigned write_done : 1;
	unsigned busy : 1;
	unsigned read_access : 1;
	unsigned write_access : 1;
	unsigned reserved : 1;
} tic12400_reg_ctrl_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_reg_ctrl_t) == TIC12400_REG_CTRL_SIZE, "Invalid size of tic12400_reg_ctrl_t!");

//структура регистра Device ID
#pragma pack(push, 1)
typedef struct {
	tic12400_dev_id_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_dev_id_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_dev_id_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_dev_id_t!");

//структура регистра Interrupt Status
#pragma pack(push, 1)
typedef struct {
	tic12400_int_stat_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_int_stat_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_int_stat_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_int_stat_t!");

//структура регистра CRC
#pragma pack(push, 1)
typedef struct {
	tic12400_crc_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_crc_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_crc_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_crc_t!");

//структура регистра Miscellaneous Status
#pragma pack(push, 1)
typedef struct {
	tic12400_in_stat_misc_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_in_stat_misc_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_in_stat_misc_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_in_stat_misc_t!");

//структура регистра Comparator Status
#pragma pack(push, 1)
typedef struct {
	tic12400_in_stat_comp_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_in_stat_comp_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_in_stat_comp_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_in_stat_comp_t!");

//структура регистра ADC0 Status
#pragma pack(push, 1)
typedef struct {
	tic12400_in_stat_adc0_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_in_stat_adc0_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_in_stat_adc0_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_in_stat_adc0_t!");

//структура регистра ADC1 Status
typedef struct {
	tic12400_in_stat_adc1_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_in_stat_adc1_t;
static_assert(sizeof(tic12400_in_stat_adc1_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_in_stat_adc1_t!");

//структура регистра Matrix0 Status
#pragma pack(push, 1)
typedef struct {
	tic12400_in_stat_matrix0_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_in_stat_matrix0_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_in_stat_matrix0_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_in_stat_matrix0_t!");

//структура регистра Matrix1 Status
#pragma pack(push, 1)
typedef struct {
	tic12400_in_stat_matrix1_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_in_stat_matrix1_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_in_stat_matrix1_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_in_stat_matrix1_t!");

//структура регистра ADC Raw Code
#pragma pack(push, 1)
typedef struct {
	tic12400_ana_stat_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_ana_stat_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_ana_stat_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_ana_stat_t!");

//структура регистра Device Global Configuration
#pragma pack(push, 1)
typedef struct {
	tic12400_config_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_config_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_config_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_config_t!");

//структура регистра Input Enable
#pragma pack(push, 1)
typedef struct {
	tic12400_in_en_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_in_en_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_in_en_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_in_en_t!");

//сруктура регистра Current Source/Sink Selection
#pragma pack(push, 1)
typedef struct {
	tic12400_cs_select_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_cs_select_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_cs_select_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_cs_select_t!");

//структура регистра Wetting Current Configuration 0
#pragma pack(push, 1)
typedef struct {
	tic12400_wc_cfg0_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_wc_cfg0_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_wc_cfg0_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_wc_cfg0_t!");

//структура регистра Wetting Current Configuration 1
#pragma pack(push, 1)
typedef struct {
	tic12400_wc_cfg1_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_wc_cfg1_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_wc_cfg1_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_wc_cfg1_t!");

//структура регистра Clean Current Polling 0
#pragma pack(push, 1)
typedef struct {
	tic12400_ccp_cfg0_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_ccp_cfg0_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_ccp_cfg0_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_ccp_cfg0_t!");

//структура регистра Clean Current Polling 1
#pragma pack(push, 1)
typedef struct {
	tic12400_ccp_cfg1_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_ccp_cfg1_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_ccp_cfg1_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_ccp_cfg1_t!");

//структура регистра Comparator Threshold Control
#pragma pack(push, 1)
typedef struct {
	tic12400_thres_comp_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_thres_comp_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_thres_comp_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_thres_comp_t!");

//структура регистра Comparator Input Interrupt Generation 1
#pragma pack(push, 1)
typedef struct {
	tic12400_ent_en_comp1_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_int_en_comp1_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_int_en_comp1_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_ent_en_comp1_t!");

//структура регистра Comparator Input Interrupt Generation 2
#pragma pack(push, 1)
typedef struct {
	tic12400_ent_en_comp2_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_int_en_comp2_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_int_en_comp2_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_ent_en_comp2_t!");

//структура регистра Global Interrupt Generation Control 0
#pragma pack(push, 1)
typedef struct {
	tic12400_int_en_cfg0_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_int_en_cfg0_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_int_en_cfg0_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_int_en_cfg0_t!");

//структура регистра ADC Input Interrupt Generation Control 1
#pragma pack(push, 1)
typedef struct {
	tic12400_int_en_cfg1_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_int_en_cfg1_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_int_en_cfg1_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_int_en_cfg1_t!");

//структура регистра ADC Input Interrupt Generation Control 2
#pragma pack(push, 1)
typedef struct {
	tic12400_int_en_cfg2_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_int_en_cfg2_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_int_en_cfg2_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_int_en_cfg2_t!");

//структура регистра ADC Input Interrupt Generation Control 3
#pragma pack(push, 1)
typedef struct {
	tic12400_int_en_cfg3_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_int_en_cfg3_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_int_en_cfg3_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_int_en_cfg3_t!");

//структура регистра ADC Input Interrupt Generation Control 4
#pragma pack(push, 1)
typedef struct {
	tic12400_int_en_cfg4_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_int_en_cfg4_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_int_en_cfg4_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_int_en_cfg4_t!");

//структура регистра ADC Threshold Control
#pragma pack(push, 1)
typedef struct {
	tic12400_thres_cfg_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_thres_cfg_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_thres_cfg_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_thres_cfg_t!");

//структура регистра ADC Threshold Mapping 0
#pragma pack(push, 1)
typedef struct {
	tic12400_thresmap_cfg0_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_thresmap_cfg0_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_thresmap_cfg0_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_thresmap_cfg0_t!");

//структура регистра ADC Threshold Mapping Register 1
#pragma pack(push, 1)
typedef struct {
	tic12400_thresmap_cfg1_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_thresmap_cfg1_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_thresmap_cfg1_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_thresmap_cfg1_t!");

//структура регистра ADC Threshold Mapping Register 2
#pragma pack(push, 1)
typedef struct {
	tic12400_thresmap_cfg2_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_thresmap_cfg2_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_thresmap_cfg2_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_thresmap_cfg2_t!");

//структура регистра Matrix Setting
#pragma pack(push, 1)
typedef struct {
	tic12400_matrix_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_matrix_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_matrix_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_matrix_t!");

//структура регистра Mode Setting
#pragma pack(push, 1)
typedef struct {
	tic12400_mode_data_t data;
	tic12400_reg_ctrl_t ctrl;
} tic12400_mode_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_mode_t) == TIC12400_REG_SIZE, "Invalid size of tic12400_mode_t!");

#endif /* INC_TIC12400_REG_H_ */
