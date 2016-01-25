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
 * @file retarget.c
 * @brief Re-implementation of low-level stdio functions
 * @author Cypress
 * @author Ingmar Delsink
 */

#include "retarget.h"

#ifndef __RETARGET__C
#define __RETARGET__C

#if (CY_PSOC3)
    /* For Keil compiler revise putchar() function with communication
    component which has to send data */
    char putchar( char c)
    {
        UART_DEBUG_PUT_CHAR(c);
        return c;
    }
#else
    #if defined(__ARMCC_VERSION)
        /* For MDK/RVDS compiler revise fputc function */
        struct __FILE {
            int handle;
        };
        enum {
            STDIN_HANDLE,
            STDOUT_HANDLE,
            STDERR_HANDLE
        };
        FILE __stdin = {STDIN_HANDLE};
        FILE __stdout = {STDOUT_HANDLE};
        FILE __stderr = {STDERR_HANDLE};
        int fputc(int ch, FILE *file) 
        {
            int ret = EOF;
            switch( file->handle ) {
            case STDOUT_HANDLE:
                UART_PutChar(ch);
                ret = ch;
                break;
            case STDERR_HANDLE:
                ret = ch;
                break;
            default:
                file = file;
                break;
            }
            return(ret);
        }
        #elif defined (__ICCARM__) /* IAR */
        /* For IAR compiler revise __write() function for printf functionality */
        size_t __write(int handle, const unsigned char * buffer, size_t size)
        {
            size_t nChars = 0;
            for (/* Empty */; size != 0; --size) {
                UART_DEBUG_PUT_CHAR(*buffer++);
                ++nChars;
            }
            return (nChars);
        }
    #else /* (__GNUC__) GCC */
        /* For GCC compiler revise _write() function */
        int _write(int file, char *ptr, int len)
        {
            int i;
            for (i = 0; i < len; i++) {
                UART_DEBUG_PUT_CHAR(*ptr++);
            }
            return(len);
        }
    #endif /* (__ARMCC_VERSION) */
#endif /* CY_PSOC3 */
/* Add an explicit reference to the floating point printf library to allow
the usage of floating point conversion specifier */
#if defined (__GNUC__)
    asm (".global _printf_float");
#endif

#endif