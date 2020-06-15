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
#include "SysSe/Math/Ifx_FftF32.h"
#pragma section all "cpu0_dsram"

#define SAMPLE_FREQUENCY	100		//�������Ƶ��
#define SIZE_N 				2000	//����ɼ�����


cfloat32 fft_in[SIZE_N];
cfloat32 fft_out[SIZE_N];
uint32 	 use_time;


//������ר�����ױ�д��matlab����
//�Ժ���y = 1024*(cos(3*pi*x))+512*(cos(7*pi*x)+pi/2)+2047��FFT����
//Ȼ����Ƴ���Ƶͼ�񣬿����ڹ���Ŀ¼���ҵ�FFT.m�ļ���ʹ��matlab�򿪲����п��Կ������Ƶķ�Ƶͼ��


int core0_main(void)
{
	int i;
	double x1, x2;

	get_clk();//��ȡʱ��Ƶ��  ��ر���

    //�û��ڴ˴����ø��ֳ�ʼ��������
    enableInterrupts();

	for (i=0; i<SIZE_N; i++)  //���������ź�
	{
		//����Ϊy = 1024*(cos(3*pi*x))+512*(cos(7*pi*x)+pi/2)+2047
		//����x
		x1      = 3 * IFX_PI * (double)i / SAMPLE_FREQUENCY;
		x2      = (7 * IFX_PI * (double)i / SAMPLE_FREQUENCY) + (IFX_PI / 2);

		//����x����y
		fft_in[i].real =(float32)(1024 * cosf(x1) + 512 * cosf(x2) + 2047);
		fft_in[i].imag =0.0;
	}

    while (TRUE)
    {
    	systick_start(STM0);						//��ʼ��ʱ
    	Ifx_FftF32_radix2(fft_out, fft_in, SIZE_N);	//����FFT����
		//Ifx_FftF32_radix2I ΪIFT��FFT��任������
		use_time = systick_getval_us(STM0);			//��ȡ��ʱʱ��

		printf("use_time: %ldus\n", use_time);		//��ӡfftһ�κ�ʱ���
    }
}

#pragma section all restore

