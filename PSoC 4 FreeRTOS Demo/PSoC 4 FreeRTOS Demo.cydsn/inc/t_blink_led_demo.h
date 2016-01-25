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
 * @file t_Blink_Led_Demo.h
 * @brief LED Demo task
 * @author Ingmar Delsink
 * 
 */

#ifndef __T_BLINK_LED_DEMO_H
#define __T_BLINK_LED_DEMO_H

/*  INCLUDES  */
/* Project and default includes */
#include <project.h>
#include <stdio.h>
/* RTOS includes. */
#include <FreeRTOS.h>
#include <semphr.h>
#include "os_resource.h"
/* Drivers */
#include "gpio_driver.h"

/** @brief Red LED blink demo thread */
void task_Blink_Led_Red_Demo(void *arg);

/** @brief Green LED blink demo thread */
void task_Blink_Led_Green_Demo(void *arg);

/** @brief Blue LED blink demo thread */
void task_Blink_Led_Blue_Demo(void *arg);

/** @brief Hearth Beat LED */
void task_Blink_HeartBeat_Demo(void *arg);
#endif

/* [] END OF FILE */
