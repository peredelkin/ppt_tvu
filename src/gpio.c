/*
 * gpio.c
 *
 *  Created on: 8 авг. 2022 г.
 *      Author: ruslan
 */

#include "gpio.h"

void gpio_mode_bit_setup(GPIO_TypeDef *gpio, gpio_pin_t pin_n, gpio_mode_t pin_mode);
void gpio_output_type_bit_setup(GPIO_TypeDef *gpio, gpio_pin_t pin_n, gpio_otype_t pin_otype);
void gpio_output_speed_bit_setup(GPIO_TypeDef *gpio, gpio_pin_t pin_n, gpio_ospeed_t pin_ospeed);
void gpio_pull_updown_bit_setup(GPIO_TypeDef *gpio, gpio_pin_t pin_n, gpio_pupd_t pin_pupd);
bool gpio_input_data_bit_read(GPIO_TypeDef *gpio, gpio_pin_t pin_n);
bool gpio_output_data_bit_read(GPIO_TypeDef *gpio, gpio_pin_t pin_n);
void gpio_output_data_bit_setup(GPIO_TypeDef *gpio, gpio_pin_t pin_n, uint8_t pin_data);
void gpio_alternate_function_bit_setup(GPIO_TypeDef *gpio, gpio_pin_t pin_n, gpio_af_t pin_altf);

void gpio_pin_setup(GPIO_TypeDef *gpio,
		gpio_pin_t pin_n,
		gpio_mode_t pin_mode,
		gpio_otype_t pin_otype,
		gpio_ospeed_t pin_ospeed,
		gpio_pupd_t pin_pupd,
		gpio_af_t pin_altf)
{
	gpio_mode_bit_setup(gpio, pin_n, pin_mode);
	gpio_output_type_bit_setup(gpio, pin_n, pin_otype);
	gpio_output_speed_bit_setup(gpio, pin_n, pin_ospeed);
	gpio_pull_updown_bit_setup(gpio, pin_n, pin_pupd);
	gpio_alternate_function_bit_setup(gpio, pin_n, pin_altf);
}

void gpio_mode_bit_setup(GPIO_TypeDef *gpio, gpio_pin_t pin_n, gpio_mode_t pin_mode) {

	BITS_GPIO_TypeDef *gpio_bits = (BITS_GPIO_TypeDef*) gpio;

	switch (pin_n) {
	case 0:
		gpio_bits->MODER.bit.MODER0 = pin_mode;
		break;
	case 1:
		gpio_bits->MODER.bit.MODER1 = pin_mode;
		break;
	case 2:
		gpio_bits->MODER.bit.MODER2 = pin_mode;
		break;
	case 3:
		gpio_bits->MODER.bit.MODER3 = pin_mode;
		break;
	case 4:
		gpio_bits->MODER.bit.MODER4 = pin_mode;
		break;
	case 5:
		gpio_bits->MODER.bit.MODER5 = pin_mode;
		break;
	case 6:
		gpio_bits->MODER.bit.MODER6 = pin_mode;
		break;
	case 7:
		gpio_bits->MODER.bit.MODER7 = pin_mode;
		break;
	case 8:
		gpio_bits->MODER.bit.MODER8 = pin_mode;
		break;
	case 9:
		gpio_bits->MODER.bit.MODER9 = pin_mode;
		break;
	case 10:
		gpio_bits->MODER.bit.MODER10 = pin_mode;
		break;
	case 11:
		gpio_bits->MODER.bit.MODER11 = pin_mode;
		break;
	case 12:
		gpio_bits->MODER.bit.MODER12 = pin_mode;
		break;
	case 13:
		gpio_bits->MODER.bit.MODER13 = pin_mode;
		break;
	case 14:
		gpio_bits->MODER.bit.MODER14 = pin_mode;
		break;
	case 15:
		gpio_bits->MODER.bit.MODER15 = pin_mode;
		break;
	default:
		break;
	}
}

void gpio_output_type_bit_setup(GPIO_TypeDef *gpio, gpio_pin_t pin_n,
		gpio_otype_t pin_otype) {

	BITS_GPIO_TypeDef *gpio_bits = (BITS_GPIO_TypeDef*) gpio;

	switch (pin_n) {
	case 0:
		gpio_bits->OTYPER.bit.OT0 = pin_otype;
		break;
	case 1:
		gpio_bits->OTYPER.bit.OT1 = pin_otype;
		break;
	case 2:
		gpio_bits->OTYPER.bit.OT2 = pin_otype;
		break;
	case 3:
		gpio_bits->OTYPER.bit.OT3 = pin_otype;
		break;
	case 4:
		gpio_bits->OTYPER.bit.OT4 = pin_otype;
		break;
	case 5:
		gpio_bits->OTYPER.bit.OT5 = pin_otype;
		break;
	case 6:
		gpio_bits->OTYPER.bit.OT6 = pin_otype;
		break;
	case 7:
		gpio_bits->OTYPER.bit.OT7 = pin_otype;
		break;
	case 8:
		gpio_bits->OTYPER.bit.OT8 = pin_otype;
		break;
	case 9:
		gpio_bits->OTYPER.bit.OT9 = pin_otype;
		break;
	case 10:
		gpio_bits->OTYPER.bit.OT10 = pin_otype;
		break;
	case 11:
		gpio_bits->OTYPER.bit.OT11 = pin_otype;
		break;
	case 12:
		gpio_bits->OTYPER.bit.OT12 = pin_otype;
		break;
	case 13:
		gpio_bits->OTYPER.bit.OT13 = pin_otype;
		break;
	case 14:
		gpio_bits->OTYPER.bit.OT14 = pin_otype;
		break;
	case 15:
		gpio_bits->OTYPER.bit.OT15 = pin_otype;
		break;
	default:
		break;
	}
}

void gpio_output_speed_bit_setup(GPIO_TypeDef *gpio, gpio_pin_t pin_n,
		gpio_ospeed_t pin_ospeed) {

	BITS_GPIO_TypeDef *gpio_bits = (BITS_GPIO_TypeDef*) gpio;

	switch (pin_n) {
	case 0:
		gpio_bits->OSPEEDR.bit.OSPEEDR0 = pin_ospeed;
		break;
	case 1:
		gpio_bits->OSPEEDR.bit.OSPEEDR1 = pin_ospeed;
		break;
	case 2:
		gpio_bits->OSPEEDR.bit.OSPEEDR2 = pin_ospeed;
		break;
	case 3:
		gpio_bits->OSPEEDR.bit.OSPEEDR3 = pin_ospeed;
		break;
	case 4:
		gpio_bits->OSPEEDR.bit.OSPEEDR4 = pin_ospeed;
		break;
	case 5:
		gpio_bits->OSPEEDR.bit.OSPEEDR5 = pin_ospeed;
		break;
	case 6:
		gpio_bits->OSPEEDR.bit.OSPEEDR6 = pin_ospeed;
		break;
	case 7:
		gpio_bits->OSPEEDR.bit.OSPEEDR7 = pin_ospeed;
		break;
	case 8:
		gpio_bits->OSPEEDR.bit.OSPEEDR8 = pin_ospeed;
		break;
	case 9:
		gpio_bits->OSPEEDR.bit.OSPEEDR9 = pin_ospeed;
		break;
	case 10:
		gpio_bits->OSPEEDR.bit.OSPEEDR10 = pin_ospeed;
		break;
	case 11:
		gpio_bits->OSPEEDR.bit.OSPEEDR11 = pin_ospeed;
		break;
	case 12:
		gpio_bits->OSPEEDR.bit.OSPEEDR12 = pin_ospeed;
		break;
	case 13:
		gpio_bits->OSPEEDR.bit.OSPEEDR13 = pin_ospeed;
		break;
	case 14:
		gpio_bits->OSPEEDR.bit.OSPEEDR14 = pin_ospeed;
		break;
	case 15:
		gpio_bits->OSPEEDR.bit.OSPEEDR15 = pin_ospeed;
		break;
	default:
		break;
	}
}

void gpio_pull_updown_bit_setup(GPIO_TypeDef *gpio, gpio_pin_t pin_n,
		gpio_pupd_t pin_pupd) {

	BITS_GPIO_TypeDef *gpio_bits = (BITS_GPIO_TypeDef*) gpio;

	switch (pin_n) {
	case 0:
		gpio_bits->PUPDR.bit.PUPDR0 = pin_pupd;
		break;
	case 1:
		gpio_bits->PUPDR.bit.PUPDR1 = pin_pupd;
		break;
	case 2:
		gpio_bits->PUPDR.bit.PUPDR2 = pin_pupd;
		break;
	case 3:
		gpio_bits->PUPDR.bit.PUPDR3 = pin_pupd;
		break;
	case 4:
		gpio_bits->PUPDR.bit.PUPDR4 = pin_pupd;
		break;
	case 5:
		gpio_bits->PUPDR.bit.PUPDR5 = pin_pupd;
		break;
	case 6:
		gpio_bits->PUPDR.bit.PUPDR6 = pin_pupd;
		break;
	case 7:
		gpio_bits->PUPDR.bit.PUPDR7 = pin_pupd;
		break;
	case 8:
		gpio_bits->PUPDR.bit.PUPDR8 = pin_pupd;
		break;
	case 9:
		gpio_bits->PUPDR.bit.PUPDR9 = pin_pupd;
		break;
	case 10:
		gpio_bits->PUPDR.bit.PUPDR10 = pin_pupd;
		break;
	case 11:
		gpio_bits->PUPDR.bit.PUPDR11 = pin_pupd;
		break;
	case 12:
		gpio_bits->PUPDR.bit.PUPDR12 = pin_pupd;
		break;
	case 13:
		gpio_bits->PUPDR.bit.PUPDR13 = pin_pupd;
		break;
	case 14:
		gpio_bits->PUPDR.bit.PUPDR14 = pin_pupd;
		break;
	case 15:
		gpio_bits->PUPDR.bit.PUPDR15 = pin_pupd;
		break;
	default:
		break;
	}
}

bool gpio_input_data_bit_read(GPIO_TypeDef *gpio, gpio_pin_t pin_n) {

	BITS_GPIO_TypeDef *gpio_bits = (BITS_GPIO_TypeDef*) gpio;

	switch (pin_n) {
	case 0:
		return (bool) (gpio_bits->IDR.bit.IDR0);
	case 1:
		return (bool) (gpio_bits->IDR.bit.IDR1);
	case 2:
		return (bool) (gpio_bits->IDR.bit.IDR2);
	case 3:
		return (bool) (gpio_bits->IDR.bit.IDR3);
	case 4:
		return (bool) (gpio_bits->IDR.bit.IDR4);
	case 5:
		return (bool) (gpio_bits->IDR.bit.IDR5);
	case 6:
		return (bool) (gpio_bits->IDR.bit.IDR6);
	case 7:
		return (bool) (gpio_bits->IDR.bit.IDR7);
	case 8:
		return (bool) (gpio_bits->IDR.bit.IDR8);
	case 9:
		return (bool) (gpio_bits->IDR.bit.IDR9);
	case 10:
		return (bool) (gpio_bits->IDR.bit.IDR10);
	case 11:
		return (bool) (gpio_bits->IDR.bit.IDR11);
	case 12:
		return (bool) (gpio_bits->IDR.bit.IDR12);
	case 13:
		return (bool) (gpio_bits->IDR.bit.IDR13);
	case 14:
		return (bool) (gpio_bits->IDR.bit.IDR14);
	case 15:
		return (bool) (gpio_bits->IDR.bit.IDR15);
	default:
		return false;
	}
}

bool gpio_output_data_bit_read(GPIO_TypeDef *gpio, gpio_pin_t pin_n) {

	BITS_GPIO_TypeDef *gpio_bits = (BITS_GPIO_TypeDef*) gpio;

	switch (pin_n) {
	case 0:
		return (bool) (gpio_bits->ODR.bit.ODR0);
	case 1:
		return (bool) (gpio_bits->ODR.bit.ODR1);
	case 2:
		return (bool) (gpio_bits->ODR.bit.ODR2);
	case 3:
		return (bool) (gpio_bits->ODR.bit.ODR3);
	case 4:
		return (bool) (gpio_bits->ODR.bit.ODR4);
	case 5:
		return (bool) (gpio_bits->ODR.bit.ODR5);
	case 6:
		return (bool) (gpio_bits->ODR.bit.ODR6);
	case 7:
		return (bool) (gpio_bits->ODR.bit.ODR7);
	case 8:
		return (bool) (gpio_bits->ODR.bit.ODR8);
	case 9:
		return (bool) (gpio_bits->ODR.bit.ODR9);
	case 10:
		return (bool) (gpio_bits->ODR.bit.ODR10);
	case 11:
		return (bool) (gpio_bits->ODR.bit.ODR11);
	case 12:
		return (bool) (gpio_bits->ODR.bit.ODR12);
	case 13:
		return (bool) (gpio_bits->ODR.bit.ODR13);
	case 14:
		return (bool) (gpio_bits->ODR.bit.ODR14);
	case 15:
		return (bool) (gpio_bits->ODR.bit.ODR15);
	default:
		return false;
	}
}

void gpio_output_data_bit_setup(GPIO_TypeDef *gpio, gpio_pin_t pin_n,
		uint8_t pin_data) {

	BITS_GPIO_TypeDef *gpio_bits = (BITS_GPIO_TypeDef*) gpio;

	switch (pin_n) {
	case 0:
		gpio_bits->ODR.bit.ODR0 = pin_data;
		break;
	case 1:
		gpio_bits->ODR.bit.ODR1 = pin_data;
		break;
	case 2:
		gpio_bits->ODR.bit.ODR2 = pin_data;
		break;
	case 3:
		gpio_bits->ODR.bit.ODR3 = pin_data;
		break;
	case 4:
		gpio_bits->ODR.bit.ODR4 = pin_data;
		break;
	case 5:
		gpio_bits->ODR.bit.ODR5 = pin_data;
		break;
	case 6:
		gpio_bits->ODR.bit.ODR6 = pin_data;
		break;
	case 7:
		gpio_bits->ODR.bit.ODR7 = pin_data;
		break;
	case 8:
		gpio_bits->ODR.bit.ODR8 = pin_data;
		break;
	case 9:
		gpio_bits->ODR.bit.ODR9 = pin_data;
		break;
	case 10:
		gpio_bits->ODR.bit.ODR10 = pin_data;
		break;
	case 11:
		gpio_bits->ODR.bit.ODR11 = pin_data;
		break;
	case 12:
		gpio_bits->ODR.bit.ODR12 = pin_data;
		break;
	case 13:
		gpio_bits->ODR.bit.ODR13 = pin_data;
		break;
	case 14:
		gpio_bits->ODR.bit.ODR14 = pin_data;
		break;
	case 15:
		gpio_bits->ODR.bit.ODR15 = pin_data;
		break;
	default:
		break;
	}

}

void gpio_alternate_function_bit_setup(GPIO_TypeDef *gpio, gpio_pin_t pin_n,
		gpio_af_t pin_altf) {

	BITS_GPIO_TypeDef *gpio_bits = (BITS_GPIO_TypeDef*) gpio;

	switch (pin_n) {
	case 0:
		gpio_bits->AFRL.bit.AFRL0 = pin_altf;
		break;
	case 1:
		gpio_bits->AFRL.bit.AFRL1 = pin_altf;
		break;
	case 2:
		gpio_bits->AFRL.bit.AFRL2 = pin_altf;
		break;
	case 3:
		gpio_bits->AFRL.bit.AFRL3 = pin_altf;
		break;
	case 4:
		gpio_bits->AFRL.bit.AFRL4 = pin_altf;
		break;
	case 5:
		gpio_bits->AFRL.bit.AFRL5 = pin_altf;
		break;
	case 6:
		gpio_bits->AFRL.bit.AFRL6 = pin_altf;
		break;
	case 7:
		gpio_bits->AFRL.bit.AFRL7 = pin_altf;
		break;
	case 8:
		gpio_bits->AFRH.bit.AFRH8 = pin_altf;
		break;
	case 9:
		gpio_bits->AFRH.bit.AFRH9 = pin_altf;
		break;
	case 10:
		gpio_bits->AFRH.bit.AFRH10 = pin_altf;
		break;
	case 11:
		gpio_bits->AFRH.bit.AFRH11 = pin_altf;
		break;
	case 12:
		gpio_bits->AFRH.bit.AFRH12 = pin_altf;
		break;
	case 13:
		gpio_bits->AFRH.bit.AFRH13 = pin_altf;
		break;
	case 14:
		gpio_bits->AFRH.bit.AFRH14 = pin_altf;
		break;
	case 15:
		gpio_bits->AFRH.bit.AFRH15 = pin_altf;
		break;
	default:
		break;
	}
}

