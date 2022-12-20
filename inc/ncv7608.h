/*
 * ncv7608.h
 *
 *  Created on: 20 дек. 2022 г.
 *      Author: Ruslan
 */

#ifndef INC_NCV7608_H_
#define INC_NCV7608_H_

#include <stdint.h>
#include <assert.h>
#include "defs.h"

#define NCV7608_FRAME_SIZE 2

//структура Input Data
typedef struct PACKED _NCV7608_INPUT_DATA_BITS {
	unsigned driver_1_ena : 1;
	unsigned driver_2_ena : 1;
	unsigned driver_3_ena : 1;
	unsigned driver_4_ena : 1;
	unsigned driver_5_ena : 1;
	unsigned driver_6_ena : 1;
	unsigned driver_7_ena : 1;
	unsigned driver_8_ena : 1;
	unsigned diagnostic_1_ena : 1;
	unsigned diagnostic_2_ena : 1;
	unsigned diagnostic_3_ena : 1;
	unsigned diagnostic_4_ena : 1;
	unsigned diagnostic_5_ena : 1;
	unsigned diagnostic_6_ena : 1;
	unsigned diagnostic_7_ena : 1;
	unsigned diagnostic_8_ena : 1;
} ncv7608_input_data_t;
static_assert(sizeof(ncv7608_input_data_t) == NCV7608_FRAME_SIZE, "Invalid size of ncv7608_input_data_t!");

typedef union _NCV7608_INPUT_DATA_REG {
	uint16_t all;
	struct _NCV7608_INPUT_DATA_BITS bit;
} NCV7608_INPUT_DATA_REG;

//структура Output Data
typedef struct PACKED _NCV7608_OUTPUT_DATA_BITS {
	unsigned  thermal_warning : 1;
	unsigned  driver_1_status : 1;
	unsigned  driver_2_status : 1;
	unsigned  driver_3_status : 1;
	unsigned  driver_4_status : 1;
	unsigned  driver_5_status : 1;
	unsigned  driver_6_status : 1;
	unsigned  driver_7_status : 1;
	unsigned  driver_8_status : 1;
	unsigned  input_5_state : 1;
	unsigned  input_6_state : 1;
	unsigned  input_7_state : 1;
	unsigned  input_8_state : 1;
	unsigned  reserved_13 : 1;
	unsigned  reserved_14 : 1;
	unsigned  vs_ps_monitoring : 1;
} ncv7608_output_data_t;
static_assert(sizeof(ncv7608_output_data_t) == NCV7608_FRAME_SIZE, "Invalid size of ncv7608_output_data_t!");

typedef union _NCV7608_OUTPUT_DATA_REG {
	uint16_t all;
	struct _NCV7608_OUTPUT_DATA_BITS bit;
} NCV7608_OUTPUT_DATA_REG;

#endif /* INC_NCV7608_H_ */
