/*
Author: Vihaan Tarale
*/

#include "stm32f407_gpio.h"

void reset_handler(void);
void reset_gpio(int x);
void reset_gpio_all();
void set_moder(GPIO *x, int state, int pin);
void set_otyper(GPIO *x, int state, int pin);
void set_ospeedr(GPIO *x, int state, int pin);
void set_pupdr(GPIO *x, int state, int pin);
void set_bsrr(GPIO *x, int state, int pin);
void write(GPIO *x, int state, int pin);

void reset_handler(void) {
    start();
}

void reset_gpio(int x) {
    RCC->AHB1RSTR |= MASK(x); // use of GPIOx_VAL
    RCC->AHB1RSTR &= ~MASK(x);
}

void reset_gpio_all() {
    RCC->AHB1RSTR |= MASK(GPIOA_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOA_VAL);
    RCC->AHB1RSTR |= MASK(GPIOB_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOB_VAL);
    RCC->AHB1RSTR |= MASK(GPIOC_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOC_VAL);
    RCC->AHB1RSTR |= MASK(GPIOD_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOD_VAL);
    RCC->AHB1RSTR |= MASK(GPIOE_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOE_VAL);
    RCC->AHB1RSTR |= MASK(GPIOF_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOF_VAL);
    RCC->AHB1RSTR |= MASK(GPIOG_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOG_VAL);
    RCC->AHB1RSTR |= MASK(GPIOI_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOI_VAL);
    RCC->AHB1RSTR |= MASK(GPIOJ_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOJ_VAL);
    RCC->AHB1RSTR |= MASK(GPIOK_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOK_VAL);
}

void set_moder(GPIO *x, int state, int pin) {
    int bit_0 = pin * 2;
    int bit_1 = bit_0 + 1;
    switch (state) {
        case MODER_INPUT:
            x->MODER |= MASK(bit_0);
            x->MODER &= ~MASK(bit_0);
            x->MODER |= MASK(bit_1);
            x->MODER &= ~MASK(bit_1);
            break;
        case MODER_OUTPUT:
            x->MODER |= MASK(bit_0);
            x->MODER |= MASK(bit_1);
            x->MODER &= ~MASK(bit_1);
            break;
        case MODER_AF:
            x->MODER |= MASK(bit_0);
            x->MODER &= ~MASK(bit_0);
            x->MODER |= MASK(bit_1);
            break;
        case MODER_ANALOG:
            x->MODER |= MASK(bit_0);
            x->MODER |= MASK(bit_1);
            break;
    }
}

void set_otyper(GPIO *x, int state, int pin) {
    switch (state) {
        case OTYPER_PUSH_PULL:
            x->OTYPER |= MASK(pin);
            x->OTYPER &= ~MASK(pin);
            break;
        case OTYPER_OPEN_DRAIN:
            x->OTYPER |= MASK(pin);
            break;
    }
}

void set_ospeedr(GPIO *x, int state, int pin) {
    int bit_0 = pin * 2;
    int bit_1 = bit_0 + 1;
    switch (state) {
        case OSPEEDR_LOW_SPEED:
            x->OSPEEDR |= MASK(bit_0);
            x->OSPEEDR &= ~MASK(bit_0);
            x->OSPEEDR |= MASK(bit_1);
            x->OSPEEDR &= ~MASK(bit_1);
            break;
        case OSPEEDR_MEDIUM_SPEED:
            x->OSPEEDR |= MASK(bit_0);
            x->OSPEEDR |= MASK(bit_1);
            x->OSPEEDR &= ~MASK(bit_1);
            break;
        case OSPEEDR_HIGH_SPEED:
            x->OSPEEDR |= MASK(bit_0);
            x->OSPEEDR &= ~MASK(bit_0);
            x->OSPEEDR |= MASK(bit_1);
            break;
        case OSPEEDR_VERY_HIGH_SPEED:
            x->OSPEEDR |= MASK(bit_0);
            x->OSPEEDR |= MASK(bit_1);
            break;
    }
}

void set_pupdr(GPIO *x, int state, int pin) {
    int bit_0 = pin * 2;
    int bit_1 = bit_0 + 1;
    switch (state) {
        case PUPDR_NO_PULL_UP_DOWN:
            x->PUPDR &= ~MASK(bit_0);
            x->PUPDR &= ~MASK(bit_1);
            break;
        case PUPDR_PULL_UP:
            x->PUPDR |= MASK(bit_0);
            x->PUPDR &= ~MASK(bit_1);
            break;
        case PUPDR_PULL_DOWN:
            x->PUPDR &= ~MASK(bit_0);
            x->PUPDR |= MASK(bit_1);
            break;
    }
}

void set_bsrr(GPIO *x, int state, int pin) {
    int bit = pin;
    if (state > 1) {
        bit = pin * 2;
    }
    switch (state) {
        case BR_NO_ACTION:
            x->BSRR |= MASK(bit);
            x->BSRR &= ~MASK(bit);
            break;
        case BR_RESET:
            x->BSRR |= MASK(bit);
            break;
        case BS_NO_ACTION:
            x->BSRR |= MASK(bit);
            x->BSRR &= ~MASK(bit);
            break;
        case BS_SET:
            x->BSRR |= MASK(bit);
            break;
    }
}

void write(GPIO *x, int state, int pin) {
    if (state == HIGH)
        x->ODR |= MASK(pin);
    else
        x->ODR &= ~MASK(pin);
}