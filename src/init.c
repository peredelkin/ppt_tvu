/*
 * init.c
 *
 *  Created on: 31 авг. 2022 г.
 *      Author: Ruslan
 */

#include "init.h"

void rcc_init(void) {
	//GPIO
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOKEN;

	//SPI4
	RCC->APB2ENR |= RCC_APB2ENR_SPI4EN;
	//SPI5
	RCC->APB2ENR |= RCC_APB2ENR_SPI5EN;
}

void gpio_preinit(void) {
	//TODO: добавить инит по умолчанию выходных пинов
}

void gpio_init(void) {
	gpio_pins_cfg_setup(gpio_init_array, GPIO_INIT_PINS_COUNT);
}
