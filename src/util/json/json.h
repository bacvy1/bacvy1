/*
 * json.h
 *
 *  Created on: Oct 7, 2020
 *      Author: quangnd
 */

#ifndef UTIL_JSON_JSON_H_
#define UTIL_JSON_JSON_H_
#include "stdint.h"
#include "stdbool.h"

char* json_from_string(char* buff,const char* name,const char* str);
char* json_from_string_no_quote(char* buff, const char* name, const char* str);
char* json_from_long(char* buff, const char* name, const int32_t val);
char* json_from_float(char* buff, const char* name, const float val, uint8_t after_point);
char* json_open(char* buff);
char* json_close(char* buff);
char* json_from_long_array(char* buff,const char* name,const uint32_t* val,const uint16_t size);
char* json_from_uint_array(char* buff, const char* name, const uint16_t* val, const uint16_t size);
char* json_from_slong_array(char* buff,const char* name,const int32_t* val,const uint16_t size);
char* json_from_uchar_array(char* buff,const char* name,const uint8_t* val,const uint16_t size);
char* json_from_schar_array(char* buff,const char* name,const int8_t* val,const uint16_t size);
char* json_open_object(char* buff, char* name);
char* json_close_object(char* buff);
char* json_from_boolean(char* buff, const char* name, const bool value);

#endif /* UTIL_JSON_JSON_H_ */
