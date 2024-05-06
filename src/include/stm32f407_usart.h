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
    __vui GTPR;
};

// typedef struct usart USART; // uart or usart

#define USART_ADDY 0x40004400U
#define USART ((struct usart *)USART_ADDY)

#define USART_PIN_0 2
#define USART_PIN_1 3

#define UE_BIT 13
#define MANTISSA_BIT 4
#define FRACTION_BIT 0
#define TX_BIT 3
#define RX_BIT 2
#define TC_BIT 6
#define RXNE_BIT 5
#define M_BIT 12

#define USART_CLOCK_BIT 17
#define ENABLE_CLOCK_USART (RCC->APB1ENR |= MASK(USART_CLOCK_BIT))

void set_usart();
void send_char(unsigned char c);
void send_string(unsigned char *s);
unsigned char get_char();
int poll_rx();
char read_usart();

#endif