/*
 * spi_dma.c
 *
 *  Created on: 6 мая 2022 г.
 *      Author: Ruslan
 */

#include "spi.h"

void spi_cfg_setup(SPI_TypeDef *spi, const CFG_REG_SPI_TypeDef* spi_cfg) {
	BITS_SPI_TypeDef *spi_bits = (BITS_SPI_TypeDef*) spi;
	//выключение SPI перед настройкой
	spi_bits->CR1.bit.SPE = SPI_SPE_DIS;
	//запись настроек
	spi_bits->CR1.all = spi_cfg->CR1.all;
	spi_bits->CR2.all = spi_cfg->CR2.all;
}
