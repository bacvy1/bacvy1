/*
 * gps.h
 *
 *  Created on: Dec 23, 2021
 *      Author: Ha
 */

#ifndef COMPONENT_GPS_GPS_H_
#define COMPONENT_GPS_GPS_H_

#include "at_modem.h"
#include "l76lb_hw.h"

#define GPS_AT_MODEM_RX_BUFFER_SIZE         256
#define GPS_AT_MODEM_TX_BUFFER_SIZE         64

typedef enum GNRMC_FIELD{
    GNRMC_MID = 0,
    GNRMC_UTC,
    GNRMC_LAT,
    GNRMC_LAT_NS,
    GNRMC_LON,
    GNRMC_LON_EW,
    GNRMC_SOG,
    GNRMC_COG,
    GNRMC_DAT,
    GNRMC_MAV,
    GNRMC_MAV_EW,
    GNRMC_MOD
} GNRMC_FIELD;

typedef union Sys_time_t Sys_time;
union Sys_time_t{
  uint8_t array_time[7];
  struct {
    uint8_t year;
    uint8_t month;
    uint8_t date;
    uint8_t hour;
    uint8_t minute;
    uint8_t sec;
  } time;
};

typedef struct Realtime_t Realtime;


typedef struct L76_LB_t L76_LB;
struct L76_LB_t{
    AT_Modem    base;
    char*       desired_nmea_msg;
    uint8_t     desired_msg_len;
    bool 		gps_lat_lon_valid;
    char        nmea_msg_buffer[GPS_AT_MODEM_RX_BUFFER_SIZE];
    float       lat;
    float       lon;
    Sys_time    gps_time;
    GPS_hw*     p_hw;
    bool        is_new_msg;
};

void l76_lb_split_nmea_message(char** fields, char* msg, char* delim_char);
//float    l76_lb_convert_lat_to_float(char *lat_str, char *ns_field);
//float    l76_lb_convert_lon_to_float(char *lon_str, char *we_field);
bool covert_lat_lon_to_float(char* str, float* output);
#endif /* COMPONENT_GPS_GPS_H_ */
