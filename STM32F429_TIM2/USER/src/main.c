/********************        (C) COPYRIGHT 2016        **************************
 * �ļ���  ��main.c
 * ����    ��STM32F429 ��ʱ������ LED����    
 * ʵ��ƽ̨: STM32F429ZIT6
 * ��汾  ��V1.6.1
 * ��д���ڣ�2016-05-16
 * �޸����ڣ�
 * ����    ��
**********************************************************************************/

#include "stm32f4xx.h"
#include "led.h"
#include "Tim2.h"

/* 
 * ��������main
 * ����  : "����"��������
 * ����  ����
 * ���  : ��
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


