#include "FreeRTOS.h"
#include "drv_pwm.h"
#include "ya_hal_pwm.h"

#if (PWM_NUM > 0)


typedef struct{
	uint32_t channel;
	uint32_t duty_ratio;
}ya_pwm_para_t;

ya_pwm_para_t ya_pwm_para[PWM_NUM] = YA_PWM_PARA_INIT;
/**/

//pwmout_t ya_pwm_obj[PWM_NUM];
/*
int32_t pwm_init(uint32_t channel);
int32_t pwm_deinit(uint32_t channel);
int32_t pwm_config(uint32_t channel, uint32_t freq, uint32_t duty_ratio);
int32_t pwm_start(uint32_t channel);
int32_t pwm_stop(uint32_t channel);

*/
void ya_hal_pwm_init(void)
{

	uint16_t index = 0;
//	sys_jtag_off();

	for(index = 0; index < PWM_NUM; index++)
	{	
		pwm_init(ya_pwm_para[index].channel);
		pwm_config(ya_pwm_para[index].channel, 5000, ya_pwm_para[index].duty_ratio);
		pwm_start(ya_pwm_para[index].channel);
	}

}

void ya_hal_pwm_write(uint8_t index, float percent)
{
	if(index < PWM_NUM)
		pwm_config(ya_pwm_para[index].channel,5000, percent);
}

#endif


