/*
 * tic12400_settings.c
 *
 *  Created on: 11 нояб. 2022 г.
 *      Author: Ruslan
 */

#include "tic12400_settings.h"

TIC12400_TX_FRAME tic124_tx_frame[TIC12400_FRAME_COUNT];
TIC12400_RX_FRAME tic124_rx_frame[TIC12400_FRAME_COUNT];

const TIC12400_SETTINGS_TypeDef tic124_settings_const = {
		.CONFIG.bit.reset = 0x0,			/*No reset*/
		.CONFIG.bit.poll_time = 0x2,		/*8ms(how frequently each input is sampled)*/
		.CONFIG.bit.poll_act_time = 0x7,	/*512μs(time for wetting current)*/
		.CONFIG.bit.crc_t = 0x0,			/*no CRC calculation triggered*/
		.CONFIG.bit.poll_en = 0x0,			/*Polling disabled*/
		.CONFIG.bit.trigger = 0x0,			/*Stop TIC12400-Q1 from normal operation*/
		.CONFIG.bit.int_config = 0x0,		/*INT pin assertion scheme set to static*/
		.CONFIG.bit.tw_cur_dis_cso = 0x0,	/*Enable CSO wetting current reduction*/
		.CONFIG.bit.det_filter = 0x0,		/*Every sample is valid and taken for threshold evaluation*/
		.CONFIG.bit.tw_cur_dis_csi = 0x0,	/*Enable CSI wetting current reduction*/
		.CONFIG.bit.vs_meas_en = 0x1,		/*Enable VS measurement at the end of every polling cycle*/
		.CONFIG.bit.wet_d_in0_en = 0x0,		/*Disable wetting current diagnostic for input IN0*/
		.CONFIG.bit.wet_d_in1_en = 0x0,		/*Disable wetting current diagnostic for input IN1*/
		.CONFIG.bit.wet_d_in2_en = 0x0,		/*Disable wetting current diagnostic for input IN2*/
		.CONFIG.bit.wet_d_in3_en = 0x0,		/*Disable wetting current diagnostic for input IN3*/
		.CONFIG.bit.adc_diag_t = 0x0,		/*Disable ADC self-diagnostic feature*/
		.CONFIG.bit.vs_ratio = 0x1,			/*Use voltage divider factor of 10 for the VS measurement*/

		.IN_EN.bit.in_en_0 = 0x0,			/*Input disabled for ResDI_4*/
		.IN_EN.bit.in_en_1 = 0x0,			/*Input disabled for ResDI_2*/
		.IN_EN.bit.in_en_2 = 0x1,			/*Input enabled for NTC5*/
		.IN_EN.bit.in_en_3 = 0x1,			/*Input enabled for NTC6*/
		.IN_EN.bit.in_en_4 = 0x1,			/*Input enabled for NTC4*/
		.IN_EN.bit.in_en_5 = 0x1,			/*Input enabled for NTC1*/
		.IN_EN.bit.in_en_6 = 0x1,			/*Input enabled for NTC3*/
		.IN_EN.bit.in_en_7 = 0x1,			/*Input enabled for NTC2*/
		.IN_EN.bit.in_en_8 = 0x1,			/*Input enabled for DI1*/
		.IN_EN.bit.in_en_9 = 0x1,			/*Input enabled for DI2*/
		.IN_EN.bit.in_en_10 = 0x1,			/*Input enabled for DI3*/
		.IN_EN.bit.in_en_11 = 0x1,			/*Input enabled for DI4*/
		.IN_EN.bit.in_en_12 = 0x1,			/*Input enabled for DI5*/
		.IN_EN.bit.in_en_13 = 0x1,			/*Input enabled for DI6*/
		.IN_EN.bit.in_en_14 = 0x1,			/*Input enabled for DI7*/
		.IN_EN.bit.in_en_15 = 0x1,			/*Input enabled for DI8*/
		.IN_EN.bit.in_en_16 = 0x0,			/*Input disabled for NC*/
		.IN_EN.bit.in_en_17 = 0x0,			/*Input disabled for NC*/
		.IN_EN.bit.in_en_18 = 0x1,			/*Input enabled for 5VREF*/
		.IN_EN.bit.in_en_19 = 0x1,			/*Input enabled for DI9*/
		.IN_EN.bit.in_en_20 = 0x1,			/*Input enabled for DI10*/
		.IN_EN.bit.in_en_21 = 0x0,			/*Input disabled for ResDI_10*/
		.IN_EN.bit.in_en_22 = 0x0,			/*Input disabled for ResDI_8*/
		.IN_EN.bit.in_en_23 = 0x0,			/*Input disabled for ResDI_6*/

		.CS_SELECT.bit.cs_in0 = 0x0,		/*Current Source (CSO)*/
		.CS_SELECT.bit.cs_in1 = 0x0,		/*Current Source (CSO)*/
		.CS_SELECT.bit.cs_in2 = 0x0,		/*Current Source (CSO)*/
		.CS_SELECT.bit.cs_in3 = 0x0,		/*Current Source (CSO)*/
		.CS_SELECT.bit.cs_in4 = 0x0,		/*Current Source (CSO)*/
		.CS_SELECT.bit.cs_in5 = 0x0,		/*Current Source (CSO)*/
		.CS_SELECT.bit.cs_in6 = 0x0,		/*Current Source (CSO)*/
		.CS_SELECT.bit.cs_in7 = 0x0,		/*Current Source (CSO)*/
		.CS_SELECT.bit.cs_in8 = 0x0,		/*Current Source (CSO)*/
		.CS_SELECT.bit.cs_in9 = 0x0,		/*Current Source (CSO)*/

		.WC_CFG0.bit.wc_in0_in1 = 0x0,		/*0mA wetting current ResDI_4 and ResDI_2*/
		.WC_CFG0.bit.wc_in2_in3 = 0x0,		/*0mA wetting current NTC5 and NTC6*/
		.WC_CFG0.bit.wc_in4 = 0x0, 			/*0mA wetting current NTC4*/
		.WC_CFG0.bit.wc_in5 = 0x0,			/*0mA wetting current NTC1*/
		.WC_CFG0.bit.wc_in6_in7 = 0x0,		/*0mA wetting current NTC3 and NTC2*/
		.WC_CFG0.bit.wc_in8_in9 = 0x0,		/*0mA wetting current DI1 and DI2*/
		.WC_CFG0.bit.wc_in10 = 0x0,			/*0mA wetting current DI3*/
		.WC_CFG0.bit.wc_in11 = 0x0,			/*0mA wetting current DI4*/

		.WC_CFG1.bit.wc_in12_in13 = 0x0,	/*0mA wetting current DI5 and DI6*/
		.WC_CFG1.bit.wc_in14_in15 = 0x0,	/*0mA wetting current DI7 and DI8*/
		.WC_CFG1.bit.wc_in16_in17 = 0x0,	/*0mA wetting current NC and NC*/
		.WC_CFG1.bit.wc_in18_in19 = 0x0,	/*0mA wetting current 5VREF and DI9*/
		.WC_CFG1.bit.wc_in20_in21 = 0x0,	/*0mA wetting current DI10 and ResDI_10*/
		.WC_CFG1.bit.wc_in22 = 0x0, 		/*0mA wetting current ResDI_8*/
		.WC_CFG1.bit.wc_in23 = 0x0, 		/*0mA wetting current ResDI_6*/
		.WC_CFG1.bit.auto_scale_dis_cso = 0x0, /*Enable CSO wetting current auto-scaling*/
		.WC_CFG1.bit.auto_scale_dis_csi = 0x0, /*Enable CSI wetting current auto-scaling*/

		.CCP_CFG0.bit.wc_ccp0 = 0x0,		/*10mA wetting current in CCP mode*/
		.CCP_CFG0.bit.wc_ccp1 = 0x0,		/*10mA wetting current in CCP mode*/
		.CCP_CFG0.bit.wc_ccp2 = 0x0,		/*10mA wetting current in CCP mode*/
		.CCP_CFG0.bit.wc_ccp3 = 0x0,		/*10mA wetting current in CCP mode*/
		.CCP_CFG0.bit.ccp_time = 0x0,		/*Wetting current activation time in CCP mode 64μs*/

		.CCP_CFG1.bit.ccp_in0 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in1 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in2 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in3 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in4 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in5 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in6 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in7 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in8 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in9 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in10 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in11 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in12 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in13 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in14 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in15 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in16 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in17 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in18 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in19 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in20 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in21 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in22 = 0x0,		/*No CCP wetting current*/
		.CCP_CFG1.bit.ccp_in23 = 0x0,		/*No CCP wetting current*/

		.THRES_COMP.bit.thres_comp_in0_in3 = 0x3, /*Comparator threshold set to 4 V*/
		.THRES_COMP.bit.thres_comp_in4_in7 = 0x3, /*Comparator threshold set to 4 V*/
		.THRES_COMP.bit.thres_comp_in8_in11 = 0x3, /*Comparator threshold set to 4 V*/
		.THRES_COMP.bit.thres_comp_in12_in15 = 0x3, /*Comparator threshold set to 4 V*/
		.THRES_COMP.bit.thres_comp_in16_in19 = 0x3, /*Comparator threshold set to 4 V*/
		.THRES_COMP.bit.thres_comp_in20_in23 = 0x3, /*Comparator threshold set to 4 V*/

		.INT_EN_COMP1.bit.inc_en_0 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP1.bit.inc_en_1 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP1.bit.inc_en_2 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP1.bit.inc_en_3 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP1.bit.inc_en_4 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP1.bit.inc_en_5 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP1.bit.inc_en_6 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP1.bit.inc_en_7 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP1.bit.inc_en_8 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP1.bit.inc_en_9 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP1.bit.inc_en_10 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP1.bit.inc_en_11 = 0x0,	/*No interrupt generation*/

		.INT_EN_COMP2.bit.inc_en_12 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP2.bit.inc_en_13 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP2.bit.inc_en_14 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP2.bit.inc_en_15 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP2.bit.inc_en_16 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP2.bit.inc_en_17 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP2.bit.inc_en_18 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP2.bit.inc_en_19 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP2.bit.inc_en_20 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP2.bit.inc_en_21 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP2.bit.inc_en_22 = 0x0,	/*No interrupt generation*/
		.INT_EN_COMP2.bit.inc_en_23 = 0x0,	/*No interrupt generation*/

		.INT_EN_CFG0.bit.spi_fail_en = 0x0,	/*INT pin assertion due to SPI fail event disabled*/
		.INT_EN_CFG0.bit.prty_fail_en = 0x0, /*INT pin assertion due to parity fail event disabled*/
		.INT_EN_CFG0.bit.ssc_en = 0x0,		/*INT pin assertion due to SSC event disabled*/
		.INT_EN_CFG0.bit.tsd_en = 0x0,		/*INT pin assertion due to TSD event disabled*/
		.INT_EN_CFG0.bit.tw_en = 0x0,		/*INT pin assertion due to TW event disabled*/
		.INT_EN_CFG0.bit.ov_en = 0x0,		/*INT pin assertion due to OV event disabled*/
		.INT_EN_CFG0.bit.uv_en = 0x0,		/*INT pin assertion due to UV event disabled*/
		.INT_EN_CFG0.bit.crc_calc_en = 0x0, /*INT pin assertion due to CRC calculation completion disabled*/
		.INT_EN_CFG0.bit.vs0_en = 0x0,		/*INT pin assertion due to VS0 threshold crossing disabled*/
		.INT_EN_CFG0.bit.vs1_en = 0x0,		/*INT pin assertion due to VS1 threshold crossing disabled*/
		.INT_EN_CFG0.bit.wet_diag_en = 0x0, /*INT pin assertion due to wetting current error disabled*/
		.INT_EN_CFG0.bit.adc_diag_en = 0x0, /*INT pin assertion due to ADC error disabled*/

		.INT_EN_CFG1.bit.in0_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG1.bit.in1_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG1.bit.in2_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG1.bit.in3_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG1.bit.in4_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG1.bit.in5_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG1.bit.in6_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG1.bit.in7_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG1.bit.in8_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG1.bit.in9_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG1.bit.in10_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG1.bit.in11_en = 0x0,		/*No interrupt generation*/

		.INT_EN_CFG2.bit.in12_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG2.bit.in13_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG2.bit.in14_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG2.bit.in15_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG2.bit.in16_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG2.bit.in17_en = 0x0,		/*No interrupt generation*/

		.INT_EN_CFG3.bit.in18_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG3.bit.in19_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG3.bit.in20_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG3.bit.in21_en = 0x0,		/*No interrupt generation*/

		.INT_EN_CFG4.bit.in22_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG4.bit.in23_en = 0x0,		/*No interrupt generation*/
		.INT_EN_CFG4.bit.vs_th0_en = 0x0,	/*No interrupt generation*/
		.INT_EN_CFG4.bit.vs_th1_en = 0x0,	/*No interrupt generation*/

		.THRES_CFG0.bit.thres0 = 0x0,		/*Value of threshold 0*/
		.THRES_CFG0.bit.thres1 = 0x0,		/*Value of threshold 1*/

		.THRES_CFG1.bit.thres0 = 0x0,		/*Value of threshold 2*/
		.THRES_CFG1.bit.thres1 = 0x0,		/*Value of threshold 3*/

		.THRES_CFG2.bit.thres0 = 0x0,		/*Value of threshold 4*/
		.THRES_CFG2.bit.thres1 = 0x0,		/*Value of threshold 5*/

		.THRES_CFG3.bit.thres0 = 0x0,		/*Value of threshold 6*/
		.THRES_CFG3.bit.thres1 = 0x0,		/*Value of threshold 7*/

		.THRES_CFG4.bit.thres0 = 0x0,		/*Value of threshold 8*/
		.THRES_CFG4.bit.thres1 = 0x0,		/*Value of threshold 9*/

		.THRESMAP_CFG0.bit.thresmap_in0 = 0x0, /*Thres 0*/
		.THRESMAP_CFG0.bit.thresmap_in1 = 0x0, /*Thres 0*/
		.THRESMAP_CFG0.bit.thresmap_in2 = 0x0, /*Thres 0*/
		.THRESMAP_CFG0.bit.thresmap_in3 = 0x0, /*Thres 0*/
		.THRESMAP_CFG0.bit.thresmap_in4 = 0x0, /*Thres 0*/
		.THRESMAP_CFG0.bit.thresmap_in5 = 0x0, /*Thres 0*/
		.THRESMAP_CFG0.bit.thresmap_in6 = 0x0, /*Thres 0*/
		.THRESMAP_CFG0.bit.thresmap_in7 = 0x0, /*Thres 0*/

		.THRESMAP_CFG1.bit.thresmap_in8 = 0x0, /*Thres 0*/
		.THRESMAP_CFG1.bit.thresmap_in9 = 0x0, /*Thres 0*/
		.THRESMAP_CFG1.bit.thresmap_in10 = 0x0, /*Thres 0*/
		.THRESMAP_CFG1.bit.thresmap_in11 = 0x0, /*Thres 0*/
		.THRESMAP_CFG1.bit.thresmap_in12_in17_thres2a = 0x0, /*Thres 0*/
		.THRESMAP_CFG1.bit.thresmap_in12_in17_thres2b = 0x0, /*Thres 0*/

		.THRESMAP_CFG2.bit.thresmap_in18_in23_thres3a = 0x0, /*Thres 0*/
		.THRESMAP_CFG2.bit.thresmap_in18_in23_thres3b = 0x0, /*Thres 0*/
		.THRESMAP_CFG2.bit.thresmap_in18_in23_thres3c = 0x0, /*Thres 0*/
		.THRESMAP_CFG2.bit.thresmap_vs0_thres2a = 0x0, /*Thres 0*/
		.THRESMAP_CFG2.bit.thresmap_vs0_thres2b = 0x0, /*Thres 0*/
		.THRESMAP_CFG2.bit.thresmap_vs1_thres2a = 0x0, /*Thres 0*/
		.THRESMAP_CFG2.bit.thresmap_vs1_thres2b = 0x0, /*Thres 0*/

		.MATRIX.bit.poll_act_time_m = 0x0,	/*Polling active time 64μs*/
		.MATRIX.bit.matrix = 0x0,			/*No matrix, regular inputs only*/
		.MATRIX.bit.thres_com = 0x0,		/*Value of threshold*/
		.MATRIX.bit.in_com_en = 0x0,		/*No interrupt generation for w.r.t. threshold*/

		.MODE.bit.m_in0 = 0x0,				/*Comparator mode for ResDI_4*/
		.MODE.bit.m_in1 = 0x0,				/*Comparator mode for ResDI_2*/
		.MODE.bit.m_in2 = 0x1,				/*ADC mode for NTC5*/
		.MODE.bit.m_in3 = 0x1,				/*ADC mode for NTC6*/
		.MODE.bit.m_in4 = 0x1,				/*ADC mode for NTC4*/
		.MODE.bit.m_in5 = 0x1,				/*ADC mode for NTC1*/
		.MODE.bit.m_in6 = 0x1,				/*ADC mode for NTC3*/
		.MODE.bit.m_in7 = 0x1,				/*ADC mode for NTC2*/
		.MODE.bit.m_in8 = 0x0,				/*Comparator mode for DI1*/
		.MODE.bit.m_in9 = 0x0,				/*Comparator mode for DI2*/
		.MODE.bit.m_in10 = 0x0,				/*Comparator mode for DI3*/
		.MODE.bit.m_in11 = 0x0,				/*Comparator mode for DI4*/
		.MODE.bit.m_in12 = 0x0,				/*Comparator mode for DI5*/
		.MODE.bit.m_in13 = 0x0,				/*Comparator mode for DI6*/
		.MODE.bit.m_in14 = 0x0,				/*Comparator mode for DI7*/
		.MODE.bit.m_in15 = 0x0,				/*Comparator mode for DI8*/
		.MODE.bit.m_in16 = 0x0,				/*Comparator mode for NC*/
		.MODE.bit.m_in17 = 0x0,				/*Comparator mode for NC*/
		.MODE.bit.m_in18 = 0x1,				/*ADC mode for 5VREF*/
		.MODE.bit.m_in19 = 0x0,				/*Comparator mode for DI9*/
		.MODE.bit.m_in20 = 0x0,				/*Comparator mode for DI10*/
		.MODE.bit.m_in21 = 0x0,				/*Comparator mode for ResDI_10*/
		.MODE.bit.m_in22 = 0x0,				/*Comparator mode for ResDI_8*/
		.MODE.bit.m_in23 = 0x0				/*Comparator mode for ResDI_6*/
};

#define TIC124_TX_FRAME_FILL(FRAME,ADDR)\
		FRAME[TIC12400_##ADDR].bit.rw = 0;\
		FRAME[TIC12400_##ADDR].bit.addr = TIC12400_##ADDR;\
		FRAME[TIC12400_##ADDR].bit.data = 0;\
		FRAME[TIC12400_##ADDR].bit.par = calc_parity(FRAME[TIC12400_##ADDR].all, 32, PARITY_ODD)

#define TIC124_SETTINGS_TX_FRAME_FILL(FRAME,CFG,ADDR)\
		FRAME[TIC12400_##ADDR].bit.rw = 1;\
		FRAME[TIC12400_##ADDR].bit.addr = TIC12400_##ADDR;\
		FRAME[TIC12400_##ADDR].bit.data = CFG.ADDR.all;\
		FRAME[TIC12400_##ADDR].bit.par = calc_parity(FRAME[TIC12400_##ADDR].all, 32, PARITY_ODD)

void tic124_tx_frame_fill(void) {
	TIC124_TX_FRAME_FILL(tic124_tx_frame,RESERVED0);

	TIC124_TX_FRAME_FILL(tic124_tx_frame,DEVICE_ID);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,INT_STAT);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,CRC);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,IN_STAT_MISC);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,IN_STAT_COMP);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,IN_STAT_ADC0);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,IN_STAT_ADC1);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,IN_STAT_MATRIX0);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,IN_STAT_MATRIX1);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,ANA_STAT0);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,ANA_STAT1);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,ANA_STAT2);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,ANA_STAT3);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,ANA_STAT4);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,ANA_STAT5);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,ANA_STAT6);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,ANA_STAT7);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,ANA_STAT8);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,ANA_STAT9);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,ANA_STAT10);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,ANA_STAT11);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,ANA_STAT12);

	TIC124_TX_FRAME_FILL(tic124_tx_frame,RESERVED23);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,RESERVED24);
	TIC124_TX_FRAME_FILL(tic124_tx_frame,RESERVED25);

	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,CONFIG);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,IN_EN);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,CS_SELECT);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,WC_CFG0);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,WC_CFG1);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,CCP_CFG0);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,CCP_CFG1);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,THRES_COMP);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,INT_EN_COMP1);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,INT_EN_COMP2);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,INT_EN_CFG0);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,INT_EN_CFG1);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,INT_EN_CFG2);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,INT_EN_CFG3);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,INT_EN_CFG4);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,THRES_CFG0);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,THRES_CFG1);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,THRES_CFG2);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,THRES_CFG3);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,THRES_CFG4);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,THRESMAP_CFG0);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,THRESMAP_CFG1);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,THRESMAP_CFG2);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,MATRIX);
	TIC124_SETTINGS_TX_FRAME_FILL(tic124_tx_frame,tic124_settings_const,MODE);
}


SPI_BUS_DATA_TypeDef tic124_spi_bus_data_control_array[TIC12400_FRAME_COUNT];

void tic124_spi_bus_data_control_array_fill(void) {
	for(int i = 0; i < TIC12400_FRAME_COUNT; i++) {
		tic124_spi_bus_data_control_array[i].tx = (uint8_t*)&tic124_tx_frame[i].all;
		tic124_spi_bus_data_control_array[i].rx = (uint8_t*)&tic124_rx_frame[i].all;
		tic124_spi_bus_data_control_array[i].count = 4;
	}
}

void tic12400_configure(SPI_BUS_TypeDef* spi_bus) {
	spi_bus_transfer(spi_bus, &tic124_spi_bus_data_control_array[TIC12400_CONFIG], 25, SPI_BYTE_ORDER_REVERSE);
}

void tic124_start_normal_operation(SPI_BUS_TypeDef* spi_bus) {
	while(spi_bus->done == false);

	TIC12400_CONFIG_REG config;
	//чтение настроек
	config.all = tic124_settings_const.CONFIG.all;
	//изменение настроек
	config.bit.poll_en = 0x1; /*Polling enabled*/ //Нужно ли?
	config.bit.trigger = 0x1; /*Start TIC12400-Q1 to normal operation*/

	//формирование фрейма
	tic124_tx_frame[TIC12400_CONFIG].bit.rw = 1;
	tic124_tx_frame[TIC12400_CONFIG].bit.addr = TIC12400_CONFIG;
	tic124_tx_frame[TIC12400_CONFIG].bit.data = config.all;
	//сброс четности
	tic124_tx_frame[TIC12400_CONFIG].bit.par = 0;
	//расчет четности
	tic124_tx_frame[TIC12400_CONFIG].bit.par = calc_parity(tic124_tx_frame[TIC12400_CONFIG].all, 32, PARITY_ODD);
	//старт приема/передачи
	spi_bus_transfer(spi_bus, &tic124_spi_bus_data_control_array[TIC12400_CONFIG], 1, SPI_BYTE_ORDER_REVERSE);
}

void tic12400_stat_read(SPI_BUS_TypeDef* spi_bus, uint8_t* digital_input_10, uint16_t* analog_input_6) {
	spi_bus_transfer(spi_bus, &tic124_spi_bus_data_control_array[TIC12400_IN_STAT_COMP], 1, SPI_BYTE_ORDER_REVERSE);
	spi_bus_transfer(spi_bus, &tic124_spi_bus_data_control_array[TIC12400_ANA_STAT1], 3, SPI_BYTE_ORDER_REVERSE);
	while(spi_bus->done == false);

	TIC12400_IN_STAT_COMP_REG in_stat_comp;

	in_stat_comp.all = tic124_rx_frame[TIC12400_IN_STAT_COMP].bit.data;

	digital_input_10[0] = in_stat_comp.bit.inc_8;	//DI1
	digital_input_10[1] = in_stat_comp.bit.inc_9;	//DI2
	digital_input_10[2] = in_stat_comp.bit.inc_10;	//DI3
	digital_input_10[3] = in_stat_comp.bit.inc_11;	//DI4
	digital_input_10[4] = in_stat_comp.bit.inc_12;	//DI5
	digital_input_10[5] = in_stat_comp.bit.inc_13;	//DI6
	digital_input_10[6] = in_stat_comp.bit.inc_14;	//DI7
	digital_input_10[7] = in_stat_comp.bit.inc_15;	//DI8
	digital_input_10[8] = in_stat_comp.bit.inc_19;	//DI9
	digital_input_10[9] = in_stat_comp.bit.inc_20;	//DI10

	TIC12400_ANA_STAT_REG ana_stat;

	ana_stat.all = tic124_rx_frame[TIC12400_ANA_STAT1].bit.data;
	analog_input_6[0] = ana_stat.bit.in0_ana;	//NTC5
	analog_input_6[1] = ana_stat.bit.in1_ana;	//NTC6

	ana_stat.all = tic124_rx_frame[TIC12400_ANA_STAT2].bit.data;
	analog_input_6[2] = ana_stat.bit.in0_ana;	//NTC4
	analog_input_6[3] = ana_stat.bit.in1_ana;	//NTC1

	ana_stat.all = tic124_rx_frame[TIC12400_ANA_STAT3].bit.data;
	analog_input_6[4] = ana_stat.bit.in0_ana;	//NTC3
	analog_input_6[5] = ana_stat.bit.in1_ana;	//NTC2
}




