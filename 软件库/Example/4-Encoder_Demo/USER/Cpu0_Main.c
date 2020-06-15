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

int16 speed;

int core0_main(void)
{
	disableInterrupts();
	get_clk();//获取时钟频率  务必保留

    //用户在此处调用各种初始化函数等
	//第一个参数 表示选择使用的定时器
	//第二个参数 表示选择的计数引脚    计数引脚与方向引脚不可交换
	//第三个参数 表示选择的方向引脚
	gpt12_init(GPT12_T2, GPT12_T2INB_P33_7, GPT12_T2EUDB_P33_6);
    enableInterrupts();

    while (TRUE)
    {
    	speed = gpt12_get(GPT12_T2);
    	gpt12_clear(GPT12_T2);
    	//打印采集到的编码器数据 到FSS窗口
    	printf("speed: %d\n", speed);
    	systick_delay_ms(STM0, 100);

    	//旋转编码器越快 FSS窗口显示的数据越大，正转数值为正，反正数值为负
    }
}

#pragma section all restore