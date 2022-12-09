/*
 * tic12400_settings.h
 *
 *  Created on: 8 дек. 2022 г.
 *      Author: Ruslan
 */

#ifndef INC_TIC12400_SETTINGS_H_
#define INC_TIC12400_SETTINGS_H_

#include "tic12400.h"
#include "parity.h"

extern void tic124_settings_tx_frame_fill(void);

extern TIC12400_TX_FRAME tic124_in_stat_comp_tx_frame;
extern TIC12400_RX_FRAME tic124_in_stat_comp_rx_frame;

extern TIC12400_TX_FRAME tic124_settings_tx_frame[25];
extern TIC12400_RX_FRAME tic124_settings_rx_frame[25];

#endif /* INC_TIC12400_SETTINGS_H_ */
