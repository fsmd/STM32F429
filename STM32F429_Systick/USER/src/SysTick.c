/**
  ******************************************************************************
  * @file    main.c 
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    13-April-2012
  * @brief   Main program body
  ******************************************************************************
 */

  /* Setup SysTick Timer for 1 msec interrupts.
     ------------------------------------------
    1. The SysTick_Config() function is a CMSIS function which configure:
       - The SysTick Reload register with value passed as function parameter.
       - Configure the SysTick IRQ priority to the lowest value (0x0F).
       - Reset the SysTick Counter register.
       - Configure the SysTick Counter clock source to be Core Clock Source (HCLK).
       - Enable the SysTick Interrupt.
       - Start the SysTick Counter.
    
    2. You can change the SysTick Clock source to be HCLK_Div8 by calling the
       SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8) just after the
       SysTick_Config() function call. The SysTick_CLKSourceConfig() is defined
       inside the misc.c file.

    3. You can change the SysTick IRQ priority by calling the
       NVIC_SetPriority(SysTick_IRQn,...) just after the SysTick_Config() function 
       call. The NVIC_SetPriority() is defined inside the core_cm4.h file.

    4. To adjust the SysTick time base, use the following formula:
                            
         Reload Value = SysTick Counter Clock (Hz) x  Desired Time base (s)
    
       - Reload Value is the parameter to be passed for SysTick_Config() function
       - Reload Value should not exceed 0xFFFFFF
   */
	 
	 
#include "stm32f4xx.h"
#include "SysTick.h"

__IO uint32_t TimingDelay;

/******************************************************************************************
*�������ƣ�void SysTick_Init(void)
*
*��ڲ�������
*
*���ڲ�������
*
*����˵����SysTick��ʼ��  �����ʼ��ʧ�ܣ���ͣ��WHILE��ѭ��
*******************************************************************************************/
void SysTick_Init(void)
{
    if (SysTick_Config(SystemCoreClock / 1000))    //1ms
    { 
        while (1); //��ʼ��ʧ��
    }
}

/******************************************************************************************
*�������ƣ�void Delay(__IO uint32_t nTime)
*
*��ڲ�������
*
*���ڲ�������
*
*����˵�������ⲿ���õ���ʱ����
*******************************************************************************************/
void Delay_ms(__IO uint32_t nTime)
{ 
    TimingDelay = nTime;
    
    while(TimingDelay != 0);
}

/******************************************************************************************
*�������ƣ�void TimingDelay_Decrement(void)
*
*��ڲ�������
*
*���ڲ�������
*
*����˵����SysTick�жϵ��ú���
*******************************************************************************************/
void TimingDelay_Decrement(void)
{
    if (TimingDelay != 0x00)
    { 
        TimingDelay--;
    }
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */

void SysTick_Handler(void)
{
  TimingDelay_Decrement();
}

