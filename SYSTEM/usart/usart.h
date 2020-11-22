#ifndef __USART_H
#define __USART_H
#include "main.h"
#include "stm32f4xx_conf.h"


#define USART_REC_LEN  			300  	//�����������ֽ��� 200
#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����

#define print_buffer for(int i=0;i<USART_REC_LEN;i++){printf("%d:  %d\r\n",i,USART_RX_BUF[i]);}


extern u8 USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з�
extern u8 cmd_stor_buffer1[4];
extern u8 cmd_send_buffer1[4];
extern u8 flag_USART_Get;
//����봮���жϽ��գ��벻Ҫע�����º궨��
void uart_init(u32 bound);
void USART1_Tx_Puts(u8* cmd_buffer, u8 Area);








#endif

