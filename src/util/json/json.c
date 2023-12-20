/*
 * json.c
 *
 *  Created on: Oct 7, 2020
 *      Author: quangnd
 */
#include "json.h"
#include "string_util.h"
#include "string.h"
#include "stdio.h"
#include "math.h"

#define TEMP_BUFF_SIZE			32

static char* json_from_ulong(char* buff,const char* name,const uint32_t val);
static char* json_from_slong(char* buff,const char* name, const int32_t val);

char* json_open(char* buff){
        *buff++='{';
        return (buff);
}

char* json_close(char* buff){
        *buff++='}';
        *buff='\0';
        return (buff);
}

char* json_open_object(char* buff, char* name){
    *buff++='"';
    while(*name){
            *buff++=*name++;
    }
    *buff++='"';
    *buff++=':';
    return buff;
}

char* json_close_object(char* buff){
    *buff++='}';
    return buff;
}

char* json_from_string(char* buff, const char* name, const char* str){

        *buff++='"';
        while(*name){
                *buff++=*name++;
        }
        *buff++='"';
        *buff++=':';
        *buff++='"';
        while(*str){
                *buff++=*str++;
        }
        *buff++='"';
        return (buff);
}

char* json_from_string_no_quote(char* buff, const char* name, const char* str){

    *buff++='"';
    while(*name){
            *buff++=*name++;
    }
    *buff++='"';
    *buff++=':';
    if(*str == '\0'){
        *buff++='0';
        return (buff);
    }
    while(*str){
            *buff++=*str++;
    }
    return (buff);
}

static char* json_from_ulong(char* buff,const char* name,const uint32_t val){

	char val_buff[TEMP_BUFF_SIZE]={0};
	long_to_string(val,val_buff);
	*buff++='"';
	while(*name){
	        *buff++=*name++;
	}
	*buff++='"';
	*buff++=':';
	char* val_str=val_buff;
	while(*val_str){
	        *buff++=*val_str++;
	}
	return (buff);
}

char* json_from_float(char* buff, const char* name, const float val, uint8_t after_point){

    uint32_t i_part = (uint32_t)val;
    float   f_part = val - (float)i_part;

    *buff++='"';
    while(*name){
        *buff++=*name++;
    }
    *buff++='"';
    *buff++=':';
    buff+=long_to_string(i_part, buff);
    *buff++='.';

    uint32_t f_part_to_int = (uint32_t)(f_part*pow(10, after_point+1));

    uint8_t index = (uint8_t)long_to_string(f_part_to_int, buff)-1;
    if(index < after_point){
        memset(buff, '0', after_point - index);
        buff+=after_point - index;
    }
    buff+=long_to_string(f_part_to_int, buff);
    return (buff);
}

static char* json_from_slong(char* buff,const char* name,const int32_t val){

    char val_buff[TEMP_BUFF_SIZE]={0};
    long_to_string((uint32_t)-val,val_buff);
    *buff++='"';
    while(*name){
            *buff++=*name++;
    }
    *buff++='"';
    *buff++=':';
    *buff++='-';
    char* val_str=val_buff;
    while(*val_str){
            *buff++=*val_str++;
    }
    return (buff);
}

char* json_from_long(char* buff, const char* name, const int32_t val){

   if(val < 0){
       return json_from_slong(buff, name, val);
   }
   else return json_from_ulong(buff, name, (uint32_t)val);
}

char* json_from_long_array(char* buff,const char* name,const uint32_t* val,const uint16_t size){

        char val_buff[TEMP_BUFF_SIZE]={0};
	char* val_str;
	*buff++='"';
	while(*name){
	        *buff++=*name++;
	}
	*buff++='"';
	*buff++=':';
	*buff++='[';
	for(int i=0;i<size;i++){
	        long_to_string(val[i],val_buff);
	        val_str=val_buff;
	        while(*val_str){
	                *buff++=*val_str++;
	        }
	        *buff++=',';
	}
	buff--;
	*buff++=']';
	return (buff);
}

char* json_from_uint_array(char* buff, const char* name, const uint16_t* val, const uint16_t size){
	char val_buff[TEMP_BUFF_SIZE]={0};
		char* val_str;
		*buff++='"';
		while(*name){
		        *buff++=*name++;
		}
		*buff++='"';
		*buff++=':';
		*buff++='[';
		for(int i=0;i<size;i++){
		        long_to_string((uint32_t)val[i],val_buff);
		        val_str=val_buff;
		        while(*val_str){
		                *buff++=*val_str++;
		        }
		        *buff++=',';
		}
		buff--;
		*buff++=']';
		return (buff);
}
char* json_from_slong_array(char* buff,const char* name,const int32_t* val,const uint16_t size){

        char val_buff[TEMP_BUFF_SIZE]={0};
	char* val_str;
	*buff++='"';
	while(*name){
	        *buff++=*name++;
	}
	*buff++='"';
	*buff++=':';
	*buff++='[';
	for(int i=0;i<size;i++){
	        slong_to_string(val[i],val_buff);
	        val_str=val_buff;
	        while(*val_str){
	                *buff++=*val_str++;
	        }
	        *buff++=',';
	}
	buff--;
	*buff++=']';
	return (buff);
}

char* json_from_uchar_array(char* buff,const char* name,const uint8_t* val,const uint16_t size){

        char val_buff[TEMP_BUFF_SIZE]={0};
	char* val_str;
	*buff++='"';
	while(*name){
	        *buff++=*name++;
	}
	*buff++='"';
	*buff++=':';
	*buff++='[';
	for(int i=0;i<size;i++){
	        long_to_string(val[i],val_buff);
	        val_str=val_buff;
	        while(*val_str){
	                *buff++=*val_str++;
	        }
	        *buff++=',';
	}
	buff--;
	*buff++=']';
	return (buff);
}

char* json_from_schar_array(char* buff,const char* name,const int8_t* val,const uint16_t size){

    char val_buff[TEMP_BUFF_SIZE]={0};
	char* val_str;
	*buff++='"';
	while(*name){
	        *buff++=*name++;
	}
	*buff++='"';
	*buff++=':';
	*buff++='[';
	for(int i=0;i<size;i++){
	        slong_to_string(val[i], val_buff);
	        val_str=val_buff;
	        while(*val_str){
	                *buff++=*val_str++;
	        }
	        *buff++=',';
	}
	buff--;
	*buff++=']';
	return (buff);
}

char* json_from_boolean(char* buff, const char* name, const bool value){
    *buff++='"';
    while(*name){
            *buff++=*name++;
    }
    *buff++='"';
    *buff++=':';
    if(value == true){
        strcat(buff, "true");
        buff+=4;
    }
    else{
        strcat(buff, "false");
        buff+=5;
    }
    return (buff);
}


