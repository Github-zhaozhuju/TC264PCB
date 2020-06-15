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

uint8 gpio_status;

int core0_main(void)
{
	disableInterrupts();
	get_clk();//��ȡʱ��Ƶ��  ��ر���

    //�û��ڴ˴����ø��ֳ�ʼ��������

	//��Ҫ�ر�ע��P20_2�ǲ�����������ģ�����ֻ������Ĺ���
	//��Ҫ�ر�ע��P20_2�ǲ�����������ģ�����ֻ������Ĺ���
	//��Ҫ�ر�ע��P20_2�ǲ�����������ģ�����ֻ������Ĺ���

	gpio_init(P20_8, GPO, 0, PUSHPULL);//����P20_8Ϊ��� Ĭ������͵�ƽ  PUSHPULL���������
	gpio_init(P20_9, GPO, 0, PUSHPULL);
	gpio_init(P21_4, GPO, 0, PUSHPULL);
	gpio_init(P21_5, GPO, 0, PUSHPULL);

	gpio_init(P21_2, GPI, 0, PULLUP);  //����P21_2Ϊ���� PULLUP����������

    enableInterrupts();

    while (TRUE)
    {
    	//��ȡgpio״̬
    	gpio_status = gpio_get(P21_2);
    	//��gpio״̬��ӡ��FSS����
    	printf("gpio_status: %d\n", gpio_status);

    	gpio_toggle(P20_8);//��תIO
    	gpio_toggle(P20_9);
    	gpio_toggle(P21_4);
    	gpio_toggle(P21_5);

    	systick_delay_ms(STM0, 100);
    }
}

#pragma section all restore

