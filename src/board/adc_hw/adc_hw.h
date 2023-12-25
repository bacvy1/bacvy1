/*
 * adc_sensor.h
 *
 *  Created on: 26 Dec 2023
 *      Author: Admin
 */

#ifndef BOARD_ADC_HW_ADC_HW_H_
#define BOARD_ADC_HW_ADC_HW_H_
#include "hal_data.h"

#define ADC_12BIT_RESOLUTION            (4095)
#define ADC_REFERENCE_VOLTAGE_mV        (3300)

typedef struct ADC_HW_t ADC_HW;
struct ADC_HW_t{
    uint16_t channel11_value;
    uint16_t channel12_value;
};

extern ADC_HW adc_hw;

void adc_hw_init();
void adc_start_scan();
void adc_get_value(adc_channel_t channel, uint16_t* value);
void adc_set_en_dust_pin(bsp_io_port_pin_t pin, uint8_t level);
#endif /* BOARD_ADC_HW_ADC_HW_H_ */
