/********************       (C) COPYRIGHT 2016      **************************
 * 文件名  ：ChipID.c
 * 描述    ：获取CPU STM32 唯一 96bits ID       
 * 实验平台：STM32F429
 * 库版本  ：V1.6.1
 *
 * 编写日期：2016-05-10
 * 修改日期：
 * 作者    ：
****************************************************************************/
#include "chipid.h"

uint32_t ChipUniqueID[3];

/*
 * 函数名：Get_ChipID
 * 描述  ：获取芯片ID
 * 输入  ：无
 * 输出  ：无
 */
void Get_ChipID(void)
{
	ChipUniqueID[0] = *(__IO uint32_t *)(0X1FFF7A18); // 高4字节
	ChipUniqueID[1] = *(__IO uint32_t *)(0X1FFF7A14); // 中4字节
	ChipUniqueID[2] = *(__IO uint32_t *)(0X1FFF7A10); // 低4字节
}


/*******************    (C) COPYRIGHT 2016     *****END OF FILE************/
