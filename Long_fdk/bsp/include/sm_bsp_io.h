//
// Created by vnbk on 20/06/2023.
//

#ifndef SM_BSP_IO_H
#define SM_BSP_IO_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
/**
 * @enum
 * @brief
 *
 */
typedef enum {
	SM_BSP_IO_OFF = 0,/**< SM_BSP_IO_OFF */
	SM_BSP_IO_ON /**< SM_BSP_IO_ON */
} sm_bsp_io_value_t;


typedef enum {
	SM_BSP_IO_INPUT = 0, /**< SM_BSP_IO_INPUT*/
	SM_BSP_IO_OUTPUT /**< SM_BSP_IO_OUTPUT*/
} sm_bsp_io_mode_t;
typedef struct sm_bsp_io sm_bsp_io_t;
/**
 * @struct sm_bsp_io_proc
 * @brief
 *
 */
typedef struct sm_bsp_io_proc
{
    int32_t (*open)(sm_bsp_io_t *_this, sm_bsp_io_mode_t _mode);
    int32_t (*close)(sm_bsp_io_t *_this);
    int32_t (*set_value)(sm_bsp_io_t*, uint8_t);
    uint8_t (*get_value)(sm_bsp_io_t*);
    int32_t (*set_mod)(sm_bsp_io_t *_this, sm_bsp_io_mode_t _mode);
} sm_bsp_io_proc_t;
/**
 * @struct sm_bsp_io
 * @brief
 *
 */

struct sm_bsp_io {
	sm_bsp_io_proc_t *proc;
	void *handle; // gpio_port
	uint16_t pin;
	sm_bsp_io_mode_t mode;
};
/**
 * @fn sm_bsp_io_t sm_bsp_io_init*(sm_bsp_io_proc_t*, void*, uint16_t)
 * @brief
 *
 * @param m_proc
 * @param handle
 * @param pin
 * @return
 */
sm_bsp_io_t* sm_bsp_io_init(sm_bsp_io_proc_t *_proc, void *_handle,
		uint16_t _pin);
/**
 * @fn void sm_bsp_io_deinit(sm_bsp_io_t*)
 * @brief
 *
 * @param _this
 */
void sm_bsp_io_deinit(sm_bsp_io_t *_this);
/**
 * @fn int32_t sm_bsp_io_set_value(sm_bsp_io_t*, uint8_t)
 * @brief
 *
 * @param _this
 * @param level
 * @return
 */
int32_t sm_bsp_io_set_value(sm_bsp_io_t *_this, uint8_t _level);
/**
 * @fn uint8_t sm_bsp_io_get_value(sm_bsp_io_t*)
 * @brief
 *
 * @param _this
 * @return
 */
uint8_t sm_bsp_io_get_value(sm_bsp_io_t *_this);
/**
 * @fn int32_t sm_bsp_io_open(sm_bsp_io_t*)
 * @brief
 *
 * @param _this
 * @return
 */
int32_t sm_bsp_io_open(sm_bsp_io_t *_this, sm_bsp_io_mode_t _mode);
/**
 * @fn int32_t sm_bsp_io_close(sm_bsp_io_t*)
 * @brief
 *
 * @param _this
 * @return
 */
int32_t sm_bsp_io_close(sm_bsp_io_t *_this);
/**
 * @fn int32_t sm_bsp_io_set_mode(sm_bsp_io_t *, sm_bsp_io_mode_t);
 * @brief
 *
 * @param _this
 * @return
 */
int32_t sm_bsp_io_set_mode(sm_bsp_io_t *_this, sm_bsp_io_mode_t _mode);
#ifdef __cplusplus
};
#endif

#endif //SM_BSP_IO_H
