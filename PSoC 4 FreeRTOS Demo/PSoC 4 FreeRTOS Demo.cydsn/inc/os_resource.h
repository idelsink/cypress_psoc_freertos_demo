/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
/**
 * @file os_resource.h
 * @brief Application-global definitions and global OS functions
 * @author Ingmar Delsink
 */

#ifndef __OS_RESOURCE_H
#define __OS_RESOURCE_H

/*  INCLUDES  */
/* Project and default includes */
#include <project.h>
#include <stdio.h>
/* RTOS includes. */
#include <FreeRTOS.h>
#include "os_mutex.h"
#include <task.h>
#include <semphr.h>
#include "retarget.h"

#define NO_FINGER 0xFFFFu

/**
 * @brief Make an IO call (i.e. printf) while keeping the
 *        serial debug mutex locked
 */
#define DEBUGPRINT(call)                                \
    do{                                                 \
        xSemaphoreTake(mtx_SerialDebug, portMAX_DELAY ); \
        call;                                           \
        xSemaphoreGive(mtx_SerialDebug);                \
    } while (0)

/* Signal defines */
/** @brief All threads receive this signal before sleep or exit.
           Receiver should (neatly) terminate itself. */
#define SIGNAL_GENERAL_KILL ((uint32_t)0x01)

/**
 * @brief a delay fuction for the OS
 */
void osDelay(double delay);

/**
 * @brief a function to convert a given time to cpu ticks
 * @return returns the number of ticks that would be passed in the given timeframe
 */
int osMsToTicks(double delayMs);

/**
 * @brief osInit initializes all threads.
 * @return 0 on failure, os not initialized, 1 on succes.
 */
int osInit(void);

/**
 * @brief osDeInit deinitializes all threads.
 * @return 0 on failure, os not initialized, 1 on succes.
 */
int osDeInit(void);

/* ---------------------------------------------------------------------------
 * FreeRTOS support and configuration functions
 * --------------------------------------------------------------------------- */

/**
 * @brief FreeRTOS Hardware setup
 */
void prvHardwareSetup();

/**
 * @brief Stack space watchdog
 */
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );

/**
 * @brief Heap space watchdog
 */
void vApplicationMallocFailedHook( void );


#endif

/* [] END OF FILE */
