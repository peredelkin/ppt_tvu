/*
 * tic12400_data.h
 *
 *  Created on: 29 апр. 2022 г.
 *      Author: Ruslan
 */

#ifndef INC_TIC12400_DATA_H_
#define INC_TIC12400_DATA_H_

#include <assert.h>

#define TIC12400_DATA_SIZE 3

//структура данных Device ID
#pragma pack(push, 1)
typedef struct {
	unsigned minor : 4;
	unsigned major : 7;
	unsigned reserved : 13;
} tic12400_dev_id_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_dev_id_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_dev_id_data_t!");

//структура данных Interrupt Status
#pragma pack(push, 1)
typedef struct {
	unsigned por : 1;
	unsigned spi_fail : 1;
	unsigned par_fail : 1;
	unsigned ssc : 1;
	unsigned tsd : 1;
	unsigned tw : 1;
	unsigned ov : 1;
	unsigned uv : 1;
	unsigned crc_calc : 1;
	unsigned vs0 : 1;
	unsigned vs1 : 1;
	unsigned wet_diag : 1;
	unsigned adc_diag : 1;
	unsigned chk_fail : 1;
	unsigned reserved : 10;
} tic12400_int_stat_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_int_stat_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_int_stat_data_t!");

//структура данных CRC
#pragma pack(push, 1)
typedef struct {
	unsigned crc : 16;
	unsigned reserved : 8;
} tic12400_crc_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_crc_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_crc_t!");

//структура данных Miscellaneous Status
#pragma pack(push, 1)
typedef struct {
	unsigned tsd_stat : 1;
	unsigned tw_stat : 1;
	unsigned ov_stat : 1;
	unsigned uv_stat : 1;
	unsigned vs0_stat : 2;
	unsigned vs1_stat : 2;
	unsigned in0_d : 1;
	unsigned in1_d : 1;
	unsigned in2_d : 1;
	unsigned in3_d : 1;
	unsigned adc_d : 1;
	unsigned reserved : 11;
} tic12400_in_stat_misc_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_in_stat_misc_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_in_stat_misc_data_t!");

//структура данных Comparator Status
#pragma pack(push, 1)
typedef struct {
	unsigned inc_0 : 1;
	unsigned inc_1 : 1;
	unsigned inc_2 : 1;
	unsigned inc_3 : 1;
	unsigned inc_4 : 1;
	unsigned inc_5 : 1;
	unsigned inc_6 : 1;
	unsigned inc_7 : 1;
	unsigned inc_8 : 1;
	unsigned inc_9 : 1;
	unsigned inc_10 : 1;
	unsigned inc_11 : 1;
	unsigned inc_12 : 1;
	unsigned inc_13 : 1;
	unsigned inc_14 : 1;
	unsigned inc_15 : 1;
	unsigned inc_16 : 1;
	unsigned inc_17 : 1;
	unsigned inc_18 : 1;
	unsigned inc_19 : 1;
	unsigned inc_20 : 1;
	unsigned inc_21 : 1;
	unsigned inc_22 : 1;
	unsigned inc_23 : 1;
} tic12400_in_stat_comp_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_in_stat_comp_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_in_stat_comp_data_t!");

//структура данных ADC0 Status
#pragma pack(push, 1)
typedef struct {
	unsigned ina_0 : 1;
	unsigned ina_1 : 1;
	unsigned ina_2 : 1;
	unsigned ina_3 : 1;
	unsigned ina_4 : 1;
	unsigned ina_5 : 1;
	unsigned ina_6 : 1;
	unsigned ina_7 : 1;
	unsigned ina_8 : 1;
	unsigned ina_9 : 1;
	unsigned ina_10 : 1;
	unsigned ina_11 : 1;
	unsigned ina_12 : 2;
	unsigned ina_13 : 2;
	unsigned ina_14 : 2;
	unsigned ina_15 : 2;
	unsigned ina_16 : 2;
	unsigned ina_17 : 2;
} tic12400_in_stat_adc0_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_in_stat_adc0_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_in_stat_adc0_data_t!");

//структура данных ADC1 Status
#pragma pack(push, 1)
typedef struct {
	unsigned ina_18 : 2;
	unsigned ina_19 : 2;
	unsigned ina_20 : 2;
	unsigned ina_21 : 2;
	unsigned ina_22 : 2;
	unsigned ina_23 : 3;
	unsigned reserved : 11;
} tic12400_in_stat_adc1_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_in_stat_adc1_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_in_stat_adc1_data_t!");

//структура данных Matrix0 Status
#pragma pack(push, 1)
typedef struct {
	unsigned inmat_10_in4 : 1;
	unsigned inmat_10_in5 : 1;
	unsigned inmat_10_in6 : 1;
	unsigned inmat_10_in7 : 1;
	unsigned inmat_10_in8 : 1;
	unsigned inmat_10_in9 : 1;
	unsigned inmat_11_in4 : 1;
	unsigned inmat_11_in5 : 1;
	unsigned inmat_11_in6 : 1;
	unsigned inmat_11_in7 : 1;
	unsigned inmat_11_in8 : 1;
	unsigned inmat_11_in9 : 1;
	unsigned inmat_12_in4 : 1;
	unsigned inmat_12_in5 : 1;
	unsigned inmat_12_in6 : 1;
	unsigned inmat_12_in7 : 1;
	unsigned inmat_12_in8 : 1;
	unsigned inmat_12_in9 : 1;
	unsigned inmat_13_in4 : 1;
	unsigned inmat_13_in5 : 1;
	unsigned inmat_13_in6 : 1;
	unsigned inmat_13_in7 : 1;
	unsigned inmat_13_in8 : 1;
	unsigned inmat_13_in9 : 1;
} tic12400_in_stat_matrix0_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_in_stat_matrix0_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_in_stat_matrix0_data_t!");

//структура данных Matrix1 Status
#pragma pack(push, 1)
typedef struct {
	unsigned inmat_14_in4 : 1;
	unsigned inmat_14_in5 : 1;
	unsigned inmat_14_in6 : 1;
	unsigned inmat_14_in7 : 1;
	unsigned inmat_14_in8 : 1;
	unsigned inmat_14_in9 : 1;
	unsigned inmat_15_in4 : 1;
	unsigned inmat_15_in5 : 1;
	unsigned inmat_15_in6 : 1;
	unsigned inmat_15_in7 : 1;
	unsigned inmat_15_in8 : 1;
	unsigned inmat_15_in9 : 1;
	unsigned in0_com : 1;
	unsigned in1_com : 1;
	unsigned in2_com : 1;
	unsigned in3_com : 1;
	unsigned in4_com : 1;
	unsigned in5_com : 1;
	unsigned in6_com : 1;
	unsigned in7_com : 1;
	unsigned in8_com : 1;
	unsigned in9_com : 1;
	unsigned in10_com : 1;
	unsigned in11_com : 1;
} tic12400_in_stat_matrix1_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_in_stat_matrix1_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_in_stat_matrix1_data_t!");

//структура данных ADC Raw Code
#pragma pack(push, 1)
typedef struct {
	unsigned in0_ana : 10;
	unsigned in1_ana : 10;
	unsigned reserved : 4;
} tic12400_ana_stat_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_ana_stat_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_ana_stat_data_t!");

//структура данных Device Global Configuration
#pragma pack(push, 1)
typedef struct {
	unsigned reset : 1;
	unsigned poll_time : 4;
	unsigned poll_act_time : 4;
	unsigned crc_t : 1;
	unsigned poll_en : 1;
	unsigned trigger : 1;
	unsigned int_config : 1;
	unsigned tw_cur_dis_cso : 1;
	unsigned det_filter : 2;
	unsigned tw_cur_dis_csi : 1;
	unsigned vs_meas_en : 1;
	unsigned wet_d_in0_en : 1;
	unsigned wet_d_in1_en : 1;
	unsigned wet_d_in2_en : 1;
	unsigned wet_d_in3_en : 1;
	unsigned adc_diag_t : 1;
	unsigned vs_ratio : 1;
} tic12400_config_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_config_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_config_data_t!");

//структура данных Input Enable
#pragma pack(push, 1)
typedef struct {
	unsigned in_en_0 : 1;
	unsigned in_en_1 : 1;
	unsigned in_en_2 : 1;
	unsigned in_en_3 : 1;
	unsigned in_en_4 : 1;
	unsigned in_en_5 : 1;
	unsigned in_en_6 : 1;
	unsigned in_en_7 : 1;
	unsigned in_en_8 : 1;
	unsigned in_en_9 : 1;
	unsigned in_en_10 : 1;
	unsigned in_en_11 : 1;
	unsigned in_en_12 : 1;
	unsigned in_en_13 : 1;
	unsigned in_en_14 : 1;
	unsigned in_en_15 : 1;
	unsigned in_en_16 : 1;
	unsigned in_en_17 : 1;
	unsigned in_en_18 : 1;
	unsigned in_en_19 : 1;
	unsigned in_en_20 : 1;
	unsigned in_en_21 : 1;
	unsigned in_en_22 : 1;
	unsigned in_en_23 : 1;
} tic12400_in_en_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_in_en_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_in_en_data_t!");

//структура данных Current Source/Sink Selection
#pragma pack(push, 1)
typedef struct {
	unsigned cs_in0 : 1;
	unsigned cs_in1 : 1;
	unsigned cs_in2 : 1;
	unsigned cs_in3 : 1;
	unsigned cs_in4 : 1;
	unsigned cs_in5 : 1;
	unsigned cs_in6 : 1;
	unsigned cs_in7 : 1;
	unsigned cs_in8 : 1;
	unsigned cs_in9 : 1;
	unsigned reserved : 14;
} tic12400_cs_select_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_cs_select_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_cs_select_data_t!");

//структура данных Wetting Current Configuration 0
#pragma pack(push, 1)
typedef struct {
	unsigned wc_in0_in1 : 3;
	unsigned wc_in2_in3 : 3;
	unsigned wc_in4 : 3;
	unsigned wc_in5 : 3;
	unsigned wc_in6_in7 : 3;
	unsigned wc_in8_in9 : 3;
	unsigned wc_in10 : 3;
	unsigned wc_in11 : 3;
} tic12400_wc_cfg0_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_wc_cfg0_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_wc_cfg0_data_t!");

//структура данных Wetting Current Configuration 1
#pragma pack(push, 1)
typedef struct {
	unsigned wc_in12_in13 : 3;
	unsigned wc_in14_in15 : 3;
	unsigned wc_in16_in17 : 3;
	unsigned wc_in18_in19 : 3;
	unsigned wc_in20_in21 : 3;
	unsigned wc_in22 : 3;
	unsigned wc_in23 : 3;
	unsigned auto_scale_dis_cso : 1;
	unsigned auto_scale_dis_csi : 1;
	unsigned reserved : 1;
} tic12400_wc_cfg1_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_wc_cfg1_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_wc_cfg1_data_t!");

//структура данных Clean Current Polling 0
#pragma pack(push, 1)
typedef struct {
	unsigned wc_ccp0 : 1;
	unsigned wc_ccp1 : 1;
	unsigned wc_ccp2 : 1;
	unsigned wc_ccp3 : 1;
	unsigned ccp_time : 3;
	unsigned reserved : 17;
} tic12400_ccp_cfg0_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_ccp_cfg0_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_ccp_cfg0_data_t!");

//структура данных Clean Current Polling 1
#pragma pack(push, 1)
typedef struct {
	unsigned ccp_in0 : 1;
	unsigned ccp_in1 : 1;
	unsigned ccp_in2 : 1;
	unsigned ccp_in3 : 1;
	unsigned ccp_in4 : 1;
	unsigned ccp_in5 : 1;
	unsigned ccp_in6 : 1;
	unsigned ccp_in7 : 1;
	unsigned ccp_in8 : 1;
	unsigned ccp_in9 : 1;
	unsigned ccp_in10 : 1;
	unsigned ccp_in11 : 1;
	unsigned ccp_in12 : 1;
	unsigned ccp_in13 : 1;
	unsigned ccp_in14 : 1;
	unsigned ccp_in15 : 1;
	unsigned ccp_in16 : 1;
	unsigned ccp_in17 : 1;
	unsigned ccp_in18 : 1;
	unsigned ccp_in19 : 1;
	unsigned ccp_in20 : 1;
	unsigned ccp_in21 : 1;
	unsigned ccp_in22 : 1;
	unsigned ccp_in23 : 1;
} tic12400_ccp_cfg1_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_ccp_cfg1_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_ccp_cfg1_data_t!");

//структура данных Comparator Threshold Control
#pragma pack(push, 1)
typedef struct {
	unsigned thres_comp_in0_in3 : 2;
	unsigned thres_comp_in4_in7 : 2;
	unsigned thres_comp_in8_in11 : 2;
	unsigned thres_comp_in12_in15 : 2;
	unsigned thres_comp_in16_in19 : 2;
	unsigned thres_comp_in20_in23 : 2;
	unsigned reserved : 12;
} tic12400_thres_comp_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_thres_comp_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_thres_comp_data_t!");

//структура данных Comparator Input Interrupt Generation 1
#pragma pack(push, 1)
typedef struct {
	unsigned inc_en_0 : 2;
	unsigned inc_en_1 : 2;
	unsigned inc_en_2 : 2;
	unsigned inc_en_3 : 2;
	unsigned inc_en_4 : 2;
	unsigned inc_en_5 : 2;
	unsigned inc_en_6 : 2;
	unsigned inc_en_7 : 2;
	unsigned inc_en_8 : 2;
	unsigned inc_en_9 : 2;
	unsigned inc_en_10 : 2;
	unsigned inc_en_11 : 2;
} tic12400_ent_en_comp1_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_ent_en_comp1_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_ent_en_comp1_data_t!");

//структура данных Comparator Input Interrupt Generation 2
#pragma pack(push, 1)
typedef struct {
	unsigned inc_en_12 : 2;
	unsigned inc_en_13 : 2;
	unsigned inc_en_14 : 2;
	unsigned inc_en_15 : 2;
	unsigned inc_en_16 : 2;
	unsigned inc_en_17 : 2;
	unsigned inc_en_18 : 2;
	unsigned inc_en_19 : 2;
	unsigned inc_en_20 : 2;
	unsigned inc_en_21 : 2;
	unsigned inc_en_22 : 2;
	unsigned inc_en_23 : 2;
} tic12400_ent_en_comp2_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_ent_en_comp2_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_ent_en_comp2_data_t!");

//структура данных Global Interrupt Generation Control 0
#pragma pack(push, 1)
typedef struct {
	unsigned spi_fail_en : 1;
	unsigned par_fail_en : 1;
	unsigned ssc_en : 1;
	unsigned tsd_en : 1;
	unsigned tw_en : 1;
	unsigned ov_en : 1;
	unsigned uv_en : 1;
	unsigned crc_calc_en : 1;
	unsigned vs0_en : 1;
	unsigned vs1_en : 1;
	unsigned wet_diag_en : 1;
	unsigned adc_diag_en : 1;
	unsigned reserved : 12;
} tic12400_int_en_cfg0_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_int_en_cfg0_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_int_en_cfg0_data_t!");

//структура данных ADC Input Interrupt Generation Control 1
#pragma pack(push, 1)
typedef struct {
	unsigned in0_en : 2;
	unsigned in1_en : 2;
	unsigned in2_en : 2;
	unsigned in3_en : 2;
	unsigned in4_en : 2;
	unsigned in5_en : 2;
	unsigned in6_en : 2;
	unsigned in7_en : 2;
	unsigned in8_en : 2;
	unsigned in9_en : 2;
	unsigned in10_en : 2;
	unsigned in11_en : 2;
} tic12400_int_en_cfg1_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_int_en_cfg1_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_int_en_cfg1_data_t!");

//структура данных ADC Input Interrupt Generation Control 2
#pragma pack(push, 1)
typedef struct {
	unsigned in12_en : 4;
	unsigned in13_en : 4;
	unsigned in14_en : 4;
	unsigned in15_en : 4;
	unsigned in16_en : 4;
	unsigned in17_en : 4;
} tic12400_int_en_cfg2_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_int_en_cfg2_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_int_en_cfg2_data_t!");

//структура данных ADC Input Interrupt Generation Control 3
#pragma pack(push, 1)
typedef struct {
	unsigned in18_en : 6;
	unsigned in19_en : 6;
	unsigned in20_en : 6;
	unsigned in21_en : 6;
} tic12400_int_en_cfg3_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_int_en_cfg3_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_int_en_cfg3_data_t!");

//структура данных ADC Input Interrupt Generation Control 4
#pragma pack(push, 1)
typedef struct {
	unsigned in22_en : 6;
	unsigned in23_en : 10;
	unsigned vs_th0_en : 4;
	unsigned vs_th1_en : 4;
} tic12400_int_en_cfg4_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_int_en_cfg4_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_int_en_cfg4_data_t!");

//структура данных ADC Threshold Control
#pragma pack(push, 1)
typedef struct {
	unsigned thres0 : 10;
	unsigned thres1 : 10;
	unsigned reserved : 4;
} tic12400_thres_cfg_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_thres_cfg_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_thres_cfg_data_t!");

//структура данных ADC Threshold Mapping 0
#pragma pack(push, 1)
typedef struct {
	unsigned thresmap_in0 : 3;
	unsigned thresmap_in1 : 3;
	unsigned thresmap_in2 : 3;
	unsigned thresmap_in3 : 3;
	unsigned thresmap_in4 : 3;
	unsigned thresmap_in5 : 3;
	unsigned thresmap_in6 : 3;
	unsigned thresmap_in7 : 3;
} tic12400_thresmap_cfg0_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_thresmap_cfg0_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_thresmap_cfg0_data_t!");

//структура данных ADC Threshold Mapping 1
#pragma pack(push, 1)
typedef struct {
	unsigned thresmap_in8 : 3;
	unsigned thresmap_in9 : 3;
	unsigned thresmap_in10 : 3;
	unsigned thresmap_in11 : 3;
	unsigned thresmap_in12_in17_2a : 3;
	unsigned thresmap_in12_in17_2b : 3;
	unsigned reservred : 6;
} tic12400_thresmap_cfg1_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_thresmap_cfg1_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_thresmap_cfg1_data_t!");

//структура данных ADC Threshold Mapping 2
#pragma pack(push, 1)
typedef struct {
	unsigned thresmap_in18_in23_3a : 3;
	unsigned thresmap_in18_in23_3b : 3;
	unsigned thresmap_in18_in23_3c : 3;
	unsigned thresmap_vs0_thres_2a : 3;
	unsigned thresmap_vs0_thres_2b : 3;
	unsigned thresmap_vs1_thres_2a : 3;
	unsigned thresmap_vs1_thres_2b : 3;
	unsigned reserved : 3;
} tic12400_thresmap_cfg2_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_thresmap_cfg2_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_thresmap_cfg2_data_t!");

//структура данных Matrix Setting
#pragma pack(push, 1)
typedef struct {
	unsigned poll_act_time_m : 3;
	unsigned matrix : 2;
	unsigned thres_com : 10;
	unsigned in_com_en : 2;
	unsigned reserved : 7;
} tic12400_matrix_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_matrix_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_matrix_data_t!");

//структура данных Mode Setting
#pragma pack(push, 1)
typedef struct {
	unsigned m_in0 : 1;
	unsigned m_in1 : 1;
	unsigned m_in2 : 1;
	unsigned m_in3 : 1;
	unsigned m_in4 : 1;
	unsigned m_in5 : 1;
	unsigned m_in6 : 1;
	unsigned m_in7 : 1;
	unsigned m_in8 : 1;
	unsigned m_in9 : 1;
	unsigned m_in10 : 1;
	unsigned m_in11 : 1;
	unsigned m_in12 : 1;
	unsigned m_in13 : 1;
	unsigned m_in14 : 1;
	unsigned m_in15 : 1;
	unsigned m_in16 : 1;
	unsigned m_in17 : 1;
	unsigned m_in18 : 1;
	unsigned m_in19 : 1;
	unsigned m_in20 : 1;
	unsigned m_in21 : 1;
	unsigned m_in22 : 1;
	unsigned m_in23 : 1;
} tic12400_mode_data_t;
#pragma pack(pop)
static_assert(sizeof(tic12400_mode_data_t) == TIC12400_DATA_SIZE, "Invalid size of tic12400_mode_data_t!");

#endif /* INC_TIC12400_DATA_H_ */
