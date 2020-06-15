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
#include "SysSe/Math/Ifx_FftF32.h"
#pragma section all "cpu0_dsram"

#define SAMPLE_FREQUENCY	100		//定义采样频率
#define SIZE_N 				2000	//定义采集数量


cfloat32 fft_in[SIZE_N];
cfloat32 fft_out[SIZE_N];
uint32 	 use_time;


//本例程专门配套编写了matlab代码
//对函数y = 1024*(cos(3*pi*x))+512*(cos(7*pi*x)+pi/2)+2047做FFT运算
//然后绘制出幅频图像，可以在工程目录下找到FFT.m文件，使用matlab打开并运行可以看到绘制的幅频图像


int core0_main(void)
{
	int i;
	double x1, x2;

	get_clk();//获取时钟频率  务必保留

    //用户在此处调用各种初始化函数等
    enableInterrupts();

	for (i=0; i<SIZE_N; i++)  //生成输入信号
	{
		//函数为y = 1024*(cos(3*pi*x))+512*(cos(7*pi*x)+pi/2)+2047
		//计算x
		x1      = 3 * IFX_PI * (double)i / SAMPLE_FREQUENCY;
		x2      = (7 * IFX_PI * (double)i / SAMPLE_FREQUENCY) + (IFX_PI / 2);

		//代入x计算y
		fft_in[i].real =(float32)(1024 * cosf(x1) + 512 * cosf(x2) + 2047);
		fft_in[i].imag =0.0;
	}

    while (TRUE)
    {
    	systick_start(STM0);						//开始计时
    	Ifx_FftF32_radix2(fft_out, fft_in, SIZE_N);	//进行FFT运算
		//Ifx_FftF32_radix2I 为IFT（FFT逆变换）运算
		use_time = systick_getval_us(STM0);			//获取计时时间

		printf("use_time: %ldus\n", use_time);		//打印fft一次耗时多久
    }
}

#pragma section all restore

