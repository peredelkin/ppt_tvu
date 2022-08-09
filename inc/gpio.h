/*
 * gpio.h
 *
 *  Created on: 8 авг. 2022 г.
 *      Author: ruslan
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include <assert.h>
#include <stdbool.h>
#include "stm32f4xx.h"

#define GPIO_MODER_BITS_TYPEDEF_SIZE 4
#define GPIO_OTYPER_BITS_TYPEDEF_SIZE 4
#define GPIO_OSPEEDR_BITS_TYPEDEF_SIZE 4
#define GPIO_PUPDR_BITS_TYPEDEF_SIZE 4
#define GPIO_IDR_BITS_TYPEDEF_SIZE 4
#define GPIO_ODR_BITS_TYPEDEF_SIZE 4
#define GPIO_LCKR_BITS_TYPEDEF_SIZE 4
#define GPIO_AFRL_BITS_TYPEDEF_SIZE 4
#define GPIO_AFRH_BITS_TYPEDEF_SIZE 4

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


typedef struct __attribute__((packed)) GPIO_PUPDR_BITS {
	unsigned PUPDR0 :2;
	unsigned PUPDR1 :2;
	unsigned PUPDR2 :2;
	unsigned PUPDR3 :2;
	unsigned PUPDR4 :2;
	unsigned PUPDR5 :2;
	unsigned PUPDR6 :2;
	unsigned PUPDR7 :2;
	unsigned PUPDR8 :2;
	unsigned PUPDR9 :2;
	unsigned PUPDR10 :2;
	unsigned PUPDR11 :2;
	unsigned PUPDR12 :2;
	unsigned PUPDR13 :2;
	unsigned PUPDR14 :2;
	unsigned PUPDR15 :2;
} GPIO_PUPDR_BITS_TYPEDEF;
static_assert(sizeof(GPIO_PUPDR_BITS_TYPEDEF) == GPIO_PUPDR_BITS_TYPEDEF_SIZE, "Invalid size of GPIO_PUPDR_BITS_TYPEDEF!");

typedef union _GPIO_PUPDR_REG {
	uint32_t all;
	struct GPIO_PUPDR_BITS bit;
} GPIO_PUPDR_REG;


typedef struct __attribute__((packed)) GPIO_IDR_BITS {
	unsigned IDR0 :1;
	unsigned IDR1 :1;
	unsigned IDR2 :1;
	unsigned IDR3 :1;
	unsigned IDR4 :1;
	unsigned IDR5 :1;
	unsigned IDR6 :1;
	unsigned IDR7 :1;
	unsigned IDR8 :1;
	unsigned IDR9 :1;
	unsigned IDR10 :1;
	unsigned IDR11 :1;
	unsigned IDR12 :1;
	unsigned IDR13 :1;
	unsigned IDR14 :1;
	unsigned IDR15 :1;
	unsigned RSVD_31_16 :16;
} GPIO_IDR_BITS_TYPEDEF;
static_assert(sizeof(GPIO_IDR_BITS_TYPEDEF) == GPIO_IDR_BITS_TYPEDEF_SIZE, "Invalid size of GPIO_IDR_BITS_TYPEDEF!");

typedef union _GPIO_IDR_REG {
	uint32_t all;
	struct GPIO_IDR_BITS bit;
} GPIO_IDR_REG;


typedef struct __attribute__((packed)) GPIO_ODR_BITS {
	unsigned ODR0 :1;
	unsigned ODR1 :1;
	unsigned ODR2 :1;
	unsigned ODR3 :1;
	unsigned ODR4 :1;
	unsigned ODR5 :1;
	unsigned ODR6 :1;
	unsigned ODR7 :1;
	unsigned ODR8 :1;
	unsigned ODR9 :1;
	unsigned ODR10 :1;
	unsigned ODR11 :1;
	unsigned ODR12 :1;
	unsigned ODR13 :1;
	unsigned ODR14 :1;
	unsigned ODR15 :1;
	unsigned RSVD_31_16 :16;
} GPIO_ODR_BITS_TYPEDEF;
static_assert(sizeof(GPIO_ODR_BITS_TYPEDEF) == GPIO_ODR_BITS_TYPEDEF_SIZE, "Invalid size of GPIO_ODR_BITS_TYPEDEF!");

typedef union _GPIO_ODR_REG {
	uint32_t all;
	struct GPIO_ODR_BITS bit;
} GPIO_ODR_REG;


typedef struct __attribute__((packed)) GPIO_LCKR_BITS {
	unsigned LCK0 :1;
	unsigned LCK1 :1;
	unsigned LCK2 :1;
	unsigned LCK3 :1;
	unsigned LCK4 :1;
	unsigned LCK5 :1;
	unsigned LCK6 :1;
	unsigned LCK7 :1;
	unsigned LCK8 :1;
	unsigned LCK9 :1;
	unsigned LCK10 :1;
	unsigned LCK11 :1;
	unsigned LCK12 :1;
	unsigned LCK13 :1;
	unsigned LCK14 :1;
	unsigned LCK15 :1;
	unsigned LCKK :1;
	unsigned RSVD_31_17 :15;
} GPIO_LCKR_BITS_TYPEDEF;
static_assert(sizeof(GPIO_LCKR_BITS_TYPEDEF) == GPIO_LCKR_BITS_TYPEDEF_SIZE, "Invalid size of GPIO_LCKR_BITS_TYPEDEF!");

typedef union _GPIO_LCKR_REG {
	uint32_t all;
	struct GPIO_LCKR_BITS bit;
} GPIO_LCKR_REG;


typedef struct __attribute__((packed)) GPIO_AFRL_BITS {
	unsigned AFRL0 :4;
	unsigned AFRL1 :4;
	unsigned AFRL2 :4;
	unsigned AFRL3 :4;
	unsigned AFRL4 :4;
	unsigned AFRL5 :4;
	unsigned AFRL6 :4;
	unsigned AFRL7 :4;
} GPIO_AFRL_BITS_TYPEDEF;
static_assert(sizeof(GPIO_AFRL_BITS_TYPEDEF) == GPIO_AFRL_BITS_TYPEDEF_SIZE, "Invalid size of GPIO_AFRL_BITS_TYPEDEF!");

typedef union _GPIO_AFRL_REG {
	uint32_t all;
	struct GPIO_AFRL_BITS bit;
} GPIO_AFRL_REG;


typedef struct  __attribute__((packed)) GPIO_AFRH_BITS {
	unsigned AFRH8 :4;
	unsigned AFRH9 :4;
	unsigned AFRH10 :4;
	unsigned AFRH11 :4;
	unsigned AFRH12 :4;
	unsigned AFRH13 :4;
	unsigned AFRH14 :4;
	unsigned AFRH15 :4;
} GPIO_AFRH_BITS_TYPEDEF;
static_assert(sizeof(GPIO_AFRH_BITS_TYPEDEF) == GPIO_AFRH_BITS_TYPEDEF_SIZE, "Invalid size of GPIO_AFRH_BITS_TYPEDEF!");

typedef union _GPIO_AFRH_REG {
	uint32_t all;
	struct GPIO_AFRH_BITS bit;
} GPIO_AFRH_REG;


typedef struct
{
  __IO GPIO_MODER_REG	MODER;		/*!< GPIO port mode register,               Address offset: 0x00	*/
  __IO GPIO_OTYPER_REG	OTYPER;		/*!< GPIO port output type register,        Address offset: 0x04	*/
  __IO GPIO_OSPEEDR_REG	OSPEEDR;	/*!< GPIO port output speed register,       Address offset: 0x08	*/
  __IO GPIO_PUPDR_REG	PUPDR;		/*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C	*/
  __IO GPIO_IDR_REG		IDR;		/*!< GPIO port input data register,         Address offset: 0x10	*/
  __IO GPIO_ODR_REG		ODR;		/*!< GPIO port output data register,        Address offset: 0x14	*/
  __IO uint16_t			BSRRL;		/*!< GPIO port bit set/reset low register,  Address offset: 0x18	*/
  __IO uint16_t			BSRRH;		/*!< GPIO port bit set/reset high register, Address offset: 0x1A	*/
  __IO GPIO_LCKR_REG	LCKR;		/*!< GPIO port configuration lock register, Address offset: 0x1C	*/
  __IO GPIO_AFRL_REG	AFRL;		/*!< GPIO alternate function registers,     Address offset: 0x20	*/
  __IO GPIO_AFRH_REG	AFRH;		/*!< GPIO alternate function registers,     Address offset: 0x24	*/
} BITS_GPIO_TypeDef;



//! Маска пина.
enum _Gpio_Pin_Mask {
    GPIO_PIN_0  = (0),
    GPIO_PIN_1  = (1),
    GPIO_PIN_2  = (2),
    GPIO_PIN_3  = (3),
    GPIO_PIN_4  = (4),
    GPIO_PIN_5  = (5),
    GPIO_PIN_6  = (6),
    GPIO_PIN_7  = (7),
    GPIO_PIN_8  = (8),
    GPIO_PIN_9  = (9),
    GPIO_PIN_10 = (10),
    GPIO_PIN_11 = (11),
    GPIO_PIN_12 = (12),
    GPIO_PIN_13 = (13),
    GPIO_PIN_14 = (14),
    GPIO_PIN_15 = (15)
};

//! Тип пина GPIO.
typedef uint16_t gpio_pin_t;

//! Состояние пина.
enum _Gpio_Pin_State {
    GPIO_STATE_OFF = 0, //!< Выключено.
    GPIO_STATE_ON  = 1  //!< Включено.
};

//! Тип состояния пина.
typedef uint16_t gpio_state_t;

//! Режим пина.
enum _Gpio_Mode {
    GPIO_MODE_INPUT = 0, //!< Вход.
    GPIO_MODE_OUT_GP = 1, //!< Выход общего назначения
    GPIO_MODE_OUT_AF = 2, //!< Выход альтернативных функций.
    GPIO_MODE_ANALOG = 3, //!< Аналоговый вход / выход.
};

//! Тип режима пина.
typedef enum _Gpio_Mode gpio_mode_t;

//! Тип выхода пина.
enum _Gpio_Otype {
    GPIO_OTYPE_PP = 0, //!< Пуш-пулл.
    GPIO_OTYPE_OD = 1  //!< Открытй коллектор.
};

//! Тип типа выхода пина.
typedef enum _Gpio_Otype gpio_otype_t;

//! Скорость выхода пина.
enum _Gpio_Ospeed {
    GPIO_OSPEED_LOW       = 0, //!< Очень медленно.
    GPIO_OSPEED_MEDIUM    = 1, //!< Медленно.
    GPIO_OSPEED_HIGH      = 2, //!< Быстро.
    GPIO_OSPEED_VERY_HIGH = 3  //!< Очень быстро.
};

//! Тип скорости выхода пина.
typedef enum _Gpio_Ospeed gpio_ospeed_t;

//! Подтяжка пина.
enum _Gpio_PuPd {
    GPIO_PUPD_NONE = 0, //!< Подтяжка не включена.
    GPIO_PUPD_UP   = 1, //!< Подтяжка к питанию.
    GPIO_PUPD_DOWN = 2  //!< Подтяжка к земле.
};

//! Тип подтяжки пина.
typedef enum _Gpio_PuPd gpio_pupd_t;

//! Альтернативные функции пина.
enum _Gpio_Af {
    GPIO_AF_0 = 0,
    GPIO_AF_1 = 1,
    GPIO_AF_2 = 2,
    GPIO_AF_3 = 3,
    GPIO_AF_4 = 4,
    GPIO_AF_5 = 5,
    GPIO_AF_6 = 6,
    GPIO_AF_7 = 7,
    GPIO_AF_8 = 8,
    GPIO_AF_9 = 9,
    GPIO_AF_10 = 10,
    GPIO_AF_11 = 11,
    GPIO_AF_12 = 12,
    GPIO_AF_13 = 13,
    GPIO_AF_14 = 14,
    GPIO_AF_15 = 15,
};

//! Тип альтернативных функций пина.
typedef enum _Gpio_Af gpio_af_t;



extern void gpio_pin_setup(GPIO_TypeDef *gpio,
		gpio_pin_t pin_n,
		gpio_mode_t pin_mode,
		gpio_otype_t pin_otype,
		gpio_ospeed_t pin_ospeed,
		gpio_pupd_t pin_pupd,
		gpio_af_t pin_altf);

#endif /* INC_GPIO_H_ */
