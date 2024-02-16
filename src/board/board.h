/*
 * board.h
 *
 *  Created on: Dec 20, 2023
 *      Author: My PC
 */

#ifndef BOARD_BOARD_H_
#define BOARD_BOARD_H_
#include "time.h"
void board_init(void);
void set_time(struct tm *p_time);
struct tm* get_time();
#endif /* BOARD_BOARD_H_ */
