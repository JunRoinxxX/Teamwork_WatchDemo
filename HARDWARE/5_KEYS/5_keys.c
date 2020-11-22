#include "5_keys.h"



extern u8 flag_BEEP;
extern uint16_t Menu_Pointer[7];
extern enum STATUS {
    MENU = 0,
    TIMERUN,
    TIME_SET,
    CLOCK_SET,
    IR_REMOTE,
    IR_CHANNEL_CHOOSE,
    MPU6050,
    AD_VAL,
}
STATE;


void five_keys_exti_config(void) {
    EXTI_InitTypeDef EXTI_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

    /*key_5_1*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Pin = K_5_1_GPIO_Pin;
    GPIO_InitStructure.GPIO_PuPd = KEY_Pud;
    GPIO_Init(K_5_1_GPIO_Port, &GPIO_InitStructure);

    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource15);

    EXTI_InitStructure.EXTI_Line = EXTI_Line15;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    /*key_5_2*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Pin = K_5_2_GPIO_Pin;
    GPIO_InitStructure.GPIO_PuPd = KEY_Pud;
    GPIO_Init(K_5_2_GPIO_Port, &GPIO_InitStructure);

    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource8);

    EXTI_InitStructure.EXTI_Line = EXTI_Line8;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    /*key_5_3*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Pin = K_5_3_GPIO_Pin;
    GPIO_InitStructure.GPIO_PuPd = KEY_Pud;
    GPIO_Init(K_5_3_GPIO_Port, &GPIO_InitStructure);

    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource11);

    EXTI_InitStructure.EXTI_Line = EXTI_Line11;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    /*key_5_4*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Pin = K_5_4_GPIO_Pin;
    GPIO_InitStructure.GPIO_PuPd = KEY_Pud;
    GPIO_Init(K_5_4_GPIO_Port, &GPIO_InitStructure);

    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource12);

    EXTI_InitStructure.EXTI_Line = EXTI_Line12;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    /*key_5_5*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Pin = K_5_5_GPIO_Pin;
    GPIO_InitStructure.GPIO_PuPd = KEY_Pud;
    GPIO_Init(K_5_5_GPIO_Port, &GPIO_InitStructure);

    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource15);

    EXTI_InitStructure.EXTI_Line = EXTI_Line15;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static void k_5_1_do_something(void) {
    if(STATE == MENU && flag_of_STATE != 6 && LCD_Already_Updated) {
        ST7789_DrawFilledTriangle(Menu_Pointer[flag_of_STATE] + 3, 25, Menu_Pointer[flag_of_STATE] + 16, 50, Menu_Pointer[flag_of_STATE] + 29, 25, WHITE);
        flag_of_STATE--;
        LCD_Already_Updated = false;
    } else flag_BEEP = 1;
}

static void k_5_3_do_something(void) {
    if(STATE == MENU && flag_of_STATE != 6 && LCD_Already_Updated) {
        ST7789_DrawFilledTriangle(Menu_Pointer[flag_of_STATE] + 3, 25, Menu_Pointer[flag_of_STATE] + 16, 50, Menu_Pointer[flag_of_STATE] + 29, 25, WHITE);
        flag_of_STATE++;
        LCD_Already_Updated = false;
    } else flag_BEEP = 1;
}

static void k_5_4_do_something(void) {
    if(STATE == MENU && flag_of_STATE != 0 && LCD_Already_Updated) {
        ST7789_DrawFilledTriangle(Menu_Pointer[flag_of_STATE] + 3, 25, Menu_Pointer[flag_of_STATE] + 16, 50, Menu_Pointer[flag_of_STATE] + 29, 25, WHITE);
        flag_of_STATE--;
        LCD_Already_Updated = false;
    } else flag_BEEP = 1;
}

static void k_5_5_do_something(void) {
    if(STATE == MENU && flag_of_STATE != 6 && LCD_Already_Updated) {
        ST7789_DrawFilledTriangle(Menu_Pointer[flag_of_STATE] + 3, 25, Menu_Pointer[flag_of_STATE] + 16, 50, Menu_Pointer[flag_of_STATE] + 29, 25, WHITE);
        flag_of_STATE++;
        LCD_Already_Updated = false;
    } else flag_BEEP = 1;
}

static void k_5_2_do_something(void) {
    if(STATE == MENU) {
        STATE += (flag_of_STATE + 1);
        LCD_Already_Updated = false;
        ST7789_Fill_Color(WHITE);
    } else if(STATE == TIMERUN) {
        STATE = MENU;
        LCD_Already_Updated = false;
        ST7789_Fill_Color(WHITE);
    } else if(STATE == TIME_SET) {
        STATE = MENU;
        LCD_Already_Updated = false;
        RTC_WakeUpCmd(ENABLE);
        RTC_Set_Time(RTC_hour, RTC_minute, RTC_second, RTC_H12_AM);
        ST7789_Fill_Color(WHITE);
    } else if(STATE == CLOCK_SET) {
        STATE = MENU;
        LCD_Already_Updated = false;
        RTC_Set_AlarmA(1, RTC_hour, RTC_minute, 0);
        RTC_Set_AlarmA(2, RTC_hour, RTC_minute, 0);
        RTC_Set_AlarmA(3, RTC_hour, RTC_minute, 0);
        RTC_Set_AlarmA(4, RTC_hour, RTC_minute, 0);
        RTC_Set_AlarmA(5, RTC_hour, RTC_minute, 0);
        RTC_Set_AlarmA(6, RTC_hour, RTC_minute, 0);
        RTC_Set_AlarmA(7, RTC_hour, RTC_minute, 0);
        RTC_WakeUpCmd(ENABLE);
        ST7789_Fill_Color(WHITE);
    } else if(STATE == IR_REMOTE) {
        STATE = MENU;
        LCD_Already_Updated = false;
        ST7789_Fill_Color(WHITE);
    } else if(STATE == IR_CHANNEL_CHOOSE) {
        STATE = MENU;
        LCD_Already_Updated = false;
        ST7789_Fill_Color(WHITE);
    } else if(STATE == MPU6050) {
        STATE = MENU;
        LCD_Already_Updated = false;
        ST7789_Fill_Color(WHITE);
    } else if(STATE == AD_VAL) {
        STATE = MENU;
        LCD_Already_Updated = false;
        SPI_ChangeConfig(LCD);
        ST7789_Fill_Color(WHITE);
    } else flag_BEEP = 1;
}



//k_5_1  k_5_3 k_5_4 k_5_5
void EXTI15_10_IRQHandler(void) {
    if(EXTI_GetITStatus(K_5_1_EXTI_Line) != RESET && !GPIO_ReadInputDataBit(K_5_1_GPIO_Port, K_5_1_GPIO_Pin)) {
        k_5_1_do_something();
        EXTI_ClearITPendingBit(K_5_1_EXTI_Line);
    } else if(EXTI_GetITStatus(K_5_3_EXTI_Line) != RESET) {
        k_5_3_do_something();
        EXTI_ClearITPendingBit(K_5_3_EXTI_Line);
    } else if(EXTI_GetITStatus(K_5_4_EXTI_Line) != RESET) {
        k_5_4_do_something();
        EXTI_ClearITPendingBit(K_5_4_EXTI_Line);
    } else if(EXTI_GetITStatus(K_5_5_EXTI_Line) != RESET) {
        k_5_5_do_something();
        EXTI_ClearITPendingBit(K_5_5_EXTI_Line);
    }
}

//k_5_2
void EXTI9_5_IRQHandler(void) {
    if(EXTI_GetITStatus(K_5_2_EXTI_Line) != RESET) {
        k_5_2_do_something();
        EXTI_ClearITPendingBit(K_5_2_EXTI_Line);
    }
}








