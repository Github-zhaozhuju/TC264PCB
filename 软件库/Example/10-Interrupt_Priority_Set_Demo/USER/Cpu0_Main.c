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

    //������û�д���

	//�ж����ȼ�����isr_config.h�� ��������

	//�Լ��жϵķ�����Ҳ��isr_config.h�� ��������

	//���е��ж�  ���ȼ���ر�֤��һ�����������ظ������ȼ�

	//��uart��pit��GPIO�ж������еı�ע�����ᵽ


    enableInterrupts();

    while (TRUE)
    {
		//��isr.c���жϺ�������������ĵڶ��������̶�Ϊ0���벻Ҫ���ģ���ʹ����CPU1�����ж�Ҳ��Ҫ���ģ���ҪCPU1�����ж�ֻ��Ҫ��isr_config.h���޸Ķ�Ӧ�ĺ궨�弴��
    }
}


#pragma section all restore
