/********************       (C) COPYRIGHT 2014  ***************************
 * �ļ���  ��led.c
 * ����    ��led Ӧ�ú�����         
 * ʵ��ƽ̨��
 * Ӳ�����ӣ�-----------------------
 *          |   PG13 - LED1(RUN)     |  
 *          |   PG14 - LED2(RUN)     |  
 *           ----------------------- 
 * ��汾  ��ST3.5.0
 * ��д���ڣ�2016-05-16
 * �޸����ڣ�
 * ����    ��
****************************************************************************/
#include "led.h"

/*
 * ��������LED_GPIO_Config
 * ����  ������LED�õ���I/O��
 * ����  ����
 * ���  ����
 */
void LED_GPIO_Config(void)
{		
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*���� LED1 ��GPIOx������ʱ��*/
	RCC_AHB1PeriphClockCmd( RCC_LED1, ENABLE); 
	/*ѡ��Ҫ���Ƶ�LED1 GPIOx����*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_LED1;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed; 
	/* ����Ϊ�������ģʽ */
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	/* ����Ϊ���� */	
		GPIO_InitStructure.GPIO_PuPd =GPIO_PuPd_UP;
	/*���ÿ⺯������ʼ��LED1 ��GPIOx*/	
  	GPIO_Init(GPIO_LED1_PORT, &GPIO_InitStructure);		  

		/*���� LED2 ��GPIOx������ʱ��*/
	RCC_AHB1PeriphClockCmd( RCC_LED2, ENABLE); 
	/*ѡ��Ҫ���Ƶ�LED2 GPIOx����*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_LED2;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed; 
	/* ����Ϊ�������ģʽ */
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	/* ����Ϊ���� */	
		GPIO_InitStructure.GPIO_PuPd =GPIO_PuPd_UP;
	/*���ÿ⺯������ʼ��LED1 ��GPIOx*/	
  	GPIO_Init(GPIO_LED2_PORT, &GPIO_InitStructure);	
		
	/* �ر�LED1	*/
	GPIO_ResetBits(GPIO_LED1_PORT, GPIO_Pin_LED1);
	GPIO_ResetBits(GPIO_LED2_PORT, GPIO_Pin_LED2);	
}




/******************* (C) COPYRIGHT  2016 *****END OF FILE************/
