#ifndef __USART3_H
#define	__USART3_H

#include "stm32f4xx.h"
#include <stdio.h>

void USART3_Config(uint32_t uBaud);
void USART3_Configuration(uint32_t uBaud);
int fputc(int ch, FILE *f);
void USART3_printf(USART_TypeDef* USARTx, uint8_t *Data,...);
void USART3_NVIC_Configuration(void);

#endif /* __USART1_H */
