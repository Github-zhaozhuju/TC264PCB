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

#define EXAMPLE_EEPROM_SECTOR        (0)

uint8  write_data1;
uint16 write_data2;
uint32 write_data3;
float  write_data4;


uint8  read_data1;
uint16 read_data2;
uint32 read_data3;
float  read_data4;

uint32 write_buf;
int core0_main(void)
{
	disableInterrupts();
	get_clk();//获取时钟频率  务必保留

    //用户在此处调用各种初始化函数等
	write_data1 = 66;
	write_data2 = 6666;
	write_data3 = 666666;
	write_data4 = 6666.66;


	//检查当前页是否有数据，如果有数据则需要擦除整个扇区，
	if(flash_check(EXAMPLE_EEPROM_SECTOR, 0))	eeprom_erase_sector(EXAMPLE_EEPROM_SECTOR);
	if(flash_check(EXAMPLE_EEPROM_SECTOR, 1))	eeprom_erase_sector(EXAMPLE_EEPROM_SECTOR);
	if(flash_check(EXAMPLE_EEPROM_SECTOR, 2))	eeprom_erase_sector(EXAMPLE_EEPROM_SECTOR);
	if(flash_check(EXAMPLE_EEPROM_SECTOR, 3))	eeprom_erase_sector(EXAMPLE_EEPROM_SECTOR);

	//当写入的数据不是32位时，建议将数据放入uint32 类型的变量中，在将该变量作为参数传入到eeprom_page_program函数
	write_buf = write_data1;
	//将数据写入EXAMPLE_EEPROM_SECTOR扇区的第0页
	eeprom_page_program(EXAMPLE_EEPROM_SECTOR, 0, &write_buf);
	write_buf = write_data2;
	eeprom_page_program(EXAMPLE_EEPROM_SECTOR, 1, &write_buf);
	write_buf = write_data3;
	eeprom_page_program(EXAMPLE_EEPROM_SECTOR, 2, &write_buf);

	//保存浮点数的时候，使用float_conversion_uint32宏定义进行转换后在保存
	write_buf = float_conversion_uint32(write_data4);
	eeprom_page_program(EXAMPLE_EEPROM_SECTOR, 3, &write_buf);

	//读取eeprom中的数据
	read_data1 = flash_read(EXAMPLE_EEPROM_SECTOR, 0, uint8);
	read_data2 = flash_read(EXAMPLE_EEPROM_SECTOR, 1, uint16);
	read_data3 = flash_read(EXAMPLE_EEPROM_SECTOR, 2, uint32);
	read_data4 = flash_read(EXAMPLE_EEPROM_SECTOR, 3, float);

	printf("read_data1: %d\n",  read_data1);
	printf("read_data2: %d\n",  read_data2);
	printf("read_data3: %ld\n", read_data3);
	printf("read_data4: %f\n",  read_data4);

    enableInterrupts();

    while (TRUE)
    {

    }
}

#pragma section all restore

