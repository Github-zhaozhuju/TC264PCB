/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ����Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
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
	get_clk();//��ȡʱ��Ƶ��  ��ر���

    //�û��ڴ˴����ø��ֳ�ʼ��������
	gtm_pwm_init(ATOM0_CH4_P02_4, 50,    0);//ATOM 0ģ���ͨ��4 ʹ��P02_4�������PWM  PWMƵ��50HZ  ռ�ձȰٷ�֮0/GTM_ATOM0_PWM_DUTY_MAX*100  GTM_ATOM0_PWM_DUTY_MAX�궨����zf_gtm_pwm.h
	gtm_pwm_init(ATOM0_CH5_P02_5, 1000,  0);
	gtm_pwm_init(ATOM0_CH6_P02_6, 10000, 0);
	gtm_pwm_init(ATOM0_CH7_P02_7, 30000, 0);

	gtm_pwm_init(ATOM1_CH7_P00_8, 30000, 5000);
	//ÿ��ͨ�������������ͬƵ�ʵ�PWM

	pwm_duty(ATOM0_CH4_P02_4, 5000);//����ռ�ձ�Ϊ�ٷ�֮5000/GTM_ATOM0_PWM_DUTY_MAX*100
	pwm_duty(ATOM0_CH5_P02_5, 5000);
	pwm_duty(ATOM0_CH6_P02_6, 5000);
	pwm_duty(ATOM0_CH7_P02_7, 5000);

    enableInterrupts();

    while (TRUE)
    {

    }
}

#pragma section all restore