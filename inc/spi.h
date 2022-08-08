/*
 * spi_dma.h
 *
 *  Created on: 6 мая 2022 г.
 *      Author: Ruslan
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

#include <assert.h>
#include "stm32f4xx.h"

#define SPI_CR1_T_SIZE 2
#define SPI_CR2_T_SIZE 2
#define SPI_SR_T_SIZE 2
#define SPI_I2S_T_SIZE 2


typedef struct __attribute__((packed)) SPI_CR1_BITS {
	unsigned CPHA		:1; //Bit 0		Clock phase
	unsigned CPOL		:1; //Bit 1		Clock polarity
	unsigned MSTR		:1; //Bit 2		Master selection
	unsigned BR			:3; //Bits 5:3	Baud rate control
	unsigned SPE		:1; //Bit 6		SPI enable
	unsigned LSBFIRST	:1; //Bit 7		Frame format
	unsigned SSI		:1; //Bit 8		Internal slave select
	unsigned SSM		:1; //Bit 9		Software slave management
	unsigned RXONLY		:1; //Bit 10	Receive only
	unsigned DFF		:1; //Bit 11	Data frame format
	unsigned CRCNEXT	:1; //Bit 12	CRC transfer next
	unsigned CRCEN		:1; //Bit 13	Hardware CRC calculation enable
	unsigned BIDIOE		:1; //Bit 14	Output enable in bidirectional mode
	unsigned BIDIMODE	:1; //Bit 15	Bidirectional data mode enable
} spi_cr1_t;
static_assert(sizeof(spi_cr1_t) == SPI_CR1_T_SIZE, "Invalid size of spi_cr1_t!");

typedef union _SPI_CR1_REG {
	uint16_t all;
	struct SPI_CR1_BITS bit;
} SPI_CR1_REG;


typedef struct __attribute__((packed)) SPI_CR2_BITS {
	unsigned RXDMAEN	:1; //Bit 0		Rx buffer DMA enable
	unsigned TXDMAEN	:1; //Bit 1		Tx buffer DMA enable
	unsigned SSOE		:1; //Bit 2		SS output enable
	unsigned RSVD_3		:1; //Bit 3		Forced to 0 by hardware.
	unsigned FRF		:1; //Bit 4		Frame format
	unsigned ERRIE		:1; //Bit 5		Error interrupt enable
	unsigned RXNEIE		:1; //Bit 6		RX buffer not empty interrupt enable
	unsigned TXEIE		:1; //Bit 7		Tx buffer empty interrupt enable
	unsigned RSVD_15_8	:8; //Bits 15:8	Reserved, must be kept at reset value.
} spi_cr2_t;
static_assert(sizeof(spi_cr2_t) == SPI_CR2_T_SIZE, "Invalid size of spi_cr2_t!");

typedef union _SPI_CR2_REG {
	uint16_t all;
	struct SPI_CR2_BITS bit;
} SPI_CR2_REG;


typedef struct __attribute__((packed)) SPI_SR_BITS {
	unsigned RXNE		:1; //Bit 0		Receive buffer not empty
	unsigned TXE		:1; //Bit 1		Transmit buffer empty
	unsigned CHSIDE		:1; //Bit 2		Channel side
	unsigned UDR		:1; //Bit 3		Underrun flag
	unsigned CRCERR		:1; //Bit 4		CRC error flag
	unsigned MODF		:1; //Bit 5		Mode fault
	unsigned OVR		:1; //Bit 6		Overrun flag
	unsigned BSY		:1; //Bit 7		Busy flag
	unsigned FRE		:1; //Bit 8		Frame format error
	unsigned RSVD_15_9	:7; //Bits 15:9	Forced to 0 by hardware.
} spi_sr_t;
static_assert(sizeof(spi_sr_t) == SPI_SR_T_SIZE, "Invalid size of spi_sr_t!");

typedef union _SPI_SR_REG {
	uint16_t all;
	struct SPI_SR_BITS bit;
} SPI_SR_REG;


typedef struct __attribute__((packed)) SPI_I2S_BITS {
	unsigned CHLEN		:1; //Bit 0		Channel length (number of bits per audio channel)
	unsigned DATLEN		:2; //Bits 2:1	Data length to be transferred
	unsigned CKPOL		:1; //Bit 3		Steady state clock polarity
	unsigned I2SSTD		:2; //Bits 5:4	I2S standard selection
	unsigned RSVD_6		:1; //Bit 6		Forced at 0 by hardware
	unsigned PCMSYNC	:1; //Bit 7		PCM frame synchronization
	unsigned I2SCFG		:2; //Bits 9:8	I2S configuration mode
	unsigned I2SE		:1; //Bit 10	I2S Enable
	unsigned I2SMOD		:1; //Bit 11	I2S mode selection
	unsigned RSVD_15_12	:4; //Bits 15:12 must be kept at reset value.
} spi_i2s_t;
static_assert(sizeof(spi_i2s_t) == SPI_I2S_T_SIZE, "Invalid size of spi_i2s_t!");

typedef union _SPI_I2S_REG {
	uint16_t all;
	struct SPI_I2S_BITS bit;
} SPI_I2S_REG;


typedef struct
{
  __IO SPI_CR1_REG	CR1;		/*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
  uint16_t			RESERVED0;	/*!< Reserved, 0x02                                                           */
  __IO SPI_CR2_REG	CR2;		/*!< SPI control register 2,                             Address offset: 0x04 */
  uint16_t			RESERVED1;	/*!< Reserved, 0x06                                                           */
  __IO SPI_SR_REG	SR;			/*!< SPI status register,                                Address offset: 0x08 */
  uint16_t			RESERVED2;	/*!< Reserved, 0x0A                                                           */
  __IO uint16_t		DR;			/*!< SPI data register,                                  Address offset: 0x0C */
  uint16_t			RESERVED3;	/*!< Reserved, 0x0E                                                           */
  __IO uint16_t		CRCPR;		/*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
  uint16_t			RESERVED4;	/*!< Reserved, 0x12                                                           */
  __IO uint16_t		RXCRCR;		/*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
  uint16_t			RESERVED5;	/*!< Reserved, 0x16                                                           */
  __IO uint16_t		TXCRCR;		/*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
  uint16_t			RESERVED6;	/*!< Reserved, 0x1A                                                           */
  __IO SPI_I2S_REG	I2SCFGR;	/*!< SPI_I2S configuration register,                     Address offset: 0x1C */
  uint16_t			RESERVED7;	/*!< Reserved, 0x1E                                                           */
  __IO uint16_t		I2SPR;		/*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
  uint16_t			RESERVED8;	/*!< Reserved, 0x22                                                           */
} spi_typedef;

#define SPI1_U		((spi_typedef *) SPI1_BASE)
#define SPI2_U		((spi_typedef *) SPI2_BASE)
#define SPI3_U		((spi_typedef *) SPI3_BASE)
#define SPI4_U		((spi_typedef *) SPI4_BASE)
#define SPI5_U		((spi_typedef *) SPI5_BASE)
#define SPI6_U		((spi_typedef *) SPI6_BASE)

#endif /* INC_SPI_H_ */
