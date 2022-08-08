/*
 * gpio.h
 *
 *  Created on: 8 авг. 2022 г.
 *      Author: ruslan
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include <assert.h>
#include "stm32f4xx.h"

#define GPIO_MODER_BITS_TYPEDEF_SIZE 4
#define GPIO_OTYPER_BITS_TYPEDEF_SIZE 4
#define GPIO_OSPEEDR_BITS_TYPEDEF_SIZE 4

typedef struct __attribute__((packed)) GPIO_MODER_BITS {
	unsigned MODER0 :2;
	unsigned MODER1 :2;
	unsigned MODER2 :2;
	unsigned MODER3 :2;
	unsigned MODER4 :2;
	unsigned MODER5 :2;
	unsigned MODER6 :2;
	unsigned MODER7 :2;
	unsigned MODER8 :2;
	unsigned MODER9 :2;
	unsigned MODER10 :2;
	unsigned MODER11 :2;
	unsigned MODER12 :2;
	unsigned MODER13 :2;
	unsigned MODER14 :2;
	unsigned MODER15 :2;
} GPIO_MODER_BITS_TYPEDEF;
static_assert(sizeof(GPIO_MODER_BITS_TYPEDEF) == GPIO_MODER_BITS_TYPEDEF_SIZE, "Invalid size of GPIO_MODER_BITS_TYPEDEF!");

typedef union _GPIO_MODER_REG {
	uint32_t all;
	struct GPIO_MODER_BITS bit;
} GPIO_MODER_REG;


typedef struct __attribute__((packed)) GPIO_OTYPER_BITS {
	unsigned OT0 :1;
	unsigned OT1 :1;
	unsigned OT2 :1;
	unsigned OT3 :1;
	unsigned OT4 :1;
	unsigned OT5 :1;
	unsigned OT6 :1;
	unsigned OT7 :1;
	unsigned OT8 :1;
	unsigned OT9 :1;
	unsigned OT10 :1;
	unsigned OT11 :1;
	unsigned OT12 :1;
	unsigned OT13 :1;
	unsigned OT14 :1;
	unsigned OT15 :1;
	unsigned RSVD_31_16 :16;
} GPIO_OTYPER_BITS_TYPEDEF;
static_assert(sizeof(GPIO_OTYPER_BITS_TYPEDEF) == GPIO_OTYPER_BITS_TYPEDEF_SIZE, "Invalid size of GPIO_OTYPER_BITS_TYPEDEF!");

typedef union _GPIO_OTYPER_REG {
	uint32_t all;
	struct GPIO_OTYPER_BITS bit;
} GPIO_OTYPER_REG;


typedef struct __attribute__((packed)) GPIO_OSPEEDR_BITS {
	unsigned OSPEEDR0 :2;
	unsigned OSPEEDR1 :2;
	unsigned OSPEEDR2 :2;
	unsigned OSPEEDR3 :2;
	unsigned OSPEEDR4 :2;
	unsigned OSPEEDR5 :2;
	unsigned OSPEEDR6 :2;
	unsigned OSPEEDR7 :2;
	unsigned OSPEEDR8 :2;
	unsigned OSPEEDR9 :2;
	unsigned OSPEEDR10 :2;
	unsigned OSPEEDR11 :2;
	unsigned OSPEEDR12 :2;
	unsigned OSPEEDR13 :2;
	unsigned OSPEEDR14 :2;
	unsigned OSPEEDR15 :2;
} GPIO_OSPEEDR_BITS_TYPEDEF;
static_assert(sizeof(GPIO_OSPEEDR_BITS_TYPEDEF) == GPIO_OSPEEDR_BITS_TYPEDEF_SIZE, "Invalid size of GPIO_OSPEEDR_BITS_TYPEDEF!");

typedef union _GPIO_OSPEEDR_REG {
	uint32_t all;
	struct GPIO_OSPEEDR_BITS bit;
} GPIO_OSPEEDR_REG;


typedef struct GPIO_PUPDR_BITS {
	//TODO: хватит заниматься херней
};


typedef struct
{
  __IO GPIO_MODER_REG	MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO GPIO_OTYPER_REG	OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO GPIO_OSPEEDR_REG	OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint16_t BSRRL;    /*!< GPIO port bit set/reset low register,  Address offset: 0x18      */
  __IO uint16_t BSRRH;    /*!< GPIO port bit set/reset high register, Address offset: 0x1A      */
  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} USER_GPIO_TypeDef;


#endif /* INC_GPIO_H_ */
