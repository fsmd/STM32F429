/********************       (C) COPYRIGHT 2016  ***************************
 * �ļ���  ��led.h
 * ����    ��led Ӧ�ú�����         
 * ʵ��ƽ̨��
 * Ӳ�����ӣ�-----------------------
 *          |   PG13 - LED1(RUN)     |   
 *          |   PG14 - LED2(RUN)     | 
 *           ----------------------- 
 * ��汾  ��V1.6.1
 * ��д���ڣ�2016-05-16
 * �޸����ڣ�
 * ����    ��
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

//���κ꣬��������������һ��ʹ��
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
