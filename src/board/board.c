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


sm_bsp_io_t *lcd_rs_pin  = NULL;
sm_bsp_io_t *lcd_dc_pin  = NULL;
sm_bsp_io_t *lcd_cs_pin  = NULL;
sm_bsp_io_t *lcd_sck_pin = NULL;
sm_bsp_io_t *lcd_din_pin = NULL;

void board_init(void){
    R_IOPORT_Open(&g_ioport_ctrl, &g_bsp_pin_cfg);
    lte_rs_pin = sm_bsp_io_init(&io_func, (void*)&g_ioport, BSP_IO_PORT_00_PIN_02);
    lte_uart = sm_bsp_uart_init(&uart_func, (void*)&g_uart0);
    lte_uart->proc->open(lte_uart);

    lcd_rs_pin  = sm_bsp_io_init(&io_func, (void*)&g_ioport, LCD_RST);
    lcd_dc_pin  = sm_bsp_io_init(&io_func, (void*)&g_ioport, LCD_DC);
    lcd_cs_pin  = sm_bsp_io_init(&io_func, (void*)&g_ioport, LCD_CS);
    lcd_sck_pin = sm_bsp_io_init(&io_func, (void*)&g_ioport, LCD_SCK);
    lcd_din_pin = sm_bsp_io_init(&io_func, (void*)&g_ioport, LCD_DIN);
}


void set_time(struct tm *p_time){
    R_RTC_CalendarTimeSet(&g_rtc0_ctrl, p_time);
}

struct tm p_time;

struct tm* get_time(){
    R_RTC_CalendarTimeGet(&g_rtc0_ctrl, &p_time);
    return &p_time;
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


