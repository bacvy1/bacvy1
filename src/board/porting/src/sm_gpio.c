/*
 * io.c
 *
 *  Created on: Jul 10, 2023
 *      Author: Admin
 */

/*include mcu platform*/

/*end*/

#include "sm_bsp_io.h"

static int32_t gpio_open(sm_bsp_io_t *_this, sm_bsp_io_mode_t _mode);
static int32_t gpio_close(sm_bsp_io_t *_this);
static int32_t gpio_set_value(sm_bsp_io_t*, uint8_t);
static uint8_t gpio_get_value(sm_bsp_io_t*);

sm_bsp_io_proc_t io_func = { .close = gpio_close, .open = gpio_open,
		.set_value = gpio_set_value, .get_value = gpio_get_value };

static int32_t gpio_open(sm_bsp_io_t *_this, sm_bsp_io_mode_t _mode) {
	/*User code*/
	_this->mode = _mode;
	return 0;
}
static int32_t gpio_close(sm_bsp_io_t *_this) {
	/*User code*/
	return 0;
}
static int32_t gpio_set_value(sm_bsp_io_t *_this, uint8_t value) {
	/*User code*/
	return 0;
}
static uint8_t gpio_get_value(sm_bsp_io_t *_this) {
	/*User code*/
	return 0;
}
