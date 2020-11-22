#include "GPIO.h"


void GPIO_ALLInit(void) {
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB, ENABLE);

    //蜂鸣器 GPIOA1初始化设置
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//下拉
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    //RGBLED GPIOB12 13 14初始化设置
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;// | GPIO_Pin_13 | GPIO_Pin_14;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    //KEY GPIOB4 5 8 9初始化设置
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_8 | GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
    GPIO_Init(GPIOB, &GPIO_InitStructure);


    GPIO_ResetBits(GPIOA, GPIO_Pin_1);									//蜂鸣器对应引脚拉低
    //LED1 = 0;				  	//先点亮灯
    LED2 = 1;				  	//先点亮灯
    //LED3 = 0;				  	//先点亮灯
}



void BEEP(void) {
	int i;
    for(i=0; i < 200; i++) {
        BEEP_PIN = !BEEP_PIN;
        delay_ms(2);
    }
}

u8 KEY_Scan(u8 mode) {
    static u8 key_up = 1; 		//按键按松开标志
    if(mode)key_up = 1; 		//支持连按
    if(key_up && (KEY1 == 0 || KEY2 == 0 || KEY3 == 0 || KEY4 == 0)) {
        delay_ms(10);			//去抖动
        key_up = 0;
        if(KEY1 == 0)return 1;
        else if(KEY2 == 0)return 2;
        else if(KEY3 == 0)return 3;
        else if(KEY4 == 0)return 4;
    } else if(KEY1 == 1 && KEY2 == 1 && KEY3 == 1 && KEY4 == 1)key_up = 1;
    return 0;					// 无按键按下
}





