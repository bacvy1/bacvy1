/* generated HAL source file - do not edit */
#include "hal_data.h"
rtc_instance_ctrl_t g_rtc0_ctrl;
const rtc_error_adjustment_cfg_t g_rtc0_err_cfg =
{ .adjustment_mode = RTC_ERROR_ADJUSTMENT_MODE_AUTOMATIC,
  .adjustment_period = RTC_ERROR_ADJUSTMENT_PERIOD_10_SECOND,
  .adjustment_type = RTC_ERROR_ADJUSTMENT_NONE,
  .adjustment_value = 0, };
const rtc_cfg_t g_rtc0_cfg =
{ .clock_source = RTC_CLOCK_SOURCE_LOCO, .freq_compare_value_loco = 255, .p_err_cfg = &g_rtc0_err_cfg, .p_callback =
          NULL,
  .p_context = NULL, .alarm_ipl = (BSP_IRQ_DISABLED), .periodic_ipl = (BSP_IRQ_DISABLED), .carry_ipl = (12),
#if defined(VECTOR_NUMBER_RTC_ALARM)
    .alarm_irq               = VECTOR_NUMBER_RTC_ALARM,
#else
  .alarm_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_RTC_PERIOD)
    .periodic_irq            = VECTOR_NUMBER_RTC_PERIOD,
#else
  .periodic_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_RTC_CARRY)
    .carry_irq               = VECTOR_NUMBER_RTC_CARRY,
#else
  .carry_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const rtc_instance_t g_rtc0 =
{ .p_ctrl = &g_rtc0_ctrl, .p_cfg = &g_rtc0_cfg, .p_api = &g_rtc_on_rtc };
sci_uart_instance_ctrl_t g_uart1_ctrl;

baud_setting_t g_uart1_baud_setting =
        {
        /* Baud rate calculated with 0.469% error. */.semr_baudrate_bits_b.abcse = 0,
          .semr_baudrate_bits_b.abcs = 0, .semr_baudrate_bits_b.bgdm = 1, .cks = 1, .brr = 161, .mddr = (uint8_t) 256, .semr_baudrate_bits_b.brme =
                  false };

/** UART extended configuration for UARTonSCI HAL driver */
const sci_uart_extended_cfg_t g_uart1_cfg_extend =
{ .clock = SCI_UART_CLOCK_INT, .rx_edge_start = SCI_UART_START_BIT_FALLING_EDGE, .noise_cancel =
          SCI_UART_NOISE_CANCELLATION_DISABLE,
  .rx_fifo_trigger = SCI_UART_RX_FIFO_TRIGGER_1, .p_baud_setting = &g_uart1_baud_setting, .flow_control =
          SCI_UART_FLOW_CONTROL_RTS,
#if 0xFF != 0xFF
                .flow_control_pin       = BSP_IO_PORT_FF_PIN_0xFF,
                #else
  .flow_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
  .rs485_setting =
  { .enable = SCI_UART_RS485_DISABLE, .polarity = SCI_UART_RS485_DE_POLARITY_HIGH,
#if 0xFF != 0xFF
                    .de_control_pin = BSP_IO_PORT_FF_PIN_0xFF,
                #else
    .de_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
          }, };

/** UART interface configuration */
const uart_cfg_t g_uart1_cfg =
{ .channel = 4, .data_bits = UART_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits = UART_STOP_BITS_1, .p_callback =
          gps_callback,
  .p_context = NULL, .p_extend = &g_uart1_cfg_extend,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
  .rxi_ipl = (6),
  .txi_ipl = (6), .tei_ipl = (6), .eri_ipl = (6),
#if defined(VECTOR_NUMBER_SCI4_RXI)
                .rxi_irq             = VECTOR_NUMBER_SCI4_RXI,
#else
  .rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI4_TXI)
                .txi_irq             = VECTOR_NUMBER_SCI4_TXI,
#else
  .txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI4_TEI)
                .tei_irq             = VECTOR_NUMBER_SCI4_TEI,
#else
  .tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI4_ERI)
                .eri_irq             = VECTOR_NUMBER_SCI4_ERI,
#else
  .eri_irq = FSP_INVALID_VECTOR,
#endif
        };

/* Instance structure to use this module. */
const uart_instance_t g_uart1 =
{ .p_ctrl = &g_uart1_ctrl, .p_cfg = &g_uart1_cfg, .p_api = &g_uart_on_sci };
sci_uart_instance_ctrl_t g_uart0_ctrl;

baud_setting_t g_uart0_baud_setting =
        {
        /* Baud rate calculated with 0.469% error. */.semr_baudrate_bits_b.abcse = 0,
          .semr_baudrate_bits_b.abcs = 0, .semr_baudrate_bits_b.bgdm = 1, .cks = 0, .brr = 53, .mddr = (uint8_t) 256, .semr_baudrate_bits_b.brme =
                  false };

/** UART extended configuration for UARTonSCI HAL driver */
const sci_uart_extended_cfg_t g_uart0_cfg_extend =
{ .clock = SCI_UART_CLOCK_INT, .rx_edge_start = SCI_UART_START_BIT_FALLING_EDGE, .noise_cancel =
          SCI_UART_NOISE_CANCELLATION_DISABLE,
  .rx_fifo_trigger = SCI_UART_RX_FIFO_TRIGGER_1, .p_baud_setting = &g_uart0_baud_setting, .flow_control =
          SCI_UART_FLOW_CONTROL_RTS,
#if 0xFF != 0xFF
                .flow_control_pin       = BSP_IO_PORT_FF_PIN_0xFF,
                #else
  .flow_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
  .rs485_setting =
  { .enable = SCI_UART_RS485_DISABLE, .polarity = SCI_UART_RS485_DE_POLARITY_HIGH,
#if 0xFF != 0xFF
                    .de_control_pin = BSP_IO_PORT_FF_PIN_0xFF,
                #else
    .de_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
          }, };

/** UART interface configuration */
const uart_cfg_t g_uart0_cfg =
{ .channel = 3, .data_bits = UART_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits = UART_STOP_BITS_1, .p_callback =
          lte_callback,
  .p_context = NULL, .p_extend = &g_uart0_cfg_extend,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
  .rxi_ipl = (1),
  .txi_ipl = (2), .tei_ipl = (2), .eri_ipl = (2),
#if defined(VECTOR_NUMBER_SCI3_RXI)
                .rxi_irq             = VECTOR_NUMBER_SCI3_RXI,
#else
  .rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI3_TXI)
                .txi_irq             = VECTOR_NUMBER_SCI3_TXI,
#else
  .txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI3_TEI)
                .tei_irq             = VECTOR_NUMBER_SCI3_TEI,
#else
  .tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI3_ERI)
                .eri_irq             = VECTOR_NUMBER_SCI3_ERI,
#else
  .eri_irq = FSP_INVALID_VECTOR,
#endif
        };

/* Instance structure to use this module. */
const uart_instance_t g_uart0 =
{ .p_ctrl = &g_uart0_ctrl, .p_cfg = &g_uart0_cfg, .p_api = &g_uart_on_sci };
void g_hal_init(void)
{
    g_common_init ();
}
