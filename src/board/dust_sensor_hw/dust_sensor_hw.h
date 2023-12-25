/*
 * dust_sensor_hw.h
 *
 *  Created on: Dec 25, 2023
 *      Author: My PC
 */

#ifndef BOARD_DUST_SENSOR_HW_DUST_SENSOR_HW_H_
#define BOARD_DUST_SENSOR_HW_DUST_SENSOR_HW_H_

#include "bsp_api.h"
#include "common_data.h"
#include "hal_data.h"
#include "stdint.h"

#define ADC_12BIT_RESOLUTION            (4095)
#define ADC_REFERENCE_VOLTAGE_mV        (3300)

typedef struct DUST_hw_t DUST_hw;
struct DUST_hw_t{
    uint16_t value;
    uint16_t offset;
    float   voltage;
};

extern DUST_hw dust_hw;
void dust_hw_init(void);
void adc_hw_start_scan(void);
void adc_hw_stop_scan(void);
void en_pin_write(uint8_t level);
#endif /* BOARD_DUST_SENSOR_HW_DUST_SENSOR_HW_H_ */
