/*
 * utils.c
 *
 *  Created on: Jun 29, 2022
 *      Author: Admin
 */

#include "utils.h"

uint8_t hex[22] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A',
		'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f' };
uint8_t byte_to_hex(uint8_t byte);
uint8_t byte_to_hex(uint8_t byte) {
	uint8_t _hex = 0;
	for (uint16_t i = 0; i < 22; i++) {
		if (byte == hex[i]) {
			if (i < 10) {
				_hex = byte - 48;
			} else if (i >= 10 && i < 16) {
				_hex = byte - 55;
			} else {
				_hex = byte - 87;
			}
		}
	}
	return _hex;
}

uint16_t  string_to_hex_bytes(char* data, uint16_t length,uint8_t *dest) {
	uint8_t *result = dest;
	uint16_t p_result = 0;
	if (length % 2 != 0) {

		for (uint16_t i = 0; i < length - 1; i = i + 2) {
			uint8_t high_byte = byte_to_hex((uint8_t)data[i]);
			uint8_t low_byte = byte_to_hex((uint8_t)data[i + 1]);
			result[p_result] = (uint8_t) (high_byte << 4 | low_byte);
			p_result++;
		}
	} else {
		for (uint16_t i = 0; i < length; i = i + 2) {
			uint8_t high_byte = byte_to_hex((uint8_t)data[i]);
			uint8_t low_byte = byte_to_hex((uint8_t)data[i + 1]);
			result[p_result] = (uint8_t) (high_byte << 4 | low_byte);
			p_result++;
		}
	}
	return p_result;
}
uint16_t byte_to_hardword(uint8_t* src){
	return (uint16_t)((uint16_t)src[0]<<8 | (uint16_t)src[1]);
}
uint32_t byte_to_word(uint8_t* src){
	uint32_t result = 0;
	for(uint16_t i = 0;i<4;i++){
		result = result | (uint32_t)src[i]<< 8*(3-i);
	}
	return result;
}
uint32_t byte_to_word_cr(uint8_t* src){
	uint32_t result = 0;
	for(uint16_t i = 0;i<4;i++){
		result = result | (uint32_t)src[i]<< 8*(i);
	}
	return result;
}
