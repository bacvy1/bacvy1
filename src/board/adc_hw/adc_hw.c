/*
 * adc_sensor.c
 *
 *  Created on: 26 Dec 2023
 *      Author: Admin
 */
#include "adc_hw.h"
#include "hal_data.h"

ADC_HW adc_hw;

void adc_hw_init(){
    R_ADC_Open(&g_adc0_ctrl, &g_adc0_cfg);
    R_ADC_ScanCfg(&g_adc0_ctrl, &g_adc0_channel_cfg);
    adc_start_scan();
}

void adc_start_scan(){
   R_ADC_ScanStart(&g_adc0_ctrl);
}

void adc_get_value(adc_channel_t channel, uint16_t* value){
    R_ADC_Read(&g_adc0_ctrl, channel, value);
}

void adc_set_en_dust_pin(bsp_io_port_pin_t pin, uint8_t level){
    R_IOPORT_PinWrite(&g_ioport_ctrl, pin, (bsp_io_level_t)level);
}
/* Callback function */
void adc_callback(adc_callback_args_t *p_args)
{
    /* TODO: add your own code here */
    if(p_args->event != ADC_EVENT_SCAN_COMPLETE){
        return;
    }
    adc_get_value(ADC_CHANNEL_11, &adc_hw.channel11_value);
    adc_get_value(ADC_CHANNEL_12, &adc_hw.channel12_value);
}

