#include "init.h"
#include "gpio.h"
#include "spi.h"
#include "parity.h"
#include "tic12400.h"

const CFG_BITS_SPI_TypeDef spi_tic12400_cfg = SPI_CFG(
		SPI_CPHA_SECOND,
		SPI_CPOL_IDLE_LOW,
		SPI_MSTR_MASTER,
		SPI_BR_FPCLK_128,
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
		SPI_RXNEIE_DIS,
		SPI_TXEIE_DIS);

//GPIO DI
const gpio_pin_t spi_di_int = GPIO_PIN(GPIOI, GPIO_PIN_10); /*12, PI10, GPIO_Input, Int_DI_App*/
const gpio_pin_t spi_di_rst = GPIO_PIN(GPIOI, GPIO_PIN_9); /*11, PI9, GPIO_Output, Reset_DI_App*/
const gpio_pin_t spi_di_cs = GPIO_PIN(GPIOI, GPIO_PIN_8); /*7, PI8, GPIO_Output, CS_DI_App*/
//GPIO DO
const gpio_pin_t spi_do_en = GPIO_PIN(GPIOA, GPIO_PIN_0); /*40, PA0/WKUP, GPIO_Output, EN_DO_App*/
const gpio_pin_t spi_do_cs = GPIO_PIN(GPIOE, GPIO_PIN_4); /*3, PE4, SPI4_NSS, CS_DO_App*/

void spi_tic12400_exchange_test() {
	TIC12400_TX_FRAME tx_data;
	tx_data.bit.rw = 0;
	tx_data.bit.addr = TIC12400_DEVICE_ID;
	tx_data.bit.data = 0;
	tx_data.bit.par = calc_parity(tx_data.all, 32, PARITY_ODD);

	TIC12400_RX_FRAME rx_data;

	SPI4->CR1 |= SPI_CR1_SPE;

	gpio_output_bit_setup(&spi_di_cs, GPIO_STATE_OFF);

	uint8_t data_n;
	for(data_n = 4; data_n ; data_n--) {
		while(!(SPI4->SR & SPI_SR_TXE));
		SPI4->DR = tx_data.byte[data_n-1];
		while(!(SPI4->SR & SPI_SR_RXNE));
		rx_data.byte[data_n-1] = SPI4->DR;
	}

	gpio_output_bit_setup(&spi_di_cs, GPIO_STATE_ON);

	SPI4->CR1 &= ~SPI_CR1_SPE;

	TIC12400_DEVICE_ID_REG id;
	id.all = rx_data.bit.data;

}

void gpio_state() {
	//DI
	gpio_output_bit_setup(&spi_di_cs, GPIO_STATE_ON);
	gpio_output_bit_setup(&spi_di_rst, GPIO_STATE_OFF);
	//DO
	gpio_output_bit_setup(&spi_do_en, GPIO_STATE_OFF);
	gpio_output_bit_setup(&spi_do_cs, GPIO_STATE_ON);
}

int main(void) {
	rcc_init();
	gpio_state();
	gpio_init();
	spi_cfg_setup(SPI4, &spi_tic12400_cfg);
	spi_tic12400_exchange_test();
	while(1);
	return 0;
}
