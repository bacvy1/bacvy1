/*
 * display_app.c
 *
 *  Created on: Dec 21, 2023
 *      Author: My PC
 */
#include "display_app.h"
#include "air_sensor_app.h"
#include "hal_data.h"
#include "sm_porting.h"
extern sm_bsp_spi_t *lcd_spi;
extern sm_bsp_io_t *lcd_rs_pin;
extern sm_bsp_io_t *lcd_io_pin;
extern sm_bsp_io_t *lcd_cs_pin;

void display_app_init(){
    LCD* p_lcd = &air_sensor_app.lcd;
    LCD5110_init(p_lcd, lcd_spi, lcd_rs_pin, lcd_io_pin, lcd_cs_pin);
    LCD5110_clear(p_lcd);
    LCD5110_set_XY(p_lcd, 0, 0);
    LCD5110_write_string(p_lcd, "   LONG   ", 0);
    LCD5110_write_string(p_lcd, "  Comunity  ", 0);
    LCD5110_write_string(p_lcd, "-------------", 0);
}



