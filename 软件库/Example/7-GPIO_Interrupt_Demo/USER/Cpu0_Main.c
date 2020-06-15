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

uint16 adc_result;

int core0_main(void)
{
	disableInterrupts();
	get_clk();//获取时钟频率  务必保留

    //用户在此处调用各种初始化函数等

	//特别注意通道2 与 通道3都被摄像头占用，由于中断共用的关系，因此通道6 与 通道7也不能使用
	//TC264的外部中断不像K60单片机那样所有IO都支持，TC264只有部分支持具体可以查看zf_eru.h中ERU_PIN_enum枚举定义

	eru_init(ERU_CH0_REQ0_P15_4, RISING);	//ERU通道0 使用P15_4引脚  上升沿中断
	eru_init(ERU_CH4_REQ13_P15_5, RISING);	//ERU通道4 使用P15_5引脚  上升沿中断
	//通道0与4共用中断，中断内通过标志位判断

	eru_init(ERU_CH1_REQ10_P14_3, RISING);	//ERU通道1 使用P14_3引脚  上升沿中断
	eru_init(ERU_CH5_REQ1_P15_8, RISING);	//ERU通道5 使用P15_8引脚  上升沿中断
	//通道1与5共用中断，中断内通过标志位判断


	//中断函数在isr.c中
	//函数名称分别为eru_ch0_ch4_isr 与 eru_ch1_ch5_isr

	//中断相关的配置参数在isr_config.h内
	//可配置参数有 ERU_CH0_CH4_INT_SERVICE 和 ERU_CH0_CH4_INT_PRIO
	//ERU_CH0_CH4_INT_SERVICE 中断服务者，表示改中断由谁处理，0:CPU0 1:CPU1 3:DMA  不可设置为其他值
	//ERU_CH0_CH4_INT_PRIO 	     中断优先级 优先级范围1-255 越大优先级越高 与平时使用的单片机不一样

	//ERU其他中断也是同理

	//需要特备注意的是  不可以有优先级相同的中断函数 每个中断的优先级都必须是不一样的

    enableInterrupts();

    while (TRUE)
    {
		//在isr.c的中断函数，函数定义的第二个参数固定为0，请不要更改，即使你用CPU1处理中断也不要更改，需要CPU1处理中断只需要在isr_config.h内修改对应的宏定义即可
    	//程序运行之后，使用杜邦线将P15_4、P15_5、P14_3、P15_8连接到GND，然后在断开，在连接如此往复
    	//在FSS窗口会看到对应的提示信息
    }
}


#pragma section all restore
