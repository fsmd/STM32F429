/********************        (C) COPYRIGHT 2016        **************************
 * �ļ���  ��main.c
 * ����    ��STM32F429 USART2 ����    PD5 PD6
 * ʵ��ƽ̨: STM32F429ZIT6
 * ��汾  ��V1.6.1
 * ��д���ڣ�2016-05-16
 * �޸����ڣ�
 * ����    ��
**********************************************************************************/

#include "stm32f4xx.h"
#include "usart2.h"
#include "led.h"
#include "Tim2.h"
#include "chipid.h"

extern uint32_t ChipUniqueID[3];

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
	USART2_Config(115200);
	LED1(OFF);
  LED2(OFF);
	Get_ChipID();
	printf("USART2 Test OK!!\r\n");
	printf("Chip ID is 0x%08X 0x%08X 0x%08X.\r\n",
			ChipUniqueID[0],ChipUniqueID[1],ChipUniqueID[2]);
	printf("Chip Size is %d KBytes.\r\n",(*(__IO uint32_t *)(0X1FFF7A22))&0xFFFF);
	while(1)
	{ 
		
	}	
}
/******************* (C) COPYRIGHT 2016 *****END OF FILE************/


