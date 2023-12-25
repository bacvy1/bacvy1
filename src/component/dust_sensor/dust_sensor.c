/*
 * dust_sensor.c
 *
 *  Created on: Dec 25, 2023
 *      Author: My PC
 */
#include "dust_sensor.h"

void dust_sensor_init(DUST_SENSOR* p_dust){
    p_dust->hw = &dust_hw;
    dust_hw_init();
}

void dust_sensor_process(DUST_SENSOR* p_dust){
    en_pin_write(0);
    R_BSP_SoftwareDelay(280, BSP_DELAY_UNITS_MICROSECONDS);
    adc_hw_start_scan();
    R_BSP_SoftwareDelay(40, BSP_DELAY_UNITS_MICROSECONDS);
    en_pin_write(1);
    R_BSP_SoftwareDelay(9680, BSP_DELAY_UNITS_MICROSECONDS);

    p_dust->result = 0.17*p_dust->hw->voltage - 0.1;
}


