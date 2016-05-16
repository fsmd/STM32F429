/********************        (C) COPYRIGHT 2016        **************************
 * 文件名  ：main.c
 * 描述    ：STM32F429 USART3 测试    
 * 实验平台: STM32F429ZIT6
 * 库版本  ：V1.6.1
 * 编写日期：2016-05-10
 * 修改日期：
 * 作者    ：
**********************************************************************************/

#include "stm32f4xx.h"
#include "usart3.h"
#include "led.h"
#include "Tim2.h"
#include "chipid.h"

extern uint32_t ChipUniqueID[3];
/* 
 * 函数名：main
 * 描述  : "主机"的主函数
 * 输入  ：无
 * 输出  : 无
 */
int main(void)
{	 
	LED_GPIO_Config();
	TIM2_Config();
	USART3_Config(115200);
	LED1(OFF);
  LED2(OFF);
	Get_ChipID();
	printf("STM32F429 Discovery USART3 Test OK!!\r\n");
	printf("Chip ID is 0x%08X 0x%08X 0x%08X.\r\n",
	ChipUniqueID[0],ChipUniqueID[1],ChipUniqueID[2]);
	printf("Chip Size is %d KBytes.\r\n",(*(__IO uint32_t *)(0X1FFF7A22))&0xFFFF);
	while(1)
	{ 

	}	
}
/******************* (C) COPYRIGHT 2014 *****END OF FILE************/


