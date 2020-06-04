
/*
realtek 8710cx
Note
    1, Supported GPIO pins, PA_0, PA_1, PA_2, PA_3, PA_4, PA_7, PA_8, PA_9, PA_10, PA_11, PA_12, PA_13, PA_14, PA_15, PA_16, PA_17, PA_18, PA_19, PA_20, and PA_23.
    2, Please off JTAG/SWD, when using PA_0, PA_1, PA_2, PA_3, and PA_4.
    3, Please off log UART, when using PA_15, and PA_16.
    4, PA_7, PA_8, PA_9, PA_10, PA_11 and PA_12 only available on RTL8720CF.

*/


#ifndef _YA_HAL_GPIO_H_
#define _YA_HAL_GPIO_H_


#define GPIO_NUM			2

#define YA_GPIO_PARA_INIT	 {{DRV_GPIO_0,DRV_GPIO_DIR_OUTPUT},\
							 {DRV_GPIO_1,DRV_GPIO_DIR_OUTPUT}}

typedef enum
{
	LED1 = 0,
	SWITCH1,
}YA_GPIO_NAME;

#define LED1_ON			0
#define LED1_OFF		1

#define SWITCH1_ON		1
#define SWITCH1_OFF 	0


#if (GPIO_NUM > 0)

extern void ya_gpio_write(uint8_t index, int value);

extern int ya_gpio_read(uint8_t index);

extern void ya_gpio_init(void);

#endif

#endif

