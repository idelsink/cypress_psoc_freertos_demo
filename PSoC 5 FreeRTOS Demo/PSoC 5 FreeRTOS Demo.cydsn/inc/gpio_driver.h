/**
 * @file gpio_driver.h
 * @brief GPIO driver and all low level GPIO related definitions
 * @author Ingmar Delsink
 * 
 */

#ifndef __GPIO_DRIVER_H
#define __GPIO_DRIVER_H
  
/**
 * @name PIN_level_definition
 * @brief The definition for the PIN values
 */
/**@{*/
#define LED_DEV_KIT_ON  (0u)
#define LED_DEV_KIT_OFF (1u)

#define PIN_LOW     (0u)
#define PIN_HIGH    (1u)
/**@}*/

/** @brief Initialize for the GPIO and low level GPIO related tasks */
void GPIO_Driver_Init(void);

#endif
