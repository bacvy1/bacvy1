/*
 * utils.h
 *
 *  Created on: Jun 29, 2022
 *      Author: Admin
 */

#ifndef FLASHFIRMWAREAPP_SERVICE_UTILS_H_
#define FLASHFIRMWAREAPP_SERVICE_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

typedef union
{
    uint32_t word;
    uint8_t byte[4];
} word_to_byte_t;

typedef union
{
    uint16_t haftword;
    uint8_t byte[2];
} haftword_to_byte_t;

uint16_t string_to_hex_bytes(char *data, uint16_t length, uint8_t *dest);
uint16_t byte_to_hardword(uint8_t *src);
uint32_t byte_to_word(uint8_t *src);
uint32_t byte_to_word_cr(uint8_t *src);

#ifdef __cplusplus
}
#endif

#endif /* FLASHFIRMWAREAPP_SERVICE_UTILS_H_ */
