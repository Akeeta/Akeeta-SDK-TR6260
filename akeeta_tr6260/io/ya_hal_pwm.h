
/*
*Note 8710cx
*   1, Supported PWM, PWM_0 to PWM_7.
*        PWM_0, PA_0, PA_11, PA_20
*        PWM_1, PA_1, PA_12
*        PWM_2, PA_2, PA_14
*        PWM_3, PA_3, PA_15
*        PWM_4, PA_4, PA_16
*        PWM_5, PA_17
*        PWM_6, PA_18
*        PWM_7, PA_13, PA_19, PA_23
*    2, Please off JTAG/SWD, when using PA_0, PA_1, PA_2, PA_3, and PA_4.
*    3, Please off log UART, when using PA_15, and PA_16.
*/

#ifndef _YA_HAL_PWM_H_
#define _YA_HAL_PWM_H_

#define PWM_NUM					5

/*
int32_t pwm_init(uint32_t channel);
int32_t pwm_deinit(uint32_t channel);
int32_t pwm_config(uint32_t channel, uint32_t freq, uint32_t duty_ratio);
int32_t pwm_start(uint32_t channel);
int32_t pwm_stop(uint32_t channel);
*/

#define YA_PWM_PARA_INIT	 {{PMW_CHANNEL_0, 0},\
							 {PMW_CHANNEL_1,0},\
							 {PMW_CHANNEL_2, 0},\
							 {PMW_CHANNEL_3, 0},\
							 {PMW_CHANNEL_4, 0}}

typedef enum
{
	PWM_R = 0,
	PWM_G,
	PWM_B,

	PWM_COOL,
	PWM_WARM,
}YA_PWM_NAME;


#if (PWM_NUM > 0)

extern void ya_hal_pwm_init(void);

extern void ya_hal_pwm_write(uint8_t index, float percent);

#endif

#endif

