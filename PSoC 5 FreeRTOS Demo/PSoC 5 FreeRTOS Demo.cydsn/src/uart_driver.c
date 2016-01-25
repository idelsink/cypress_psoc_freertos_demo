/* ========================================
 *
 * Copyright CLS LED, 2015
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF CLS LED.
 *
 * ========================================
*/
/**
 * @file uart_driver.c
 * @brief Implementation of uart_driver.h
 * @author Ingmar Delsink
 */

/* INCLUDES */
/* Project and default includes */
#include "uart_driver.h"
#include <project.h>

void UART_Driver_Debug_Init(void)
{
    UART_DEBUG_Start();
}

void UART_Driver_Debug_DeInit(void)
{
    UART_DEBUG_Stop();
}

/* [] END OF FILE */
