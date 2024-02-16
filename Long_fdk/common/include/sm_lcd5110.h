/*
 * sm_lcd5110.h
 *
 *  Created on: Dec 21, 2023
 *      Author: My PC
 */

#ifndef INCLUDE_SM_LCD5110_H_
#define INCLUDE_SM_LCD5110_H_

#include "sm_bsp_spi.h"
#include "sm_bsp_io.h"

#define LCD_COMMAND 0
#define LCD_DATA 1
typedef struct LCD_t LCD;
struct LCD_t{
    sm_bsp_io_t *rs_pin;
    sm_bsp_io_t *dc_pin;
    sm_bsp_io_t *cs_pin;
    sm_bsp_io_t *sck_pin;
    sm_bsp_io_t *din_pin;
};

void LCD5110_init(LCD* p_lcd);

void LCD5110_write_char(LCD* p_lcd, unsigned char c);

void LCD5110_write_char_inv(LCD* p_lcd, unsigned char c);

void LCD5110_clear(LCD* p_lcd);

void LCD5110_set_XY(LCD* p_lcd, unsigned char X, unsigned char Y);

void LCD5110_write_string(LCD* p_lcd, char *s, int color);

void LCD5110_Write_Dec(LCD* p_lcd, unsigned int buffer, int amount_num, int color);

void LCD5110_Led(LCD* p_lcd, unsigned char c);



#endif /* INCLUDE_SM_LCD5110_H_ */
