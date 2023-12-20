/*
 * uart.c
 *
 *  Created on: Jul 10, 2023
 *      Author: Admin
 */


/*include mcu platform*/

/*end*/

#include "sm_bsp_uart.h"
#include "hal_data.h"
static    int32_t uart_write(sm_bsp_uart_t *_this,uint8_t* buff,uint32_t len);
static    int32_t uart_set_baudrate(sm_bsp_uart_t *_this,uint32_t baudrate);
static    int32_t uart_set_parity(sm_bsp_uart_t *_this,sm_uart_parity_t parity);
static    int32_t uart_set_databit(sm_bsp_uart_t *_this,sm_uart_databit_t databit);
static    int32_t uart_open(sm_bsp_uart_t *_this);
static    int32_t uart_close(sm_bsp_uart_t *_this);
static    int32_t uart_abort_rx(sm_bsp_uart_t *_this);
static    int32_t uart_abort_tx(sm_bsp_uart_t *_this);

sm_bsp_uart_proc_t uart_func = {.write = uart_write,.set_baudrate = uart_set_baudrate,
                                .set_parity = uart_set_parity,.set_databit = uart_set_databit,
                                .open = uart_open,.close = uart_close,.abort_rx = uart_abort_rx,.abort_tx = uart_abort_tx};

static    int32_t uart_write(sm_bsp_uart_t *_this,uint8_t* buff,uint32_t len){
    /*User code*/
    uart_instance_t *p_uart = (uart_instance_t*) _this->handle;
    return R_SCI_UART_Write(p_uart->p_ctrl, buff, len);
}
static    int32_t uart_set_baudrate(sm_bsp_uart_t *_this,uint32_t baudrate){
    /*User code*/
    return 0;
}
static    int32_t uart_set_parity(sm_bsp_uart_t *_this,sm_uart_parity_t parity){
    /*User code*/
    return 0;
}
static    int32_t uart_set_databit(sm_bsp_uart_t *_this,sm_uart_databit_t databit){
    /*User code*/
    return 0;
}
static    int32_t uart_open(sm_bsp_uart_t *_this){
    /*User code*/
    uart_instance_t *p_uart = (uart_instance_t*) _this->handle;
    return R_SCI_UART_Open(p_uart->p_ctrl, p_uart->p_cfg);
}
static    int32_t uart_close(sm_bsp_uart_t *_this){
    /*User code*/
    uart_instance_t *p_uart = (uart_instance_t*) _this->handle;
    return R_SCI_UART_Close(p_uart->p_ctrl);
}
static    int32_t uart_abort_rx(sm_bsp_uart_t *_this){
    /*User code*/
    uart_instance_t *p_uart = (uart_instance_t*) _this->handle;
    return R_SCI_UART_Abort(p_uart->p_ctrl, UART_DIR_TX);
}
static    int32_t uart_abort_tx(sm_bsp_uart_t *_this){
    /*User code*/
    uart_instance_t *p_uart = (uart_instance_t*) _this->handle;
    return R_SCI_UART_Abort(p_uart->p_ctrl, UART_DIR_RX);
}
