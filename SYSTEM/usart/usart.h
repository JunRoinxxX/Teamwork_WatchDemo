#ifndef __USART_H
#define __USART_H
#include "main.h"
#include "stm32f4xx_conf.h"


#define USART_REC_LEN  			300  	//定义最大接收字节数 200
#define EN_USART1_RX 			1		//使能（1）/禁止（0）串口1接收

#define print_buffer for(int i=0;i<USART_REC_LEN;i++){printf("%d:  %d\r\n",i,USART_RX_BUF[i]);}


extern u8 USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符
extern u8 cmd_stor_buffer1[4];
extern u8 cmd_send_buffer1[4];
extern u8 flag_USART_Get;
//如果想串口中断接收，请不要注释以下宏定义
void uart_init(u32 bound);
void USART1_Tx_Puts(u8* cmd_buffer, u8 Area);








#endif

