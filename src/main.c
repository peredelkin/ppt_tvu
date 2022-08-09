
#include "stm32f4xx.h"
#include "tic12400.h"
#include "gpio.h"

int main(void) {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
	GPIOH->MODER |= (GPIO_MODER_MODER10_0 | GPIO_MODER_MODER11_0 | GPIO_MODER_MODER12_0);
	GPIOH->ODR |= (GPIO_ODR_ODR_10 | GPIO_ODR_ODR_11 | GPIO_ODR_ODR_12);

	gpio_pin_setup(GPIOA, GPIO_PIN_1, GPIO_MODE_OUT_GP, GPIO_OTYPE_PP, GPIO_OSPEED_LOW, GPIO_PUPD_NONE, GPIO_AF_0);

	for(int i = 0; i < 10000000; i ++){
		__NOP();
	}
	uint8_t i = 0;
	while(1){
		GPIOH->ODR &= ~(GPIO_ODR_ODR_10 | GPIO_ODR_ODR_11 | GPIO_ODR_ODR_12);
		GPIOH->ODR |= (GPIO_ODR_ODR_10 | GPIO_ODR_ODR_11 | GPIO_ODR_ODR_12) & (uint32_t)(i << 10);

		for(int i = 0; i < 7000000; i ++){
					__NOP();
				}

		if(i == 7) {
			i = 0;
		} else {
			i++;
		}
	}
	return 0;
}
