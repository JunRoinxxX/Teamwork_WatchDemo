#ifndef __FONT_H
#define __FONT_H

#include "stdint.h"

typedef struct {
    const uint8_t width;
    uint8_t height;
    const uint16_t *data;
} FontDef;

//Font lib.
extern FontDef Font_7x10;
extern FontDef Font_11x18;
extern FontDef Font_16x26;

//16-bit(RGB565) Image lib.
/*******************************************
 *             CAUTION:
 *   If the MCU onchip flash cannot
 *  store such huge image data,please
 *           do not use it.
 * These pics are for test purpose only.
 *******************************************/

/* 128x128 pixel RGB565 image */
//extern const uint16_t saber[][128];

/* 240x240 pixel RGB565 image 
extern const uint16_t knky[][240];
extern const uint16_t tek[][240];
extern const uint16_t adi1[][240];
*/


extern const uint16_t REMOTE1[][40];
extern const uint16_t REMOTE2[][40];
extern const uint16_t IR_ChannelChoosing[][40];

extern const uint16_t img[];
extern const uint16_t imgtri[];

extern const uint16_t icon_TimeRunning[];
extern const uint16_t icon_Time_Set[];
extern const uint16_t icon_Clock_Set[];
extern const uint16_t icon_IR_Remote[];
extern const uint16_t icon_Channel_Choosing[];
extern const uint16_t icon_MPU6050[];
extern const uint16_t icon_AD_Val[];

extern const uint16_t icon_AD[];
extern const uint16_t icon_V[];
extern const uint16_t icon_C[];
extern const uint16_t icon_R[];



#endif

