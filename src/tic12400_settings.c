/*
 * tic12400_settings.c
 *
 *  Created on: 11 нояб. 2022 г.
 *      Author: Ruslan
 */

#include "tic12400.h"

const TIC12400_DEVICE_ID_REG tic12400_device_id_const = {
		.bit.minor = 0x0,
		.bit.major = 0x2
};

const TIC12400_SETTINGS_TypeDef tic124_settings_const = {
		.CONFIG.bit.reset = 0x0, /*No reset*/
		.CONFIG.bit.poll_time = 0x2, /*8ms*/
		.CONFIG.bit.poll_act_time = 0x7, /*512us*/
		.CONFIG.bit.crc_t = 0x0, /*no CRC calculation triggered*/
		.CONFIG.bit.poll_en = 0x0, /*Polling disabled*/
		.CONFIG.bit.trigger = 0x0, /*Stop TIC12400-Q1 from normal operation*/
		.CONFIG.bit.int_config = 0x0, /*INT pin assertion scheme set to static*/
		.CONFIG.bit.tw_cur_dis_cso = 0x0, /*Enable CSO wetting current reduction*/
		.CONFIG.bit.det_filter = 0x0, /*Every sample is valid and taken for threshold evaluation*/
		.CONFIG.bit.tw_cur_dis_csi = 0x0, /*Enable CSI wetting current reduction*/
		.CONFIG.bit.vs_meas_en = 0x1, /*Enable VS measurement at the end of every polling cycle*/
		.CONFIG.bit.wet_d_in0_en = 0x0, /*Disable wetting current diagnostic for input IN0*/
		.CONFIG.bit.wet_d_in1_en = 0x0, /*Disable wetting current diagnostic for input IN1*/
		.CONFIG.bit.wet_d_in2_en = 0x0, /*Disable wetting current diagnostic for input IN2*/
		.CONFIG.bit.wet_d_in3_en = 0x0, /*Disable wetting current diagnostic for input IN3*/
		.CONFIG.bit.adc_diag_t = 0x0, /*Disable ADC self-diagnostic feature*/
		.CONFIG.bit.vs_ratio = 0x1, /*Use voltage divider factor of 10 for the VS measurement*/

		.IN_EN.bit.in_en_0 = 0x0, /*ResDI_4*/
		.IN_EN.bit.in_en_1 = 0x0, /*ResDI_2*/
		.IN_EN.bit.in_en_2 = 0x1, /*NTC5*/
		.IN_EN.bit.in_en_3 = 0x1, /*NTC6*/
		.IN_EN.bit.in_en_4 = 0x1, /*NTC4*/
		.IN_EN.bit.in_en_5 = 0x1, /*NTC1*/
		.IN_EN.bit.in_en_6 = 0x1, /*NTC3*/
		.IN_EN.bit.in_en_7 = 0x1, /*NTC2*/
		.IN_EN.bit.in_en_8 = 0x1, /*DI1*/
		.IN_EN.bit.in_en_9 = 0x1, /*DI2*/
		.IN_EN.bit.in_en_10 = 0x1, /*DI3*/
		.IN_EN.bit.in_en_11 = 0x1, /*DI4*/
		.IN_EN.bit.in_en_12 = 0x1, /*DI5*/
		.IN_EN.bit.in_en_13 = 0x1, /*DI6*/
		.IN_EN.bit.in_en_14 = 0x1, /*DI7*/
		.IN_EN.bit.in_en_15 = 0x1, /*DI8*/
		.IN_EN.bit.in_en_16 = 0x0, /*NC*/
		.IN_EN.bit.in_en_17 = 0x0, /*NC*/
		.IN_EN.bit.in_en_18 = 0x1, /*5VREF*/
		.IN_EN.bit.in_en_19 = 0x1, /*DI9*/
		.IN_EN.bit.in_en_20 = 0x1, /*DI10*/
		.IN_EN.bit.in_en_21 = 0x0, /*ResDI_10*/
		.IN_EN.bit.in_en_22 = 0x0, /*ResDI_8*/
		.IN_EN.bit.in_en_23 = 0x0, /*ResDI_6*/

		.CS_SELECT.cs_in0 = 0x0,
		.CS_SELECT.cs_in1 = 0x0,
		.CS_SELECT.cs_in2 = 0x0,
		.CS_SELECT.cs_in3 = 0x0,
		.CS_SELECT.cs_in4 = 0x0,
		.CS_SELECT.cs_in5 = 0x0,
		.CS_SELECT.cs_in6 = 0x0,
		.CS_SELECT.cs_in7 = 0x0,
		.CS_SELECT.cs_in8 = 0x0,
		.CS_SELECT.cs_in9 = 0x0,

		//.WC_CFG0;
		//.WC_CFG1;
		//.CCP_CFG0;
		//.CCP_CFG1;

		.THRES_COMP.bit.thres_comp_in0_in3 = 0x3, /*Comparator threshold set to 4 V*/
		.THRES_COMP.bit.thres_comp_in4_in7 = 0x3, /*Comparator threshold set to 4 V*/
		.THRES_COMP.bit.thres_comp_in8_in11 = 0x3, /*Comparator threshold set to 4 V*/
		.THRES_COMP.bit.thres_comp_in12_in15 = 0x3, /*Comparator threshold set to 4 V*/
		.THRES_COMP.bit.thres_comp_in16_in19 = 0x3, /*Comparator threshold set to 4 V*/
		.THRES_COMP.bit.thres_comp_in20_in23 = 0x3, /*Comparator threshold set to 4 V*/

		//.INT_EN_COMP1;
		//.INT_EN_COMP2;
		//.INT_EN_CFG0;
		//.INT_EN_CFG1;
		//.INT_EN_CFG2;
		//.INT_EN_CFG3;
		//.INT_EN_CFG4;
		//.THRES_CFG0;
		//.THRES_CFG1;
		//.THRES_CFG2;
		//.THRES_CFG3;
		//.THRES_CFG4;
		//.THRESMAP_CFG0;
		//.THRESMAP_CFG1;
		//.THRESMAP_CFG2;
		//.MATRIX;

		.MODE.bit.m_in0 = 0x0, /*Comparator mode for ResDI_4*/
		.MODE.bit.m_in1 = 0x0, /*Comparator mode for ResDI_2*/
		.MODE.bit.m_in2 = 0x1, /*ADC mode for NTC5*/
		.MODE.bit.m_in3 = 0x1, /*ADC mode for NTC6*/
		.MODE.bit.m_in4 = 0x1, /*ADC mode for NTC4*/
		.MODE.bit.m_in5 = 0x1, /*ADC mode for NTC1*/
		.MODE.bit.m_in6 = 0x1, /*ADC mode for NTC3*/
		.MODE.bit.m_in7 = 0x1, /*ADC mode for NTC2*/
		.MODE.bit.m_in8 = 0x0, /*Comparator mode for DI1*/
		.MODE.bit.m_in9 = 0x0, /*Comparator mode for DI2*/
		.MODE.bit.m_in10 = 0x0, /*Comparator mode for DI3*/
		.MODE.bit.m_in11 = 0x0, /*Comparator mode for DI4*/
		.MODE.bit.m_in12 = 0x0, /*Comparator mode for DI5*/
		.MODE.bit.m_in13 = 0x0, /*Comparator mode for DI6*/
		.MODE.bit.m_in14 = 0x0, /*Comparator mode for DI7*/
		.MODE.bit.m_in15 = 0x0, /*Comparator mode for DI8*/
		.MODE.bit.m_in16 = 0x0, /*Comparator mode for NC*/
		.MODE.bit.m_in17 = 0x0, /*Comparator mode for NC*/
		.MODE.bit.m_in18 = 0x1, /*ADC mode for 5VREF*/
		.MODE.bit.m_in19 = 0x0, /*Comparator mode for DI9*/
		.MODE.bit.m_in20 = 0x0, /*Comparator mode for DI10*/
		.MODE.bit.m_in21 = 0x0, /*Comparator mode for ResDI_10*/
		.MODE.bit.m_in22 = 0x0, /*Comparator mode for ResDI_8*/
		.MODE.bit.m_in23 = 0x0 /*Comparator mode for ResDI_6*/
};
