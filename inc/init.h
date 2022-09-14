/*
 * init.h
 *
 *  Created on: 31 авг. 2022 г.
 *      Author: Ruslan
 */

#ifndef INC_INIT_H_
#define INC_INIT_H_

#include "stm32f4xx.h"
#include "gpio_init.h"

extern void rcc_init(void);
extern void gpio_preinit(void);
extern void gpio_init(void);

#endif /* INC_INIT_H_ */
