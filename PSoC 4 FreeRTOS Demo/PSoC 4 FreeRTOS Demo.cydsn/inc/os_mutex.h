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
 * @file os_mutex.h
 * @brief All the mutexes of the OS
 * @author Ingmar Delsink
 * 
 */

#ifndef __OS_MUTEX_H
#define __OS_MUTEX_H

/*  INCLUDES  */
/* RTOS includes. */
#include <FreeRTOS.h>
#include <semphr.h>

/* Mutex/semaphore IDs*/
SemaphoreHandle_t mtx_SerialDebug;      /**< The serial debug Mutex */
    
#endif
    