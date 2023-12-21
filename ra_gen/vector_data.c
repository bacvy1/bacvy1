/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = sci_uart_rxi_isr, /* SCI3 RXI (Received data full) */
            [1] = sci_uart_txi_isr, /* SCI3 TXI (Transmit data empty) */
            [2] = sci_uart_tei_isr, /* SCI3 TEI (Transmit end) */
            [3] = sci_uart_eri_isr, /* SCI3 ERI (Receive error) */
            [4] = sci_uart_rxi_isr, /* SCI4 RXI (Received data full) */
            [5] = sci_uart_txi_isr, /* SCI4 TXI (Transmit data empty) */
            [6] = sci_uart_tei_isr, /* SCI4 TEI (Transmit end) */
            [7] = sci_uart_eri_isr, /* SCI4 ERI (Receive error) */
            [8] = sci_spi_rxi_isr, /* SCI2 RXI (Received data full) */
            [9] = sci_spi_txi_isr, /* SCI2 TXI (Transmit data empty) */
            [10] = sci_spi_tei_isr, /* SCI2 TEI (Transmit end) */
            [11] = sci_spi_eri_isr, /* SCI2 ERI (Receive error) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_SCI3_RXI), /* SCI3 RXI (Received data full) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_SCI3_TXI), /* SCI3 TXI (Transmit data empty) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_SCI3_TEI), /* SCI3 TEI (Transmit end) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_SCI3_ERI), /* SCI3 ERI (Receive error) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_SCI4_RXI), /* SCI4 RXI (Received data full) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_SCI4_TXI), /* SCI4 TXI (Transmit data empty) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_SCI4_TEI), /* SCI4 TEI (Transmit end) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_SCI4_ERI), /* SCI4 ERI (Receive error) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_SCI2_RXI), /* SCI2 RXI (Received data full) */
            [9] = BSP_PRV_IELS_ENUM(EVENT_SCI2_TXI), /* SCI2 TXI (Transmit data empty) */
            [10] = BSP_PRV_IELS_ENUM(EVENT_SCI2_TEI), /* SCI2 TEI (Transmit end) */
            [11] = BSP_PRV_IELS_ENUM(EVENT_SCI2_ERI), /* SCI2 ERI (Receive error) */
        };
        #endif
