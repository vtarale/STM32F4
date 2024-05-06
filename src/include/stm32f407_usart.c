/*
Author: Vihaan Tarale
*/

#include "stm32f407_usart.h"

void set_usart();
void send_char(unsigned char c);
void send_string(unsigned char *s);
unsigned char get_char();
int poll_rx();
char read_usart();

void set_usart() {
    ENABLE_CLOCK_GPIO(GPIOA_VAL);
    RCC->APB1ENR |= MASK(USART_CLOCK_BIT);
    set_moder(GPIOA, MODER_AF, USART_PIN_0);
    set_moder(GPIOA, MODER_AF, USART_PIN_1);
    set_af(GPIOA, AF_7, USART_PIN_0);
    set_af(GPIOA, AF_7, USART_PIN_1);
    set_ospeedr(GPIOA, OSPEEDR_VERY_HIGH_SPEED, USART_PIN_0);
    set_ospeedr(GPIOA, OSPEEDR_VERY_HIGH_SPEED, USART_PIN_1);
    USART->CR1 = 0x00;
    USART->CR1 &= ~MASK(12);
    USART->BRR = 0x8A;
    USART->CR1 |= MASK(TX_BIT); 
    USART->CR1 |= MASK(RX_BIT);
    USART->CR1 |= MASK(UE_BIT);
}

void send_char(unsigned char c) {
    while(!(USART->SR & MASK(TC_BIT)));
    USART->DR = c;
}

void send_string(unsigned char *s) {
    while (*s)
        send_char((*s++));
}

unsigned char get_char() {
    while(!(USART->SR & MASK(RXNE_BIT)));
    return (unsigned char)USART->DR;
}

int poll_rx() {
    if ((USART->SR & MASK(RXNE_BIT)))
        return HIGH;
    return LOW;
}

char read_usart() {
    return (char)USART->DR;
}