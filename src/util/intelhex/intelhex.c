/*
 * intelhex.c
 *
 *  Created on: Jun 29, 2022
 *      Author: Admin
 */


#include "intelhex.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "utils.h"

//#include "flash.h"

intel_hex my_intel_data;
uint8_t my_data[100];
uint8_t hex_data[100];
intel_hex my_hex;

intel_hex* intel_hex_process(uint8_t* data, uint16_t length){
	intel_hex* result = &my_hex;
	if(data[0] == ':'){
		uint16_t _index = 0;
		memset(hex_data,0,100);
		hex_data[0] = data[0];
		string_to_hex_bytes((char*)data+1, length-1,hex_data+1);
		result->start_code = hex_data[_index++];
		result->byte_count = hex_data[_index++];
		uint8_t addr[2];
		addr[0] = hex_data[_index++];
		addr[1] = hex_data[_index++];

		result->addr = ((uint16_t)addr[0] << 8) |((uint16_t) addr[1]);
		result->record_type = hex_data[_index++];
		memset(my_data,0,100);
		result->data = my_data;
		for(uint16_t i = 0;i<result->byte_count;i++){
			result->data[i] = hex_data[_index++];
		}
		result->checksum = hex_data[_index++];
		uint16_t crc = intel_hex_checksum(hex_data,_index);
		if(result->checksum != crc){
			return NULL;
		}
	}
	return result;
}
uint8_t intel_hex_checksum(uint8_t* data, uint16_t length){
	uint8_t intel_crc = 0;
	for(uint16_t i = 1;i<length-1;i++){
		intel_crc += data[i];
	}
	intel_crc = ~intel_crc + 1;
	return intel_crc;
}
void intel_hex_print(intel_hex *p_intel_hex){
	printf("Intel hex record type: %d\n",p_intel_hex->record_type);
	printf("Intel hex record addr: 0x%04X\n",p_intel_hex->addr);
	printf("Intel hex record data: ");
	for(uint8_t i = 0;i<p_intel_hex->byte_count;i++){
		printf("0x%02X ",p_intel_hex->data[i]);
	}
	printf("\nIntel hex record checksum: 0x%02X\r\n",p_intel_hex->checksum);
}
