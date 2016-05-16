/********************       (C) COPYRIGHT 2016  ***************************
 * 文件名  ：led.h
 * 描述    ：led 应用函数库         
 * 实验平台：
 * 硬件连接：-----------------------
 *          |   PG13 - LED1(RUN)     |   
 *          |   PG14 - LED2(RUN)     | 
 *           ----------------------- 
 * 库版本  ：V1.6.1
 * 编写日期：2016-05-16
 * 修改日期：
 * 作者    ：
****************************************************************************/
#ifndef __LED_H
#define	__LED_H

#include "stm32f4xx.h"

/* the macro definition to trigger the led on or off 
 * 1 - off
 - 0 - on
 */
#define ON  1
#define OFF 0

#define RCC_LED1						RCC_AHB1Periph_GPIOG
#define GPIO_LED1_PORT			GPIOG
#define GPIO_Pin_LED1				GPIO_Pin_13

#define RCC_LED2						RCC_AHB1Periph_GPIOG
#define GPIO_LED2_PORT			GPIOG
#define GPIO_Pin_LED2				GPIO_Pin_14

//带参宏，可以像内联函数一样使用
#define LED1(a)	if (a)	\
					GPIO_SetBits(GPIO_LED1_PORT,GPIO_Pin_LED1);\
					else		\
					GPIO_ResetBits(GPIO_LED1_PORT,GPIO_Pin_LED1)

#define LED2(a)	if (a)	\
					GPIO_SetBits(GPIO_LED2_PORT,GPIO_Pin_LED2);\
					else		\
					GPIO_ResetBits(GPIO_LED2_PORT,GPIO_Pin_LED2)
					

void LED_GPIO_Config(void);

#endif /* __LED_H */
