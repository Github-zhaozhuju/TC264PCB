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
#pragma section all "cpu1_dsram"




void core1_main(void)
{
	disableInterrupts();
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());

    //�û��ڴ˴����ø��ֳ�ʼ��������
	//˫�˵�ʹ����ʵ�ܼ򵥣�����������main�б�д���õĳ��򼴿�
    //������ʹ�ú���0 ��˸P20_8��LED	����1��˸P20_9��LED
    gpio_init(P20_9, GPO, 0, PUSHPULL);
	
    enableInterrupts();
    while (TRUE)
    {
		//�û��ڴ˴���д�������
    	gpio_toggle(P20_9);
    	systick_delay_ms(STM1, 100);

    }
}





#pragma section all restore
