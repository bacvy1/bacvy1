/*
 * dust_sensor_hw.c
 *
 *  Created on: Dec 25, 2023
 *      Author: My PC
 */
#include "dust_sensor_hw.h"

DUST_hw dust_hw = {.offset = 0};

void dust_convert_handler();

void dust_hw_init(void){
    R_ADC_Open(&g_adc0_ctrl, &g_adc0_cfg);
    R_ADC_ScanCfg(&g_adc0_ctrl, &g_adc0_channel_cfg);
    adc_hw_start_scan();
}
void adc_hw_start_scan(void){
    R_ADC_ScanStart(&g_adc0_ctrl);
}

void adc_hw_stop_scan(void){
    R_ADC_ScanStop(&g_adc0_ctrl);
}


void en_pin_write(uint8_t level){
    R_IOPORT_PinWrite(&g_ioport_ctrl, DUST_EN, (bsp_io_level_t)level);
}

void dust_convert_handler(){
    dust_hw.voltage = (float)(((float)dust_hw.value/ADC_12BIT_RESOLUTION)*ADC_REFERENCE_VOLTAGE_mV);
}
/* Callback function */
void adc_callback(adc_callback_args_t *p_args)
{
    /* TODO: add your own code here */
    if(p_args->event != ADC_EVENT_SCAN_COMPLETE){
        return;
    }
    R_ADC_Read(&g_adc0_ctrl, ADC_CHANNEL_11, &dust_hw.value);
    dust_convert_handler();
}
