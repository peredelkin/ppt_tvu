/*
 * tic12400_settings.h
 *
 *  Created on: 8 дек. 2022 г.
 *      Author: Ruslan
 */

#ifndef INC_TIC12400_SETTINGS_H_
#define INC_TIC12400_SETTINGS_H_

#include "tic12400.h"
#include "spi.h"

extern TIC12400_TX_FRAME tic124_tx_frame[TIC12400_FRAME_COUNT];
extern TIC12400_RX_FRAME tic124_rx_frame[TIC12400_FRAME_COUNT];

extern const TIC12400_SETTINGS_TypeDef tic124_settings_const;

extern SPI_BUS_DATA_TypeDef tic124_spi_bus_data_control_array[TIC12400_FRAME_COUNT];

#endif /* INC_TIC12400_SETTINGS_H_ */
