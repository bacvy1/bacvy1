/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#include "r_ioport.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#define RESET_LCD (BSP_IO_PORT_01_PIN_03)
#define SPI_CS (BSP_IO_PORT_04_PIN_02)
extern const ioport_cfg_t g_bsp_pin_cfg; /* R7FA4M2AB3CFL.pincfg */

void BSP_PinConfigSecurityInit();

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif /* BSP_PIN_CFG_H_ */
