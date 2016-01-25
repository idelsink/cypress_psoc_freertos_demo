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
 * @file t_blink_led_demo.c
 * @brief Implementation of t_blink_led_demo.h
 * @author Ingmar Delsink
 */

/*  INCLUDES  */
/* Project and default includes */
#include "t_blink_led_demo.h"
#include <project.h>
#include <stdio.h>
/* RTOS includes. */
#include <FreeRTOS.h>
#include <semphr.h>
#include "os_resource.h"
/* Drivers */
#include "gpio_driver.h"

/* Debug MACRO */
//#define T_BLINK_LED_DEMO_DEBUG
#ifdef T_BLINK_LED_DEMO_DEBUG
#define D(call) DEBUGPRINT(call)
#else
#define D(call)
#endif

/** @brief Hearth Beat LED */
void task_Blink_HeartBeat_Demo(void *arg)
{
    unsigned int onTime = 100;//ms
    unsigned int offTime = 80;//ms
    unsigned int period = 1000;//ms
    Pin_HeartBeat_LED_Write(PIN_LOW);
    while(1) {
        Pin_HeartBeat_LED_Write(PIN_HIGH);//on
        Pin_Blue_LED_Write(LED_DEV_KIT_ON);
        D(printf("Task HB | Blink\n"));
        osDelay(onTime);//wait
        Pin_HeartBeat_LED_Write(PIN_LOW);//off
        Pin_Blue_LED_Write(LED_DEV_KIT_OFF);
        osDelay(offTime);//wait
        Pin_HeartBeat_LED_Write(PIN_HIGH);//on
        Pin_Blue_LED_Write(LED_DEV_KIT_ON);
        osDelay(onTime);//wait
        Pin_HeartBeat_LED_Write(PIN_LOW);//off
        Pin_Blue_LED_Write(LED_DEV_KIT_OFF);
        osDelay(period-(2*onTime)-(1*offTime));
	}
}

/** @brief Red LED blink demo thread */
void task_Blink_Led_Red_Demo(void *arg)
{
    Pin_Red_LED_Write(LED_DEV_KIT_OFF);
	while(1) {
        Pin_Red_LED_Write(~Pin_Red_LED_Read());
        D(printf("Task BlinkRed | Blink\n"));
        osDelay(500);
	}
}

/** @brief Green LED blink demo thread */
void task_Blink_Led_Green_Demo(void *arg)
{
    Pin_Green_LED_Write(LED_DEV_KIT_OFF);
	while(1) {
		Pin_Green_LED_Write(~Pin_Green_LED_Read());
        D(printf("Task BlinkGreen | Blink\n"));
        osDelay(500);
	}
}

/** @brief Blue LED blink demo thread */
void task_Blink_Led_Blue_Demo(void *arg)
{
    Pin_Blue_LED_Write(LED_DEV_KIT_OFF);
    while(1) {
		Pin_Blue_LED_Write(~Pin_Blue_LED_Read());
        D(printf("Task BlinkBlue | Blink\n"));
        osDelay(500);
	}
}

/* [] END OF FILE */
