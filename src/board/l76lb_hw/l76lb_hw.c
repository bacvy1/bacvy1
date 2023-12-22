/*
 * l76lb_hw.c
 *
 *  Created on: Jan 2, 2022
 *      Author: Ha
 */

#include "l76lb_hw.h"
#include "stdbool.h"
#include "FreeRTOS.h"
#include "task.h"

GPS_hw  gps_hw;
static volatile bool _is_gps_transmit_completed = false;

void gps_hw_init(void){
    /* Baudrate default is 115200 bps */
    R_SCI_UART_Open(&g_uart1_ctrl, &g_uart1_cfg);
}

void gps_sends(const char* tx_buff){
    _is_gps_transmit_completed = false;
    R_SCI_UART_Write(&g_uart1_ctrl, (uint8_t*)tx_buff, strlen(tx_buff));
    TickType_t timeout = pdMS_TO_TICKS(5000);
    while(!_is_gps_transmit_completed){
    	if(timeout-- >0 ) break;
    	vTaskDelay(1);
    }
}

/* Callback function */
void gps_callback(uart_callback_args_t *p_args)
{
    /* TODO: add your own code here */
    if(p_args->event == UART_EVENT_RX_CHAR){

        gps_hw.rx_data = (uint8_t)p_args->data;
        gps_hw.receive_handle(&gps_hw);
    }
    else if(p_args->event == UART_EVENT_TX_COMPLETE){
        _is_gps_transmit_completed = true;
    }
}

