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

#define UE_BIT 13
#define MANTISSA_BIT 4
#define FRACTION_BIT 0
#define TX_BIT 3
#define RX_BIT 2
#define TC_BIT 6
#define RXNE_BIT 5

#define USART_CLOCK_BIT 17
#define ENABLE_CLOCK_USART (RCC->APB1ENR |= MASK(USART_CLOCK_BIT))

#define USART_CLEAR_ALL (USART->CR1 = 0x00)
#define ENABLE_USART (USART->CR1 |= MASK(UE_BIT))
#define SET_BAUDRATE (USART->BRR |= (7 << FRACTION_BIT) | (24 << MANTISSA_BIT))
#define ENABLE_TX (USART->CR1 |= MASK(TX_BIT))
#define ENABLE_RX (USART->CR1 |= MASK(RX_BIT))

void set_usart();
void send_char(char c);
void send_string(char *s);
char get_char();
int poll_rx();
char read();

#endif