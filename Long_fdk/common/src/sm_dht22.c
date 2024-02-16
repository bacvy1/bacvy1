/*
 * sm_dht22.c
 *
 *  Created on: Dec 25, 2023
 *      Author: My PC
 */
#include "sm_dht22.h"
#include "sm_bsp_delay.h"
static void dht_pin_write(DHT22* p_dht, unsigned char state);
static void dht_pin_mode(DHT22* p_dht, sm_bsp_io_mode_t mode);
static uint8_t dht_pin_read(DHT22* p_dht);

static uint8_t sm_dht22_read(DHT22* p_dht);
static uint8_t  sm_dht22_start(DHT22* p_dht);


void sm_dht22_init(DHT22* p_dht, sm_bsp_io_t* dht_pin){
    p_dht->dht_pin = dht_pin;
}
static uint8_t sm_dht22_start(DHT22* p_dht){
    uint8_t Response = 0;
    uint16_t counter = 0;
    dht_pin_mode(p_dht, SM_BSP_IO_OUTPUT);
    dht_pin_write(p_dht, 0);
    sm_bsp_delay_us(1300);
    dht_pin_write(p_dht, 1);
    sm_bsp_delay_us(30);
    dht_pin_mode(p_dht, SM_BSP_IO_INPUT);
    sm_bsp_delay_us(40);
    if(!(dht_pin_read(p_dht))){
        sm_bsp_delay_us(80);
        if(dht_pin_read(p_dht)){
            Response = 1;
        }
    }
    while(dht_pin_read(p_dht) && counter < 1000){
        counter++;
    }
    counter = 0;
    return Response;
}

static uint8_t sm_dht22_read(DHT22* p_dht){
    uint8_t x,y;
    uint16_t counter = 0;
    for (x = 0; x < 8; x++){
        while(!(dht_pin_read(p_dht)) && counter < 1000){
            counter++;
        }
        counter = 0;
        sm_bsp_delay_us(40);
        if(!(dht_pin_read(p_dht))){
            y &= ~(1 << (7 - x));
        }
        else{
            y |= (1 << (7 - x));
        }

        while(dht_pin_read(p_dht) && counter < 1000){
            counter++;
        }
        counter = 0;
    }
    return y;
}

void sm_dht22_process(DHT22* p_dht){
    uint8_t hum1, hum2, tempC1, tempC2;
    uint8_t SUM, CHECK;
    float temp_Celsius, temp_Fahrenheit, Humidity;
    if(sm_dht22_start(p_dht)){
        hum1 = sm_dht22_read(p_dht);
        hum2 = sm_dht22_read(p_dht);
        tempC1 = sm_dht22_read(p_dht);
        tempC2 = sm_dht22_read(p_dht);

        SUM = sm_dht22_read(p_dht);
        CHECK = (uint8_t)(hum1 + hum2 + tempC1 + tempC2) & 0xFF;
        if(CHECK == SUM){
            if (tempC1>127)
            {
              temp_Celsius = (float)tempC2/10*(-1);
            }
            else
            {
              temp_Celsius = (float)((tempC1<<8)|tempC2);
            }
            temp_Fahrenheit = temp_Celsius * 9/5 + 32;
            Humidity = (float) ((hum1<<8)|hum2);

            p_dht->temperature = (float)(temp_Celsius/10);
            p_dht->humidity = Humidity/10;
        }

    }
    vTaskDelay(1000);
}

static void dht_pin_write(DHT22* p_dht, unsigned char state){
    p_dht->dht_pin->proc->set_value(p_dht->dht_pin, state);
}
static void dht_pin_mode(DHT22* p_dht, sm_bsp_io_mode_t mode){
    p_dht->dht_pin->proc->set_mod(p_dht->dht_pin, mode);
}
static uint8_t dht_pin_read(DHT22* p_dht){
    return p_dht->dht_pin->proc->get_value(p_dht->dht_pin);
}
