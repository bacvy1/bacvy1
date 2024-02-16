/*
 * adc_app.c
 *
 *  Created on: 26 Dec 2023
 *      Author: Admin
 */
#include "adc_app.h"
#include "air_sensor_app.h"

void adc_app_init(){
    ADC_SENSOR* p_adc = &air_sensor_app.adc_sensor;
    adc_sensor_init(p_adc);
}

void adc_app_process(){
    ADC_SENSOR* p_adc = &air_sensor_app.adc_sensor;
    adc_sensor_process(p_adc);

}
