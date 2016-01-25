/**
 * @file retarget.h
 * @brief Provides retargeting of low-level I/O libraries
 *        so that functions like `printf` can be used as a
 *        interface to the USART communication channel(s)
 * @author Ingmar Delsink
 *
 * Only `fputc` is meaningfully implemented. As a result,
 * higher level functions requiring only basic output
 * (e.g. `fprintf`) will work while input and advanced
 * I/O control like seeking and flushing will fail.
 *
 * Output is passed to usart_driver.h, where it
 * is buffered and shifted out efficiently.
 */

#ifndef __RETARGET__H
#define __RETARGET__H

#include <project.h>
#include "stdio.h"
    
#define UART_DEBUG_PUT_CHAR UART_DEBUG_PutChar

#endif
