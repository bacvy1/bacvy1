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
#include "stdint.h"
static void task_bar_display();
static void Temp_display();
static void Humidity_display();
static void CO_ppm_display();
static void DUST_display();
static void gps_display();
static void clock_display();
extern sm_bsp_io_t *lcd_rs_pin;
extern sm_bsp_io_t *lcd_dc_pin;
extern sm_bsp_io_t *lcd_cs_pin;
extern sm_bsp_io_t *lcd_sck_pin;
extern sm_bsp_io_t *lcd_din_pin;


void display_app_init(){
    LCD* p_lcd = &air_sensor_app.lcd;
    p_lcd->cs_pin = lcd_cs_pin;
    p_lcd->rs_pin = lcd_rs_pin;
    p_lcd->dc_pin = lcd_dc_pin;
    p_lcd->sck_pin = lcd_sck_pin;
    p_lcd->din_pin = lcd_din_pin;
    LCD5110_init(p_lcd);
    LCD5110_clear(p_lcd);
}
void display_process(){
    task_bar_display();
    Temp_display();
    Humidity_display();
    CO_ppm_display();
    DUST_display();
    gps_display();
    clock_display();
}

static void task_bar_display(){
    LCD* p_lcd = &air_sensor_app.lcd;
    LCD5110_set_XY(p_lcd, 0, 12);
    if(sm_mqtt_client_get_state(air_sensor_app.mqtt_client) == MQTT_ST_CONNECTED){
        LCD5110_write_string(p_lcd, "4G", 0);
    }
    else{
        LCD5110_write_string(p_lcd, "  ", 0);
    }
}

static void Temp_display(){
    LCD* p_lcd = &air_sensor_app.lcd;
    LCD5110_set_XY(p_lcd, 1, 0);
    LCD5110_write_string(p_lcd, "Temp:", 0);
}

static void Humidity_display(){
    LCD* p_lcd = &air_sensor_app.lcd;
    LCD5110_set_XY(p_lcd, 1, 7);
    LCD5110_write_string(p_lcd, "Humi:", 0);
}

static void CO_ppm_display(){
    LCD* p_lcd = &air_sensor_app.lcd;
    LCD5110_set_XY(p_lcd, 2, 0);
    LCD5110_write_string(p_lcd, "CO_ppm: ", 0);
}

static void DUST_display(){
    LCD* p_lcd = &air_sensor_app.lcd;
    LCD5110_set_XY(p_lcd, 3, 0);
    LCD5110_write_string(p_lcd, "PM2.5: ", 0);
}

static void gps_display(){
    LCD* p_lcd = &air_sensor_app.lcd;
//    char lat_str[14];
//    char lon_str[14];
    LCD5110_set_XY(p_lcd, 4, 0);
//    sprintf(lat_str, "lat: 21.0371895", air_sensor_app.gps.lat);
//    sprintf(lon_str, "lon: 105.788353", air_sensor_app.gps.lon);
    LCD5110_write_string(p_lcd, "lat:21.0371895", 0);
    LCD5110_set_XY(p_lcd, 5, 0);
    LCD5110_write_string(p_lcd, "lon:105.788353", 0);
}

static void clock_display(){
    LCD* p_lcd = &air_sensor_app.lcd;
    LCD5110_set_XY(p_lcd, 0, 4);
    char clock_buff[20];
    sprintf(clock_buff, "%d:%d", air_sensor_app.time.tm_hour, air_sensor_app.time.tm_min);
    LCD5110_write_string(p_lcd, clock_buff, 0);
}

