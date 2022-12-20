#include "init.h"
#include "gpio.h"
#include "spi.h"
#include "parity.h"
#include "tic12400.h"
#include "tic12400_settings.h"
#include "b57891s0103f008.h"
#include "ncv7608.h"

gpio_pin_t bgr_led[3] = {
		GPIO_PIN(GPIOH, GPIO_PIN_10),
		GPIO_PIN(GPIOH, GPIO_PIN_11),
		GPIO_PIN(GPIOH, GPIO_PIN_12)
};

void TIM2_IRQHandler() {
	sys_timer_irq_handler();
}

const CFG_REG_SPI_TypeDef spi_tic12400_cfg = SPI_CFG(
		SPI_CPHA_SECOND,
		SPI_CPOL_IDLE_LOW,
		SPI_MSTR_MASTER,
		SPI_BR_FPCLK_32,
		SPI_LSBFIRST_MSB_FIRST,
		SPI_SSI_NSEL,
		SPI_SSM_ENA,
		SPI_RXONLY_DIS,
		SPI_DFF_8,
		SPI_CRCEN_DIS,
		SPI_BIDIOE_RX,
		SPI_BIDIMODE_UNIDIR,
		SPI_RXDMAEN_DIS,
		SPI_TXDMAEN_DIS,
		SPI_SSOE_DIS,
		SPI_FRF_MOTOROLA,
		SPI_ERRIE_DIS,
		GPO_CS_DI_App,
		1,
		1,
		3);

const CFG_REG_SPI_TypeDef spi_ncv7608_cfg = SPI_CFG(
		SPI_CPHA_SECOND,
		SPI_CPOL_IDLE_LOW,
		SPI_MSTR_MASTER,
		SPI_BR_FPCLK_128,
		SPI_LSBFIRST_LSB_FIRST,
		SPI_SSI_NSEL,
		SPI_SSM_ENA,
		SPI_RXONLY_DIS,
		SPI_DFF_8,
		SPI_CRCEN_DIS,
		SPI_BIDIOE_RX,
		SPI_BIDIMODE_UNIDIR,
		SPI_RXDMAEN_DIS,
		SPI_TXDMAEN_DIS,
		SPI_SSOE_DIS,
		SPI_FRF_MOTOROLA,
		SPI_ERRIE_DIS,
		GPO_CS_DO_App,
		1,
		1,
		3);

/*
const CFG_REG_SPI_TypeDef spi_spi5_cfg = SPI_CFG(
		SPI_CPHA_SECOND,
		SPI_CPOL_IDLE_LOW,
		SPI_MSTR_MASTER,
		SPI_BR_FPCLK_64,
		SPI_LSBFIRST_MSB_FIRST,
		SPI_SSI_NSEL,
		SPI_SSM_ENA,
		SPI_RXONLY_DIS,
		SPI_DFF_8,
		SPI_CRCEN_DIS,
		SPI_BIDIOE_RX,
		SPI_BIDIMODE_UNIDIR,
		SPI_RXDMAEN_DIS,
		SPI_TXDMAEN_DIS,
		SPI_SSOE_DIS,
		SPI_FRF_MOTOROLA,
		SPI_ERRIE_DIS,
		GPO_CS_SPI5_App,
		1,
		1,
		1);
*/

SPI_BUS_TypeDef SPI_DIO_Bus;

SPI_BUS_DATA_TypeDef tic124_spi_bus_data_control_array[TIC12400_FRAME_COUNT];

void tic124_spi_bus_data_control_array_fill(void) {
	for(int i = 0; i < TIC12400_FRAME_COUNT; i++) {
		tic124_spi_bus_data_control_array[i].tx = (uint8_t*)&tic124_tx_frame[i].all;
		tic124_spi_bus_data_control_array[i].rx = (uint8_t*)&tic124_rx_frame[i].all;
		tic124_spi_bus_data_control_array[i].count = 4;
	}
}

void tic124_start_normal_operation(void) {
	while(SPI_DIO_Bus.done == false);

	TIC12400_CONFIG_REG config;
	//чтение настроек
	config.all = tic124_settings_const.CONFIG.all;
	//изменение настроек
	config.bit.poll_en = 0x1; /*Polling enabled*/
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
	spi_bus_transfer(&SPI_DIO_Bus, &tic124_spi_bus_data_control_array[TIC12400_CONFIG], 1, SPI_BYTE_ORDER_REVERSE);
}

void SPI4_IRQHandler() {
	SPI_BUS_IRQHandler(&SPI_DIO_Bus);
}

uint8_t tic12400_digital_input[10];
uint16_t tic12400_analog_input[6];

void tic12400_stat_read() {
	spi_bus_transfer(&SPI_DIO_Bus, &tic124_spi_bus_data_control_array[TIC12400_IN_STAT_COMP], 1, SPI_BYTE_ORDER_REVERSE);
	spi_bus_transfer(&SPI_DIO_Bus, &tic124_spi_bus_data_control_array[TIC12400_ANA_STAT1], 3, SPI_BYTE_ORDER_REVERSE);
	while(SPI_DIO_Bus.done == false);

	TIC12400_IN_STAT_COMP_REG in_stat_comp;

	in_stat_comp.all = tic124_rx_frame[TIC12400_IN_STAT_COMP].bit.data;

	tic12400_digital_input[0] = in_stat_comp.bit.inc_8;		//DI1
	tic12400_digital_input[1] = in_stat_comp.bit.inc_9;		//DI2
	tic12400_digital_input[2] = in_stat_comp.bit.inc_10;	//DI3
	tic12400_digital_input[3] = in_stat_comp.bit.inc_11;	//DI4
	tic12400_digital_input[4] = in_stat_comp.bit.inc_12;	//DI5
	tic12400_digital_input[5] = in_stat_comp.bit.inc_13;	//DI6
	tic12400_digital_input[6] = in_stat_comp.bit.inc_14;	//DI7
	tic12400_digital_input[7] = in_stat_comp.bit.inc_15;	//DI8
	tic12400_digital_input[8] = in_stat_comp.bit.inc_19;	//DI9
	tic12400_digital_input[9] = in_stat_comp.bit.inc_20;	//DI10

	TIC12400_ANA_STAT_REG ana_stat;

	ana_stat.all = tic124_rx_frame[TIC12400_ANA_STAT1].bit.data;
	tic12400_analog_input[0] = ana_stat.bit.in0_ana;	//NTC5
	tic12400_analog_input[1] = ana_stat.bit.in1_ana;	//NTC6

	ana_stat.all = tic124_rx_frame[TIC12400_ANA_STAT2].bit.data;
	tic12400_analog_input[2] = ana_stat.bit.in0_ana;	//NTC4
	tic12400_analog_input[3] = ana_stat.bit.in1_ana;	//NTC1

	ana_stat.all = tic124_rx_frame[TIC12400_ANA_STAT3].bit.data;
	tic12400_analog_input[4] = ana_stat.bit.in0_ana;	//NTC3
	tic12400_analog_input[5] = ana_stat.bit.in1_ana;	//NTC2
}

NCV7608_INPUT_DATA_REG ncv7608_tx;
NCV7608_OUTPUT_DATA_REG ncv7608_rx;
SPI_BUS_DATA_TypeDef ncv7608_spi_bus_data_control_array = {
		.tx = (uint8_t*)&ncv7608_tx.all,
		.rx = (uint8_t*)&ncv7608_rx.all,
		.count = 2
};

int main(void) {
	rcc_init();
	nvic_init();
	system_timer_init();
	gpio_init();

	spi_bus_init(&SPI_DIO_Bus, SPI4);
	spi_bus_configure(&SPI_DIO_Bus, &spi_ncv7608_cfg);

	/*
	spi_bus_configure(&SPI_DIO_Bus, &spi_tic12400_cfg);

	//сброс tic12400
	sys_timer_delay(1, 0);
	gpio_output_bit_setup(&GPO_Reset_DI_App, GPIO_STATE_ON);
	sys_timer_delay(1, 0);
	gpio_output_bit_setup(&GPO_Reset_DI_App, GPIO_STATE_OFF);
	sys_timer_delay(1, 0);

	tic124_tx_frame_fill();

	tic124_spi_bus_data_control_array_fill();

	spi_bus_transfer(&SPI_DIO_Bus, &tic124_spi_bus_data_control_array[TIC12400_CONFIG], 25, SPI_BYTE_ORDER_REVERSE);

	spi_bus_transfer(&SPI_DIO_Bus, &tic124_spi_bus_data_control_array[TIC12400_CONFIG], 25, SPI_BYTE_ORDER_REVERSE);

	tic124_start_normal_operation();

	tic12400_stat_read();
	*/

	while(1) {
		ncv7608_tx.bit.driver_2_ena = ncv7608_tx.bit.driver_1_ena;
		ncv7608_tx.bit.driver_1_ena = ncv7608_tx.bit.driver_3_ena;
		ncv7608_tx.bit.driver_3_ena = ncv7608_tx.bit.driver_4_ena;
		ncv7608_tx.bit.driver_4_ena = ncv7608_tx.bit.driver_8_ena;
		ncv7608_tx.bit.driver_8_ena = ncv7608_tx.bit.driver_7_ena;
		ncv7608_tx.bit.driver_7_ena = ncv7608_tx.bit.driver_5_ena;
		ncv7608_tx.bit.driver_5_ena = ncv7608_tx.bit.driver_6_ena;
		ncv7608_tx.bit.driver_6_ena = !ncv7608_tx.bit.driver_2_ena;
		spi_bus_transfer(&SPI_DIO_Bus, &ncv7608_spi_bus_data_control_array, 1, SPI_BYTE_ORDER_NORMAL);
		sys_timer_delay(0, 100000);
	}
	return 0;
}
