#ifndef __RTC_H_
#define __RTC_H_
#include "main.h"



extern  RTC_TimeTypeDef RTC_TimeStructure;
extern  RTC_DateTypeDef RTC_DateStructure;

ErrorStatus RTC_Set_Time(uint8_t hour, uint8_t min, uint8_t sec, uint8_t ampm);
ErrorStatus RTC_Set_Date(uint8_t year, uint8_t month, uint8_t date, uint8_t week);
ErrorStatus My_RTC_Init(void);

void RTC_Set_AlarmA(u8 week,u8 hour,u8 min,u8 sec);		//设置闹钟时间(按星期闹铃,24小时制)
void RTC_Set_WakeUp(u32 wksel,u16 cnt);					//周期性唤醒定时器设置




#endif 

