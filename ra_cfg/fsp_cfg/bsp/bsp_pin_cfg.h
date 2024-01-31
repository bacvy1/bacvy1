/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#include "r_ioport.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#define DHT_PIN (BSP_IO_PORT_00_PIN_15)
#define DUST_EN (BSP_IO_PORT_01_PIN_00)
#define LED1 (BSP_IO_PORT_01_PIN_01)
#define LCD_RST (BSP_IO_PORT_01_PIN_03)
#define LCD_DC (BSP_IO_PORT_01_PIN_04)
#define LCD_SCK (BSP_IO_PORT_01_PIN_11)
#define LED2 (BSP_IO_PORT_03_PIN_01)
#define LCD_DIN (BSP_IO_PORT_03_PIN_02)
#define LCD_CS (BSP_IO_PORT_04_PIN_02)
#define LED3 (BSP_IO_PORT_04_PIN_07)
extern const ioport_cfg_t g_bsp_pin_cfg; /* R7FA4M2AB3CFL.pincfg */

void BSP_PinConfigSecurityInit();

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif /* BSP_PIN_CFG_H_ */
