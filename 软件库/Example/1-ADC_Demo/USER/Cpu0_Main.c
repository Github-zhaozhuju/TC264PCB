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
	adc_init(ADC_0, ADC0_CH0_A0);//��ʼ��ADC0 ͨ��0 ʹ��A0����

    enableInterrupts();

    while (TRUE)
    {
    	//ͨ����A0���Žӵ�GND���ߺ��İ�VCC  �鿴FSS�����д�ӡ������ADC���
    	//A0�ӵ�GNDʱ ���Ӧ����0����
    	//A0�ӵ�VCCʱ ���Ӧ����4095����
    	//����ʱ �����������������û���κ����壬���Դ�Ҳ�Ҫ�����յ�ʱ��Ϊʲô�������ô���أ�
    	adc_result = adc_mean_filter(ADC_0, ADC0_CH0_A0, ADC_12BIT, 10);//�ɼ�10����ƽ��  �ֱ���12λ
    	printf("adc_result: %d\n", adc_result);
    	systick_delay_ms(STM0, 100);
    }
}

#pragma section all restore

