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


int core0_main(void)
{
	disableInterrupts();
	get_clk();//��ȡʱ��Ƶ��  ��ر���

    //�û��ڴ˴����ø��ֳ�ʼ��������
	//ʹ��CCU6_0ģ���ͨ��0 ����һ�� 100ms�������ж�
	pit_interrupt_ms(CCU6_0, PIT_CH0, 100);


	//�жϺ�����isr.c�� ��������Ϊcc60_pit_ch0_isr
	//�ж���ص����ò�����isr_config.h��
	//�����ò����� CCU6_0_CH0_INT_SERVICE �� CCU6_0_CH0_ISR_PRIORITY
	//CCU6_0_CH0_INT_SERVICE �жϷ����ߣ���ʾ���ж���˭����0:CPU0 1:CPU1 3:DMA  ��������Ϊ����ֵ
	//CCU6_0_CH0_ISR_PRIORITY �ж����ȼ� ���ȼ���Χ1-255 Խ�����ȼ�Խ�� ��ƽʱʹ�õĵ�Ƭ����һ��

	//��Ҫ�ر�ע�����  �����������ȼ���ͬ���жϺ��� ÿ���жϵ����ȼ��������ǲ�һ����
    enableInterrupts();

    while (TRUE)
    {
		//��isr.c���жϺ�������������ĵڶ��������̶�Ϊ0���벻Ҫ���ģ���ʹ����CPU1�����ж�Ҳ��Ҫ���ģ���ҪCPU1�����ж�ֻ��Ҫ��isr_config.h���޸Ķ�Ӧ�ĺ궨�弴��
    	//��������֮�� PIT�ж�ÿִ��һ�ξͻ��ӡһ�ε�FSS����
    }
}

#pragma section all restore