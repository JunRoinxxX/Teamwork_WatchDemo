# Watch_DEMO

## 模式
主要分为 () 个模式;
由枚举类型决定状态：
```c
enum STATUS {
	MENU = 0,
	TIME_SET,
	CLOCK_SET，
	IR_REMOTE,
	IR_CHANNEL_CHOOSE,
	MPU6050,
	AD_VAL,
} STATE;
```
### MENU 菜单
平时的普通状态；唤醒时的状态，应该主要有时间霸屏，然后按键进入其他模式选择；
进入模式选择后可通过五向按键上下拨以进行上下翻页以及中间（ENTER）键确认；

### TIME_SET 时间设置
（字面意思

### CLOCK_SET 闹钟⏰设置
设置一个时间点，每天到点就会BEEP BEEP BEEP~

### IR_REMOTE 红外收发模式
进入模式后，预定通过两个小按键，按下KEY1后进行等待存储红外码，发送之后再按一次（或者按到其他键也）退出；按下KEY2后进行发射对应的红外码；

### IR_CHANNEL_CHOOSE 红外通道选择模式
进入模式后，直接按四个小按键来选择当前的通道，选择之后再进入红外收发模式进行收发都是基于当前选择的通道，只能通过进入这个模式来更改；

### MPU6050 陀螺仪
我也不知道这个模式有没有必要；

### AD_VAL
进行模拟量测试，将相应元器件插入后可测电阻电容电压；