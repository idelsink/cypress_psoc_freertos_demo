/**
 * @file uart_driver.h
 * @brief Write-and-forget USART serial output driver layer
 * @author Ingmar Delsink
 * 
 * Currently supports multi-channel serial output.
 * Output data is buffered in a FIFO queue and pushed
 * out efficiently with interrupt service routines.
 */

#ifndef __UART_DRIVER_H
#define __UART_DRIVER_H

/** @brief Initialize USART peripheral for debug channel */
void UART_Driver_Debug_Init(void);

/** @brief De-activate all USART peripherals */    
void UART_Driver_Debug_DeInit(void);

#endif
