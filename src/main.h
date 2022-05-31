#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f4xx_hal.h"


void Error_Handler(void);


#define TEST_LED_Pin GPIO_PIN_13
#define TEST_LED_GPIO_Port GPIOC
#define LED_R_Pin GPIO_PIN_3
#define LED_R_GPIO_Port GPIOA
#define LED_G_Pin GPIO_PIN_4
#define LED_G_GPIO_Port GPIOA
#define LED_B_Pin GPIO_PIN_5
#define LED_B_GPIO_Port GPIOA

#endif /* __MAIN_H */
