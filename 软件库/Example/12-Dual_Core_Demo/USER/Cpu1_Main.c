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
#pragma section all "cpu1_dsram"




void core1_main(void)
{
	disableInterrupts();
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());

    //用户在此处调用各种初始化函数等
	//双核的使用其实很简单，就是在两个main中编写不用的程序即可
    //本例程使用核心0 闪烁P20_8的LED	核心1闪烁P20_9的LED
    gpio_init(P20_9, GPO, 0, PUSHPULL);
	
    enableInterrupts();
    while (TRUE)
    {
		//用户在此处编写任务代码
    	gpio_toggle(P20_9);
    	systick_delay_ms(STM1, 100);

    }
}





#pragma section all restore
