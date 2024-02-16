/*
 * gps.c
 *
 *  Created on: Dec 23, 2021
 *      Author: Ha
 */

#include "l76_lb.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"
void l76_lb_split_nmea_message(char** fields, char* msg, char* delim_char){

    char** fields_buff = fields;
    char* msg_buff = msg;

    // Strtok can't use because dynamic allocation, so use strtok_r instead.
    while( (*fields_buff++ = strtok_r(msg_buff, delim_char, &msg_buff)) );
}
bool covert_lat_lon_to_float(char* str, float* output){
	float value;
	if(strcmp(str,"") == 0) return false;
	value = (float)(atof(str));
	int hour;
	float minute;
	if(value < 100.0000) return false;
	hour = (int)(value / 100);
	minute = (float)((value - (float)hour*100) / 60);
	*output = (float)hour + minute;
	return true;
}
//
//float l76_lb_convert_lat_to_float(char *lat_str, char *ns_field){
//    char hours[2];
//    char minutes[8];
//    float val;
//
//    memcpy( hours, lat_str, 2 );
//    memcpy( minutes, lat_str + 2 , strlen(lat_str) - 2 );
//
//    val = (float)atof(hours);
//    val += (float)atof(minutes)/60;
//
//    if(strcmp(ns_field, "S") == 0){
//        return -val;
//    }
//    return val;
//}

//float l76_lb_convert_lon_to_float(char *lon_str, char *we_field){
//    char hours[3];
//    char minutes[8];
//    float val;
//
//    memcpy( hours, lon_str, 3 );
//    memcpy( minutes, lon_str + 3 , strlen(lon_str) - 3 );
//
//    val = (float)atof(hours);
//    val += (float)atof(minutes)/60;
//
//    if(strcmp(we_field, "W") == 0){
//        return -val;
//    }
//    return val;
//}
