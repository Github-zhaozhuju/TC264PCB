/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		tasking v6.3r1
 * @Target core		TC264D
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-3-23
 ********************************************************************************************************************/


#include "headfile.h"
#pragma section all "cpu0_dsram"

uint16 adc_result;

int core0_main(void)
{
	disableInterrupts();
	get_clk();//获取时钟频率  务必保留

    //用户在此处调用各种初始化函数等
	gtm_pwm_init(ATOM0_CH4_P02_4, 50,    0);//ATOM 0模块的通道4 使用P02_4引脚输出PWM  PWM频率50HZ  占空比百分之0/GTM_ATOM0_PWM_DUTY_MAX*100  GTM_ATOM0_PWM_DUTY_MAX宏定义在zf_gtm_pwm.h
	gtm_pwm_init(ATOM0_CH5_P02_5, 1000,  0);
	gtm_pwm_init(ATOM0_CH6_P02_6, 10000, 0);
	gtm_pwm_init(ATOM0_CH7_P02_7, 30000, 0);

	gtm_pwm_init(ATOM1_CH7_P00_8, 30000, 5000);
	//每个通道都可以输出不同频率的PWM

	pwm_duty(ATOM0_CH4_P02_4, 5000);//设置占空比为百分之5000/GTM_ATOM0_PWM_DUTY_MAX*100
	pwm_duty(ATOM0_CH5_P02_5, 5000);
	pwm_duty(ATOM0_CH6_P02_6, 5000);
	pwm_duty(ATOM0_CH7_P02_7, 5000);

    enableInterrupts();

    while (TRUE)
    {

    }
}

#pragma section all restore