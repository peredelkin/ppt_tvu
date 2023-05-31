/*
 * gpio_init.h
 *
 *  Created on: 31 авг. 2022 г.
 *      Author: Ruslan
 */

#ifndef INC_GPIO_INIT_H_
#define INC_GPIO_INIT_H_

#include "gpio.h"

#define GPIO_INIT_PINS_COUNT 25

//Socket 3
extern const gpio_pin_t GPO_OE_App;
extern const gpio_pin_t GPO_CS_SPI5_App;

//DI
extern const gpio_pin_t GPO_Reset_DI_App;
extern const gpio_pin_t GPI_Int_DI_App;
extern const gpio_pin_t GPO_CS_DI_App;

//DO
extern const gpio_pin_t GPO_CS_DO_App;

//AO
extern const gpio_pin_t GPO_SYNCAO_App;
extern const gpio_pin_t GPO_nLDAC_App;
extern const gpio_pin_t GPO_nCLR_App;

extern const gpio_pin_cfg_t gpio_init_array[GPIO_INIT_PINS_COUNT];

#endif /* INC_GPIO_INIT_H_ */
