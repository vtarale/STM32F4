/*
Author: Vihaan Tarale
*/

#ifndef COOLSTUFFF
#define COOLSTUFFF

#include "stm32f407_gpio.h"

struct usart {
    __vui SR;
    __vui DR;
    __vui BRR;
    __vui CR1;
    __vui CR2;
    __vui CR3;
    __vui CR1;
    __vui GTPR;
};

typedef usart USART; // uart or usart

#define USART_ADDY 0x40004400U
#define USART ((USART *)USART_ADDY)

#define USART_PIN_0 2
#define USART_PIN_1 3

#define USART_CLOCK_BIT 17
#define ENABLE_CLOCK_USART (RCC->APB1ENR |= MASK(USART_CLOCK_BIT))

#define USART_CLEAR_ALL (USART->CR1 = 0x00)

void set_usart();

#endif