/*
Author: Vihaan Tarale
*/

#include "stm32f407_usart.h"

void set_usart();
void send_char(char c);
void send_string(char *s);
char get_char();
int poll_rx();
char read();

void set_usart() {
    ENABLE_CLOCK_GPIO(GPIOA_VAL);
    ENABLE_CLOCK_USART;
    set_moder(GPIOA, MODER_AF, USART_PIN_0);
    set_moder(GPIOA, MODER_AF, USART_PIN_1);
    set_af(GPIOA, AF_7, USART_PIN_0);
    set_af(GPIOA, AF_7, USART_PIN_1);
    set_ospeedr(GPIOA, OSPEEDR_VERY_HIGH_SPEED, USART_PIN_0);
    set_ospeedr(GPIOA, OSPEEDR_VERY_HIGH_SPEED, USART_PIN_1);
    USART_CLEAR_ALL; ENABLE_USART; SET_BAUDRATE; ENABLE_TX; ENABLE_RX;
}

void send_char(char c) {
    USART->DR = c;
    while(!(USART->SR & MASK(TC_BIT)));
}

void send_string(char *s) {
    while (*s)
        send_char((*s++));
}

char get_char() {
    while(!(USART->SR & MASK(RXNE_BIT)));
    return (char)USART->DR;
}

int poll_rx() {
    if (USART->SR & MASK(RXNE_BIT))
        return HIGH;
    return LOW;
}

char read() {
    return (char)USART->DR;
}