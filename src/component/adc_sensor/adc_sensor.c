/*
 * adc_sensor.c
 *
 *  Created on: 26 Dec 2023
 *      Author: Admin
 */
#include "adc_sensor.h"
#include "sm_bsp_delay.h"
#include "FreeRTOS.h"
#include "task.h"
#include "mq7_lookup_table.h"

static void adc_sensor_get_value(ADC_SENSOR* p_adc);
static void adc_sensor_measure();
void adc_sensor_init(ADC_SENSOR* p_adc){
    adc_hw_init();
    p_adc->hw = &adc_hw;
}

void adc_sensor_process(ADC_SENSOR* p_adc){
    adc_sensor_measure();
    vTaskDelay(pdMS_TO_TICKS(100));
    adc_sensor_get_value(p_adc);

}

static void adc_sensor_measure(){
    adc_set_en_dust_pin(DUST_EN, 0);
    sm_bsp_delay_us(280);
    adc_start_scan();
    sm_bsp_delay_us(40);
    adc_set_en_dust_pin(DUST_EN, 1);
    sm_bsp_delay_us(9680);
}

static void adc_sensor_get_value(ADC_SENSOR* p_adc){
    float c11_mvol = 0, c12_mvol = 0;
    c11_mvol = (float)(p_adc->hw->channel11_value*5000)/ADC_12BIT_RESOLUTION;
    if(c11_mvol > 875){
        p_adc->dust_value = (float)((c11_mvol/1000)*6/35-0.15)*1000;
    }
    else
        p_adc->dust_value = 0;
    if (p_adc->hw->channel12_value > 0)
        c12_mvol = (float)(p_adc->hw->channel12_value*ADC_REFERENCE_VOLTAGE_mV)/ADC_12BIT_RESOLUTION;
    else
        c12_mvol = 0;
//    p_adc->dust_value = (float)((c11_mvol/1000)/0.5);
//    p_adc->co_value = (float)(c12_mvol * 0.3);
    for(int i = 0; i < 330; i++){
        if((int)c12_mvol < mq7_voltage[i]){
            p_adc->co_value = ppm_value[i];
            break;
        }
    }
}
