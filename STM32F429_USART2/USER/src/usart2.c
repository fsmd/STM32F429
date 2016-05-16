/********************     (C)  2016     ***************************
 * 文件名 	：usart2.c
 * 描述   	：将printf函数重定向到USART2。这样就可以用printf函数将单片机的数据
 *        	  打印到PC上的超级终端或串口调试助手。         
 * 实验平台	：STM32F429
 * 硬件连接	：------------------------
 *          | PD5  - USART2(Tx)      |
 *          | PD6  - USART2(Rx)      |
 *           ------------------------
 * 库版本  	：V1.6.1
 * 编写日期	：2016-05-10
 * 修改日期	：
 * 作者    	：
*****************************************************************************/
#include "usart2.h"
#include <stdarg.h>

/*
 * 函数名：USART2_Config
 * 描述  ：USART2 GPIO 配置
 * 输入  ：uint32_t uBaud
 * 输出  : 无
 * 调用  ：外部调用
 */
void USART2_Config(uint32_t uBaud)
{
	USART2_Configuration(uBaud);
	USART2_NVIC_Configuration();
}


/*
 * 函数名：USART2_Configuration
 * 描述  ：USART2 GPIO 配置,工作模式配置。uBaud 8-N-1
 * 输入  ：uint32_t uBaud
 * 输出  : 无
 * 调用  ：外部调用
 */
void USART2_Configuration(uint32_t uBaud)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	/* config USART2 clock */

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_USART2);   
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource6, GPIO_AF_USART2);
	
	/* USART2 GPIO config */
	/* Configure USART2 Tx (PD.05) as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);    
	/* Configure USART2 Rx (PD.06) as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	//GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	  
	/* USART2 mode config */
	USART_InitStructure.USART_BaudRate = uBaud;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART2, &USART_InitStructure); 
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART2, ENABLE);
}


void USART2_NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 
	/* Configure the NVIC Preemption Priority Bits */  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
	/* Enable the USARTy Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;	 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}



/*
 * 函数名：fputc
 * 描述  ：重定向c库函数printf到USART2
 * 输入  ：无
 * 输出  ：无
 * 调用  ：由printf调用
 */
int fputc(int ch, FILE *f)
{
	/* 将Printf内容发往串口 */
	USART_SendData(USART2, (unsigned char) ch);
	while (!(USART2->SR & USART_FLAG_TXE));
	//while( USART_GetFlagStatus(USART1,USART_FLAG_TC)!= SET);	
	return (ch);
}

/******************* (C) COPYRIGHT 2016  *****END OF FILE************/

