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

//如果是新手可以先不学习本例程，本例程主要针对单片机基础较好的同学，想自己优化RAM分配提高性能的同学参考学习
//学习的时候请从上往下认真阅读。



//在TC264中的两个核心，实际上他们的流水线数量是不一样的，CPU0是一级流水线，CPU1是三级流水线，因此CPU1更适合做运算，速度会比CPU0快一些。


//TC264D单片机有如下几个RAM可供用户使用
//CPU0 psram 程序RAM 大小为16KB
//CPU0 dsram 数据RAM 大小为72KB

//CPU1 psram 程序RAM 大小为32KB
//CPU1 dsram 数据RAM 大小为120KB

//TC264D中两个核心都有自己的程序缓存
//CPU0 Cache大小为8KB
//CPU1 Cache大小为16KB

//程序RAM用来放代码，将代码放在RAM中，可以提高执行速度，特别是当周期运行的代码大小超过了cache之后效果比较显著。
//数据RAM用来放变量，任意CPU都可以访问dsram0和dsram1，也就是说CPU0可以访问dsram1，这种行为叫做跨核访问，带来的问题就是访问延迟有所增大
//最好的是CPU0访问dsram0，CPU1访问dsram1，这样速度最快。
//默认情况下定义的全局变量都是保存在dsram1中的，这就会导致在CPU0中跑的代码对RAM读取会有一定的延迟


//那么接下来我们就要学习如何指定变量存放位置




//使用#pragma section all "cpu0_dsram" 和 #pragma section all restore可以将变量放在cpu0_dsram
//我们只需要将变量定义放在上面两句话中间即可，使用示例如下
#pragma section all "cpu0_dsram"
uint8 test_arry[5];	//将变量放在cpu0_dsram区域内
//如果将cpu0_dsram改为cpu1_dsram  则变量放在cpu1_dsram区域内
//我们建议程序由哪个CPU执行，则将所使用的变量放置在哪个区域内，默认不指定的情况下变量被放置在cpu1_dsram区域
#pragma section all restore



//使用#pragma section all "cpu0_psram" 和 #pragma section all restore可以将函数加载到cpu0_psram
//我们只需要将函数定义放在上面两句话中间即可，使用示例如下
#pragma section all "cpu0_psram"
void delay_tset(void)	//将函数加载到cpu0_psram区域内执行
{
	int i;
	i = 999;
	while(i--);
}
//如果将cpu0_psram改为cpu1_psram  则函数加载到cpu1_psram区域内
//我们建议程序由哪个CPU执行，则将函数加载到在哪个区域内，默认不指定的情况下，程序都是从flash加载并执行
//通常我们都不需要将函数放在RAM运行，一般在周期执行的程序大小超过了cache后，会出现程序执行速度降低，这个时候我们就可以将部分代码放入RAM执行，可以提高运算速度
#pragma section all restore



//如果在写代码的时候忘记了上面的使用方式，可以从Libraries\Doc文件夹内找到version.txt，打开后可以看到上面的使用示例

int core0_main(void)
{
	get_clk();//获取时钟频率  务必保留

	test_arry[0] = 0;
	delay_tset();
    enableInterrupts();

    while (TRUE)
    {
    	//如果是新手可以先不学习本例程，本例程主要针对单片机基础较好的同学，想自己优化RAM分配提高性能的同学参考学习
    	//如果是移植代码请务必从最新版本的库，提取LSL文件替换到自己的工程
    	//学习的时候请从上往下认真阅读。
    }
}

#pragma section all restore
