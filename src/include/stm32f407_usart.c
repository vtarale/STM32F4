/*
Author: Vihaan Tarale
*/

#include "stm32f407_usart.h"

void set_usart();

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