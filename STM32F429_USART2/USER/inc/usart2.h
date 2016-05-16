#ifndef __USART2_H
#define	__USART2_H

#include "stm32f4xx.h"
#include <stdio.h>

void USART2_Config(uint32_t uBaud);
void USART2_Configuration(uint32_t uBaud);
int fputc(int ch, FILE *f);
void USART2_NVIC_Configuration(void);

#endif /* __USART1_H */
