#ifndef __SPI_H
#define __SPI_H
#include "main.h"


#define LCD  0
#define ADS  1
#define W25Q 2






void SPI1_Init(void);			 //��ʼ��SPI1��
void SPI1_SetSpeed(u8 SpeedSet); //����SPI1�ٶ�
u8 SPI1_ReadWriteByte(u8 TxData);//SPI1���߶�дһ���ֽ�
void SPI_ChangeConfig(uint8_t device);



#endif

