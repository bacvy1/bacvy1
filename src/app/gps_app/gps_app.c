/*
 * gps_app.c
 *
 *  Created on: Mar 10, 2022
 *      Author: khanh
 */

#include "gps_app.h"
#include "air_sensor_app.h"

static char  gps_at_modem_rx_buffer[GPS_AT_MODEM_RX_BUFFER_SIZE];
static char  gps_at_modem_tx_data_buffer[GPS_AT_MODEM_TX_BUFFER_SIZE];

static void gps_hw_receive_handle_impl(GPS_hw* p_hw);



void gps_app_init(void){
    L76_LB* p_gps = &air_sensor_app.gps;

    p_gps->base.rx_res_buffer = gps_at_modem_rx_buffer;
    p_gps->base.rx_res_buffer_size = GPS_AT_MODEM_RX_BUFFER_SIZE;
    p_gps->base.tx_data_buff = gps_at_modem_tx_data_buffer;

    p_gps->p_hw = &gps_hw;
    p_gps->p_hw->receive_handle = gps_hw_receive_handle_impl;

    p_gps->desired_nmea_msg = "$GNGGA";
    p_gps->desired_msg_len = (uint8_t)strlen(p_gps->desired_nmea_msg);
    p_gps->is_new_msg = false;

    gps_hw_init();
}

static void gps_hw_receive_handle_impl(GPS_hw* p_hw){

    uint16_t* p_id = &air_sensor_app.gps.base.rx_res_index;

    memcpy(air_sensor_app.gps.base.rx_res_buffer + *p_id, &p_hw->rx_data, 1);
    (*p_id)++;

    if( *p_id >= air_sensor_app.gps.desired_msg_len ){
        if( p_hw->rx_data == '\r' || p_hw->rx_data == '\n'){
            air_sensor_app.gps.base.rx_res_buffer[*p_id-1] = '\0';

            if(!air_sensor_app.gps.is_new_msg){
                memcpy(air_sensor_app.gps.nmea_msg_buffer, air_sensor_app.gps.base.rx_res_buffer, *p_id-1);
                air_sensor_app.gps.is_new_msg = true;
            }

            *p_id = 0;
        }
    }

    else if( p_hw->rx_data != air_sensor_app.gps.desired_nmea_msg[*p_id-1] ){
        *p_id = 0;
        return;
    }
}
