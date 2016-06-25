/********************       (C) COPYRIGHT 2014  ***************************
 * 文件名  ：led.c
 * 描述    ：led 应用函数库         
 * 实验平台：
 * 硬件连接：-----------------------
 *          |   PG13 - LED1(RUN)     |  
 *          |   PG14 - LED2(RUN)     |  
 *           ----------------------- 
 * 库版本  ：ST3.5.0
 * 编写日期：2016-05-16
 * 修改日期：
 * 作者    ：
****************************************************************************/
#include "led.h"

/*
 * 函数名：LED_GPIO_Config
 * 描述  ：配置LED用到的I/O口
 * 输入  ：无
 * 输出  ：无
 */
void LED_GPIO_Config(void)
{		
	/*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*开启 LED1 的GPIOx的外设时钟*/
	RCC_AHB1PeriphClockCmd( RCC_LED1, ENABLE); 
	/*选择要控制的LED1 GPIOx引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_LED1;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed; 
	/* 设置为推挽输出模式 */
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	/* 设置为上拉 */	
		GPIO_InitStructure.GPIO_PuPd =GPIO_PuPd_UP;
	/*调用库函数，初始化LED1 的GPIOx*/	
  	GPIO_Init(GPIO_LED1_PORT, &GPIO_InitStructure);		  

		/*开启 LED2 的GPIOx的外设时钟*/
	RCC_AHB1PeriphClockCmd( RCC_LED2, ENABLE); 
	/*选择要控制的LED2 GPIOx引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_LED2;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed; 
	/* 设置为推挽输出模式 */
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	/* 设置为上拉 */	
		GPIO_InitStructure.GPIO_PuPd =GPIO_PuPd_UP;
	/*调用库函数，初始化LED1 的GPIOx*/	
  	GPIO_Init(GPIO_LED2_PORT, &GPIO_InitStructure);	
		
	/* 关闭LED1	*/
	GPIO_ResetBits(GPIO_LED1_PORT, GPIO_Pin_LED1);
	GPIO_ResetBits(GPIO_LED2_PORT, GPIO_Pin_LED2);	
}




/******************* (C) COPYRIGHT  2016 *****END OF FILE************/
