#include "GPIO.h"


void GPIO_ALLInit(void) {
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB, ENABLE);

    //������ GPIOA1��ʼ������
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//����
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    //RGBLED GPIOB12 13 14��ʼ������
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;// | GPIO_Pin_13 | GPIO_Pin_14;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    //KEY GPIOB4 5 8 9��ʼ������
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_8 | GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
    GPIO_Init(GPIOB, &GPIO_InitStructure);


    GPIO_ResetBits(GPIOA, GPIO_Pin_1);									//��������Ӧ��������
    //LED1 = 0;				  	//�ȵ�����
    LED2 = 1;				  	//�ȵ�����
    //LED3 = 0;				  	//�ȵ�����
}



void BEEP(void) {
	int i;
    for(i=0; i < 200; i++) {
        BEEP_PIN = !BEEP_PIN;
        delay_ms(2);
    }
}

u8 KEY_Scan(u8 mode) {
    static u8 key_up = 1; 		//�������ɿ���־
    if(mode)key_up = 1; 		//֧������
    if(key_up && (KEY1 == 0 || KEY2 == 0 || KEY3 == 0 || KEY4 == 0)) {
        delay_ms(10);			//ȥ����
        key_up = 0;
        if(KEY1 == 0)return 1;
        else if(KEY2 == 0)return 2;
        else if(KEY3 == 0)return 3;
        else if(KEY4 == 0)return 4;
    } else if(KEY1 == 1 && KEY2 == 1 && KEY3 == 1 && KEY4 == 1)key_up = 1;
    return 0;					// �ް�������
}





