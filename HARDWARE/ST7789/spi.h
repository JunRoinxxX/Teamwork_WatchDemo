#ifndef __SPI_H
#define __SPI_H
#include "main.h"


#define LCD  0
#define ADS  1
#define W25Q 2






void SPI1_Init(void);			 //初始化SPI1口
void SPI1_SetSpeed(u8 SpeedSet); //设置SPI1速度
u8 SPI1_ReadWriteByte(u8 TxData);//SPI1总线读写一个字节
void SPI_ChangeConfig(uint8_t device);



#endif

