/*
 * cli_task.c
 *
 *  Created on: Dec 16, 2022
 *      Author: Admin
 */




#include <sm_bsp_uart.h>
#include <sm_bsp_delay.h>
#include <sm_cli.h>
#include <sm_config.h>
#if USING_CLI
#include <cli_app.h>
extern sm_bsp_uart_t *debug_consol;

extern void cli_app_start(void);

extern void cli_app_main_loop(void* pvParameters);

extern void cli_app_on_data_received(uint8_t ch);

#define ACK_LENGTH      10
#define SEND_LENGTH     10

#define MS_TO_TICK(x) (x/10)

uint8_t SendBuffer[SEND_LENGTH] = { 0xab, 1, 2, 3, 4, 5, 6, 7, 8, 9 };


//static void cli_rx_task(void *arg);

#define BLINK_GPIO CONFIG_BLINK_GPIO

void cli_init(sm_bsp_uart_t *port)
{
    consol_init(port);
#if RTOS
    //xTaskCreate(cli_rx_task, "rx_task", 1024*4, NULL, configMAX_PRIORITIES, NULL);
    xTaskCreate(cli_process, "cli_task", 1024*10, NULL, 15, NULL);
#else
    cli_app_start();
#endif


}

//static void cli_rx_task(void *arg)
//{
//    uint8_t rxChar = 0;
//    uint8_t rxBytes = 0;
//
//    while (1) {
//        rxBytes = uart_read_bytes(CLI_PORT, &rxChar, 1, 10 / 10);
//        if (rxBytes == 1) {
//            cli_app_on_data_received(rxChar);
//        }
//        vTaskDelay(1);
//    }
//}

uint8_t cli_rx_buff[128];

void cli_process(void *arg)
{
    (void) arg;
    uint8_t rxBytes = 0;
#if(RTOS)
    cli_app_start();
    while (1) {
#endif
        rxBytes = (uint8_t)sm_bsp_uart_read(debug_consol,cli_rx_buff, 128);
        if (rxBytes > 1) {
            for(uint8_t i =0 ; i<rxBytes;i++)
                cli_app_on_data_received(cli_rx_buff[i]);
        }
        cli_app_main_loop(NULL);
        sm_bsp_delay_ms(1);
#if(RTOS)
    }
#endif
}
#endif
