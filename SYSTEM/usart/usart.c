#include "usart.h"





//���ʹ��ucos,����������ͷ�ļ�����.
#if SYSTEM_SUPPORT_OS
#include "includes.h"					//ucos ʹ��	  
#endif

//�������´���,֧��printf����,������Ҫѡ��use MicroLIB
#if 1
#pragma import(__use_no_semihosting)
//��׼����Ҫ��֧�ֺ���
struct __FILE {
    int handle;
};

FILE __stdout;
//����_sys_exit()�Ա���ʹ�ð�����ģʽ
void _sys_exit(int x) {
    x = x;
}
//�ض���fputc����
int fputc(int ch, FILE *f) {
    while((USART1->SR & 0X40) == 0); //ѭ������,ֱ���������
    USART1->DR = (u8) ch;
    return ch;
}
#endif

#if EN_USART1_RX   //���ʹ���˽���
//����1�жϷ������
//ע��,��ȡUSARTx->SR�ܱ���Ī������Ĵ���
u8 flag_USART_Get = 1;
extern u8 IR_Channel;

u8 USART_RX_BUF[USART_REC_LEN];     //���ջ���,���USART_REC_LEN���ֽ�.
u8 cmd_stor_buffer1[4] = {0xFE, 0xAB, 0xCD, 0x88};		//����洢ָ��
u8 cmd_send_buffer1[4] = {0xFE, 0xDC, 0xBA, 0x66};		//���ⷢ��ָ��
extern u8 Fill_IR_Code[4];
//����״̬
//bit15��	������ɱ�־
//bit14��	���յ�0x0d
//bit13~0��	���յ�����Ч�ֽ���Ŀ
u16 USART_RX_STA = 0;     //����״̬���

//��ʼ��IO ����1
//bound:������
void uart_init(u32 bound) {
    //GPIO�˿�����
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    USART_ClockInitTypeDef USART_ClockInitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); //ʹ��GPIOAʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); //ʹ��USART1ʱ��

    //����1��Ӧ���Ÿ���ӳ��
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1); //GPIOA9����ΪUSART1
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1); //GPIOA10����ΪUSART1

    //USART1�˿�����
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;// | GPIO_Pin_10; //GPIOA9��GPIOA10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; //����
    GPIO_Init(GPIOA, &GPIO_InitStructure); //��ʼ��PA9��PA10

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //GPIOA9��GPIOA10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//���ù���
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; //����
    GPIO_Init(GPIOA, &GPIO_InitStructure); //��ʼ��PA9��PA10

    //USART1 ��ʼ������
    USART_InitStructure.USART_BaudRate = bound;//����������
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
    USART_InitStructure.USART_Mode = USART_Mode_Tx;	//�շ�ģʽ
    USART_Init(USART1, &USART_InitStructure); //��ʼ������1

    USART_ClockInitStructure.USART_Clock = USART_Clock_Disable;     					//ʱ�ӵ͵�ƽ�
    USART_ClockInitStructure.USART_CPOL = USART_CPOL_Low;         						//����SCLK������ʱ������ļ���Ϊ�͵�ƽ
    USART_ClockInitStructure.USART_CPHA = USART_CPHA_1Edge;   							//ʱ�ӵ�һ�����ؽ������ݲ���
    USART_ClockInitStructure.USART_LastBit = USART_LastBit_Disable;  					//���һλ���ݵ�ʱ�����岻��SCLK���
    USART_ClockInit(USART1, &USART_ClockInitStructure);

    USART_Cmd(USART1, ENABLE);  //ʹ�ܴ���1

    //USART_ClearFlag(USART1, USART_FLAG_TC);

#if 1//EN_USART1_RX
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//��������ж�

    //Usart1 NVIC ����
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;//����1�ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3; //��ռ���ȼ�3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//�����ȼ�3
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����

#endif

}


void USART1_IRQHandler(void) {              	//����1�жϷ������
    u8 Res;
#if SYSTEM_SUPPORT_OS 		//���SYSTEM_SUPPORT_OSΪ�棬����Ҫ֧��OS.
    OSIntEnter();
#endif
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) { //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
        Res = USART_ReceiveData(USART1); //(USART1->DR);	//��ȡ���յ�������

        if((USART_RX_STA & 0x8000) == 0) { //����δ���
            if(USART_RX_STA & 0x4000) { //���յ���0x0d
                if(Res != 0x0a)USART_RX_STA = 0; //���մ���,���¿�ʼ
                else {
                    USART_RX_STA |= 0x8000;	//���������
					flag_USART_Get = 1;
                }
            } else { //��û�յ�0X0D
                if(Res == 0x0d)USART_RX_STA |= 0x4000;
                else {
                    USART_RX_BUF[USART_RX_STA & 0X3FFF] = Res;
                    USART_RX_STA++;
                    if(USART_RX_STA > (USART_REC_LEN - 1))USART_RX_STA = 0; //�������ݴ���,���¿�ʼ����
                }
            }
        }
    }
#if SYSTEM_SUPPORT_OS 	//���SYSTEM_SUPPORT_OSΪ�棬����Ҫ֧��OS.
    OSIntExit();
#endif
}
#endif





/**********************************************************************************************************
* ��  �� : USART1���ͺ���
* ��  �� : �����ַ�
* ����ֵ : ��
**********************************************************************************************************/
void USART1_SendByte(u8 byte) {
    while(USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);
    USART_SendData(USART1, byte);
}
/**********************************************************************************************************
* ��  �� : USART1���յ����ݺ󴮿ڷ��ͳ�ȥ
* ��  �� : ��
* ����ֵ : ��
**********************************************************************************************************/
void USART1_Tx_Puts(u8* cmd_buffer, u8 Area) {
    u16 i;

    for(i = 0; i < 4; i++) {			//����
        USART1_SendByte(cmd_buffer[i]);
    }
    USART1_SendByte(Area);
}
/**********************************************************************************************************/









