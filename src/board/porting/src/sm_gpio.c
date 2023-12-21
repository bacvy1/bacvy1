/*
 * io.c
 *
 *  Created on: Jul 10, 2023
 *      Author: Admin
 */

/*include mcu platform*/

/*end*/

#include "sm_bsp_io.h"
#include "hal_data.h"
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
    ioport_instance_t *gpio = (ioport_instance_t*) _this;
    fsp_err_t err = R_IOPORT_PinWrite(gpio->p_ctrl,_this->pin,(bsp_io_level_t)value);
    return err;
	return 0;
}
static uint8_t gpio_get_value(sm_bsp_io_t *_this) {
	/*User code*/
    ioport_instance_t *gpio = (ioport_instance_t*) _this;
    uint8_t value = 0;
    R_IOPORT_PinRead(gpio->p_ctrl, _this->pin,&value);
    return value;
	return 0;
}
