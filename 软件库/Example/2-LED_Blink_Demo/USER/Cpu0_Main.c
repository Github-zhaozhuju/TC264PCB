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

uint8 gpio_status;

int core0_main(void)
{
	disableInterrupts();
	get_clk();//获取时钟频率  务必保留

    //用户在此处调用各种初始化函数等

	//需要特别注意P20_2是不能用于输出的，仅仅只有输入的功能
	//需要特别注意P20_2是不能用于输出的，仅仅只有输入的功能
	//需要特别注意P20_2是不能用于输出的，仅仅只有输入的功能

	gpio_init(P20_8, GPO, 0, PUSHPULL);//设置P20_8为输出 默认输出低电平  PUSHPULL：推挽输出
	gpio_init(P20_9, GPO, 0, PUSHPULL);
	gpio_init(P21_4, GPO, 0, PUSHPULL);
	gpio_init(P21_5, GPO, 0, PUSHPULL);

	gpio_init(P21_2, GPI, 0, PULLUP);  //设置P21_2为输入 PULLUP：上拉输入

    enableInterrupts();

    while (TRUE)
    {
    	//获取gpio状态
    	gpio_status = gpio_get(P21_2);
    	//将gpio状态打印到FSS窗口
    	printf("gpio_status: %d\n", gpio_status);

    	gpio_toggle(P20_8);//翻转IO
    	gpio_toggle(P20_9);
    	gpio_toggle(P21_4);
    	gpio_toggle(P21_5);

    	systick_delay_ms(STM0, 100);
    }
}

#pragma section all restore

