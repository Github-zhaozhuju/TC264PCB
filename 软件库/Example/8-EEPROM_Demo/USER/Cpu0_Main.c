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
	get_clk();//��ȡʱ��Ƶ��  ��ر���

    //�û��ڴ˴����ø��ֳ�ʼ��������
	write_data1 = 66;
	write_data2 = 6666;
	write_data3 = 666666;
	write_data4 = 6666.66;


	//��鵱ǰҳ�Ƿ������ݣ��������������Ҫ��������������
	if(flash_check(EXAMPLE_EEPROM_SECTOR, 0))	eeprom_erase_sector(EXAMPLE_EEPROM_SECTOR);
	if(flash_check(EXAMPLE_EEPROM_SECTOR, 1))	eeprom_erase_sector(EXAMPLE_EEPROM_SECTOR);
	if(flash_check(EXAMPLE_EEPROM_SECTOR, 2))	eeprom_erase_sector(EXAMPLE_EEPROM_SECTOR);
	if(flash_check(EXAMPLE_EEPROM_SECTOR, 3))	eeprom_erase_sector(EXAMPLE_EEPROM_SECTOR);

	//��д������ݲ���32λʱ�����齫���ݷ���uint32 ���͵ı����У��ڽ��ñ�����Ϊ�������뵽eeprom_page_program����
	write_buf = write_data1;
	//������д��EXAMPLE_EEPROM_SECTOR�����ĵ�0ҳ
	eeprom_page_program(EXAMPLE_EEPROM_SECTOR, 0, &write_buf);
	write_buf = write_data2;
	eeprom_page_program(EXAMPLE_EEPROM_SECTOR, 1, &write_buf);
	write_buf = write_data3;
	eeprom_page_program(EXAMPLE_EEPROM_SECTOR, 2, &write_buf);

	//���渡������ʱ��ʹ��float_conversion_uint32�궨�����ת�����ڱ���
	write_buf = float_conversion_uint32(write_data4);
	eeprom_page_program(EXAMPLE_EEPROM_SECTOR, 3, &write_buf);

	//��ȡeeprom�е�����
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

