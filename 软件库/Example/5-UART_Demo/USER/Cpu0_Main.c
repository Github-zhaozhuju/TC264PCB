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

uint8 uart_buff;

int core0_main(void)
{
	disableInterrupts();
	get_clk();//��ȡʱ��Ƶ��  ��ر���

    //�û��ڴ˴����ø��ֳ�ʼ��������
	uart_init(UART_0, 115200, UART0_TX_P14_0, UART0_RX_P14_1);
	uart_putstr(UART_0, "\n---uart test---\n");
    enableInterrupts();

	//�ڱ����У����ڴ��ڵĽ����뷢�Ͷ���ͨ���ж���ɵģ������Ҫ������ʹ�ô��ڹ�����ر�֤�ж��ǿ����ģ�Ҳ���ǵ�����enableInterrupts()
	//���ڵ��жϺ���ȫ������isr.c�С�
	
	//�����ж���ص����ò�������isr_config.h��
	//�����ò����� ERU_CH0_CH4_INT_SERVICE �� ERU_CH0_CH4_INT_PRIO
	//UART0_INT_SERVICE �жϷ����ߣ���ʾ���ж���˭����0:CPU0 1:CPU1 3:DMA  ��������Ϊ����ֵ
	//UART0_TX_INT_PRIO �����ж����ȼ� ���ȼ���Χ1-255 Խ�����ȼ�Խ�� ��ƽʱʹ�õĵ�Ƭ����һ��
	//UART0_RX_INT_PRIO	�����ж����ȼ�
	//UART0_ER_INT_PRIO �����ж����ȼ�
	
	//���������жϲ���ͬ��

	//��Ҫ�ر�ע�����  �����������ȼ���ͬ���жϺ��� ÿ���жϵ����ȼ��������ǲ�һ����
    while (TRUE)
    {
    	//��ѯ�Ƿ������ݣ�����������
    	if(uart_query(UART_0, &uart_buff))
    	{
    		//���յ������ݣ��ٷ���ȥ
    		uart_putchar(UART_0, uart_buff);
    	}

    	//ʹ��usbתttl���ӵ�Ƭ���Ĵ��ڣ��ڵ����ϴ򿪴������֣����ⷢ���ַ���
    	//��Ƭ���յ���᷵�ط��͵��ַ����������־ͻ���ʾ�ղŷ��͵Ķ���
    }
}

#pragma section all restore

