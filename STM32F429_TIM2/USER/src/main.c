/********************        (C) COPYRIGHT 2016        **************************
 * 文件名  ：main.c
 * 描述    ：STM32F429 定时器控制 LED测试    
 * 实验平台: STM32F429ZIT6
 * 库版本  ：V1.6.1
 * 编写日期：2016-05-16
 * 修改日期：
 * 作者    ：
**********************************************************************************/

#include "stm32f4xx.h"
#include "led.h"
#include "Tim2.h"

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
	LED1(OFF);
  LED2(OFF);
	while(1)
	{ 
		/* Timer2 interrupt control! */
	}	
}
/******************* (C) COPYRIGHT 2016 *****END OF FILE************/


