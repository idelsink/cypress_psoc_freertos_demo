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
 * @file main.c
 * @brief Entry point and RTOS resources
 * @author Ingmar Delsink
 */

/*  INCLUDES  */
/* Project and default includes */
#include <project.h>
/* RTOS includes. */
#include <FreeRTOS.h>
#include "os_mutex.h"
#include "os_resource.h"
/* Project */
/* Drivers */
#include "gpio_driver.h"
#include "uart_driver.h"
/* Interfaces */
/* Data */
/* Task includes */
#include "t_blink_led_demo.h"

/* Debug MACRO */
#define MAIN_DEBUG
#ifdef MAIN_DEBUG
#define D(call) DEBUGPRINT(call)
#else
#define D(call)
#endif

/*----------------------------------------------------------------------------
   Main: Initialize and start Kernel
*---------------------------------------------------------------------------*/
int main()
{	
    mtx_SerialDebug     = xSemaphoreCreateMutex();  /* Initialize the Debug Mutex           */

    /* Drivers                              */
    UART_Driver_Debug_Init();               /* Initialize serial debug                  */
    GPIO_Driver_Init();                     /* Initialize GPIO                          */
    CySysTickStart();
    /* ISR                                  */
    CyGlobalIntEnable;                      /* Init the interrupts                      */
    
    /* Operating System                     */
    osInit();                               /* Initialize all thread related tasks      */
    prvHardwareSetup();                     /* FreeRTOS setup                           */
	vTaskStartScheduler();                  /* Start the scheduler                      */
    
	return 1;
}

int osInit(void)
{
    /* Demo tasks                   */
    xTaskCreate(task_Blink_HeartBeat_Demo, "BlinkHB", (configMINIMAL_STACK_SIZE), NULL, tskIDLE_PRIORITY + 0, NULL);    /* HB LED Demo              */
    xTaskCreate(task_Blink_Led_Red_Demo, "BlinkR", (configMINIMAL_STACK_SIZE), NULL, tskIDLE_PRIORITY + 0, NULL);       /* LED Demo                 */
    xTaskCreate(task_Blink_Led_Green_Demo, "BlinkG", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 0, NULL);       /* LED Demo                 */
	xTaskCreate(task_Blink_Led_Blue_Demo, "BlinkB", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 0, NULL);        /* LED Demo                 */
    
    D(printf("\nOS Initialized\n"));
    D(printf("%d words left (%d bytes)\n", xPortGetFreeHeapSize(), xPortGetFreeHeapSize()*4));
    return 1;// All went well
}

int osDeInit(void)
{
    return 1;
}

/* [] END OF FILE */
