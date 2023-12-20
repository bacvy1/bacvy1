/*
 * board.c
 *
 *  Created on: Dec 20, 2023
 *      Author: My PC
 */
#include "board.h"
#include "sm_porting.h"
#include "hal_data.h"

sm_bsp_uart_t *lte_uart = NULL;
sm_bsp_io_t *lte_rs_pin = NULL;

void board_init(void){
    lte_rs_pin = sm_bsp_io_init(&io_func, (void*)&g_ioport, BSP_IO_PORT_00_PIN_02);
    sm_bsp_io_open(lte_rs_pin, SM_BSP_IO_OUTPUT);
    lte_uart = sm_bsp_uart_init(&uart_func, (void*)&g_uart0);
    lte_uart->proc->open(lte_uart);
}

void lte_callback(uart_callback_args_t *p_args) {
    /* TODO: add your own code here */

    if (p_args->event == UART_EVENT_RX_CHAR) {
        char c = (char) p_args->data;
        sm_bsp_uart_rx_callback(lte_uart, (uint8_t*) &c, 1);
    }

    else if (p_args->event == UART_EVENT_TX_COMPLETE) {
        sm_bsp_uart_tx_callback(lte_uart);
    }
}
