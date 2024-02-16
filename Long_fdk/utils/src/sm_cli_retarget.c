/*******************************************************************************
 *  @FILE NAME:    button.cpp
 *  @DESCRIPTION:  This file for button process
 *
 *  Copyright (c) 2019 BTM Technologies.
 *  All Rights Reserved This program is the confidential and proprietary
 *  product of BTM Technologies. Any Unauthorized use, reproduction or transfer
 *  of this program is strictly prohibited.
 *
 *  @Author: ManhBT
 *  @NOTE:   No Note at the moment
 *  @BUG:    No known bugs.
 *
 *<pre>
 *  MODIFICATION HISTORY:
 *
 *  Ver   Who       Date                Changes
 *  ----- --------- ------------------  ----------------------------------------
 *  1.00  ManhBT    Jun 12, 2019        First release
 *
 *
 *</pre>
*******************************************************************************/

/***************************** Include Files *********************************/
#include <sm_cli_fifo.h>
#include <sm_cli_retarget.h>
#include "sm_bsp_uart.h"

#if USING_CLI

/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/

/********************** Internal Function Prototypes *************************/

/************************** Variable Definitions *****************************/
fifo_t shell_fifo;
uint8_t shell_rx_buffer[128] = {0};
uint8_t u8RxByte = 0;

FILE __stdout;
FILE __stdin;
/********************* Exported Function Definitions *************************/\

/* HAL_UART Callback, available on STM32 platform only */
sm_bsp_uart_t *debug_consol;

void consol_init(sm_bsp_uart_t *consol){
    debug_consol = consol;
}

/**
 * @brief      Initialize FIFO
 *
 * @return     { description_of_the_return_value }
 */
int retarget_init(void) {
  fifo_create( &shell_fifo,
               shell_rx_buffer,
               sizeof(shell_rx_buffer)/sizeof(uint8_t),
               sizeof(uint8_t)
             );

  return 0;
}


int serial_get_char(uint8_t *c) {
  uint8_t item = 0;

  if (fifo_is_empty(&shell_fifo) == 1) {
    return 0;
  }

  if(fifo_get(&shell_fifo, &item) == 1) {
    *c = item;
    return 1;
  }

  return 0;
}

/* Basic IO putchar/getchar functions */

uint8_t __io_putchar(uint8_t ch)
{
    sm_bsp_uart_write(debug_consol,(uint8_t*)&ch,1);
	return ch;
}

uint8_t __io_getchar(void)
{
	uint8_t ch;
  int ret = serial_get_char((uint8_t*)&ch);

  return (ret == 1) ? ch : 0;
}

void on_uart_data_received(uint8_t ch) {
  if(!fifo_add(&shell_fifo, (const void *)&ch)) {
    printf("err");
  }
}

#if defined(__CC_ARM) ||  defined(__ICCARM__)
int fgetc(FILE * p_file)
{
  int ch = 0;
  return (serial_get_char((uint8_t*)&ch) == 1) ? ch : 0;
}


int fputc(int ch, FILE * p_file)
{
    __io_putchar(ch);
    return ch;
}
#elif defined(__GNUC__)

int _read(int file, char *ptr, int len)
{
  int DataIdx;

  for (DataIdx = 0; DataIdx < len; DataIdx++) {
    *ptr++ = __io_getchar();
  }

  return len;
}

int _write(int file, char *ptr, int len)
{
	int DataIdx;

	for (DataIdx = 0; DataIdx < len; DataIdx++)
	{
		__io_putchar(*ptr++);
	}
  return len;
}

#endif

#endif


/********************* Internal Function Definitions *************************/

/*****************************************************************************/
