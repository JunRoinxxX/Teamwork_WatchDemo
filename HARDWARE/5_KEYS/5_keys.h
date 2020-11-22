#ifndef __5_KEYS_H__
#define __5_KEYS_H__
#include  "main.h"



#define KEY_Pud GPIO_PuPd_UP

#define K_5_1_GPIO_Port GPIOB
#define K_5_1_GPIO_Pin 	GPIO_Pin_15
#define K_5_1_EXTI_Line EXTI_Line15

#define K_5_2_GPIO_Port GPIOA
#define K_5_2_GPIO_Pin 	GPIO_Pin_8
#define K_5_2_EXTI_Line EXTI_Line8

#define K_5_3_GPIO_Port GPIOA
#define K_5_3_GPIO_Pin 	GPIO_Pin_11
#define K_5_3_EXTI_Line EXTI_Line11

#define K_5_4_GPIO_Port GPIOA
#define K_5_4_GPIO_Pin 	GPIO_Pin_12
#define K_5_4_EXTI_Line EXTI_Line12

#define K_5_5_GPIO_Port GPIOA
#define K_5_5_GPIO_Pin 	GPIO_Pin_15
#define K_5_5_EXTI_Line EXTI_Line15





void five_keys_exti_config(void);







#endif

