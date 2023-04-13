/*
 * init.c
 *
 *  Created on: 31 авг. 2022 г.
 *      Author: Ruslan
 */

#include "init.h"

void rcc_init(void) {
	//TIM2
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	//TIM5
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;

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

	//SPI2
	RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
	//SPI4
	RCC->APB2ENR |= RCC_APB2ENR_SPI4EN;
	//SPI5
	RCC->APB2ENR |= RCC_APB2ENR_SPI5EN;
}

void nvic_init(void) {
	NVIC_SetPriorityGrouping(0b000);

	NVIC_SetPriority(TIM2_IRQn, 7);
	NVIC_EnableIRQ(TIM2_IRQn);

	NVIC_SetPriority(TIM5_IRQn, 7);
	NVIC_EnableIRQ(TIM5_IRQn);

	NVIC_SetPriority(SPI2_IRQn, 8);
	NVIC_EnableIRQ(SPI2_IRQn);

	NVIC_SetPriority(SPI4_IRQn, 8);
	NVIC_EnableIRQ(SPI4_IRQn);
}

void system_timer_init(void) {
	sys_timer_init(TIM2);
	sys_timer_irq_enable();
	sys_timer_start();
}

void gpio_init(void) {
	gpio_pins_cfg_setup(gpio_init_array, GPIO_INIT_PINS_COUNT);
}
