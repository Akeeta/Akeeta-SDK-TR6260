#include "FreeRTOS.h"
#include "drv_gpio.h"
#include "ya_hal_gpio.h"


#if (GPIO_NUM > 0)
typedef struct
{
	uint32_t pin_num;
	uint32_t pin_dir;

}ya_gpio_para_t;
ya_gpio_para_t ya_gpio_para[GPIO_NUM] = YA_GPIO_PARA_INIT;

void ya_gpio_write(uint8_t index, int value)
{
	if(GPIO_NUM == 0 || index > GPIO_NUM)
	{
		return;
	}
	gpio_write(ya_gpio_para[index].pin_num, value);
}

int ya_gpio_read(uint8_t index)
{
	uint32_t value=-1;
	if(GPIO_NUM == 0 || index > GPIO_NUM)
	{
		return -1;
	}

	 gpio_read(ya_gpio_para[index].pin_num,&value);
	return value;
/*	*/
}

void ya_gpio_init(void)
{
	uint8_t index = 0;
	for(index = 0; index < GPIO_NUM; index++)
	{
		gpio_set_dir(ya_gpio_para[index].pin_num,ya_gpio_para[index].pin_dir);
	}
	/**/
}
#endif


