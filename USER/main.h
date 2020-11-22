#ifndef __MAIN_H
#define __MAIN_H
#include "stm32f4xx.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdint.h"
#include "stddef.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "timer.h"
#include "GPIO.h"
#include "spi.h"
#include "st7789.h"
#include "myiic.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "ads1118.h"
#include "rtc.h"
#include "5_keys.h"



/********************GPIO_Pre_Define********************/
// 蜂鸣器控制IO
#define BEEP_PIN 	PAout(1)

//LED端口定义
#define LED1 		PBout(12)
#define LED2 		PBout(13)
#define LED3 		PBout(14)

/*下面的方式是通过直接操作库函数方式读取IO*/
//#define KEY1 		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)
//#define KEY2 		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)
//#define KEY3 		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)
//#define KEY4 		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)

/*下面方式是通过位带操作方式读取IO*/
#define KEY1 		PBin(8)
#define KEY2 		PBin(5)
#define KEY3 		PBin(4)
#define KEY4 		PBin(9)


#define KEY1_PRES	1
#define KEY2_PRES	2
#define KEY3_PRES 	3
#define KEY4_PRES   4



/********************ST7789_Pre_Define********************/
/* Define the pins tp connect */
#define ST7789_RST_PORT 	GPIOA
#define ST7789_RST_PIN 		GPIO_Pin_4
#define ST7789_DC_PORT 		GPIOA
#define ST7789_DC_PIN 		GPIO_Pin_3
#define ST7789_CS_PORT 		GPIOA
#define ST7789_CS_PIN 		GPIO_Pin_2


#define TRUE          1
#define FALSE         0
#define NULL          0



extern u8 flag_Power_On;
extern uint8_t RTC_hour, RTC_minute, RTC_second;
extern bool LCD_Already_Updated;
extern u8 flag_of_STATE;






#endif

