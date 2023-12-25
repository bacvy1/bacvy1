/*
 * adc_sensor.h
 *
 *  Created on: 26 Dec 2023
 *      Author: Admin
 */

#ifndef COMPONENT_ADC_SENSOR_ADC_SENSOR_H_
#define COMPONENT_ADC_SENSOR_ADC_SENSOR_H_
#include "adc_hw.h"
#include "board.h"

#define CO_SENSOR_DILIMETER 300
typedef struct ADC_SENSOR_t ADC_SENSOR;
struct ADC_SENSOR_t{
    ADC_HW* hw;
    float dust_value;
    float co_value;
};

void adc_sensor_process(ADC_SENSOR* p_adc);
void adc_sensor_init(ADC_SENSOR* p_adc);
#endif /* COMPONENT_ADC_SENSOR_ADC_SENSOR_H_ */
