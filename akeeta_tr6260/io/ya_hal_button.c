#include "ya_common.h"
#include "drv_gpio.h"
#include "ya_hal_button.h"

#define DEBUNCE_NUM   3

#if (BUTTON_NUM > 0)

typedef struct
{
	uint32_t pin_num;
	uint32_t pin_dir;
	int 			push_value;
	void (*ya_button_push_time_handler)(uint32_t button_push_ms);
}ya_button_para_t;

ya_button_para_t ya_button_para[BUTTON_NUM] = YA_BUTTON_PARA_INIT;

typedef struct
{
	uint8_t  cur_value;
	uint32_t trigger_num;
}ya_button_handle_para_t;


ya_button_handle_para_t ya_button_interupt_para[BUTTON_NUM] = {0};

//gpio_t ya_button[BUTTON_NUM];

void ya_set_button_callback(uint8_t index, ya_button_push_time_func ya_button_push_time_callback)
{

	if(BUTTON_NUM == 0 || index > BUTTON_NUM)
	{
		return;
	}

	ya_button_para[index].ya_button_push_time_handler = ya_button_push_time_callback;
	/**/
}

void ya_button_listen(void *arg)
{

	uint8_t index = 0;
	uint32_t pin_value;
	while(1)
	{
		for(index = 0; index < BUTTON_NUM; index++)
		{
			gpio_read(ya_button_para[index].pin_num,&pin_value);
			ya_button_interupt_para[index].cur_value = pin_value;
			if((ya_button_interupt_para[index].cur_value) != ya_button_para[index].push_value)
			{
				if(ya_button_interupt_para[index].trigger_num > DEBUNCE_NUM)
				{
					if(ya_button_para[index].ya_button_push_time_handler)
						ya_button_para[index].ya_button_push_time_handler(ya_button_interupt_para[index].trigger_num*10);
				}
				ya_button_interupt_para[index].trigger_num = 0;
			}
			else
				ya_button_interupt_para[index].trigger_num++;
				
		}
		ya_delay(10);
	}
	/**/
}


int ya_button_init(void)
{

	uint8_t index = 0;

	//sys_jtag_off();
	for(index = 0; index < BUTTON_NUM; index++)
	{
		// Initial Push Button pin
		gpio_set_dir(ya_button_para[index].pin_num,ya_button_para[index].pin_dir);
	}

	if(xTaskCreate(ya_button_listen, "ya_button_listen", (512), NULL, tskIDLE_PRIORITY + 1, NULL) != pdPASS)
		return -1;
	/*	*/

	return 0;
}

#endif



