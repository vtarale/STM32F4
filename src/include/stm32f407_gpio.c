/*
Author: Vihaan Tarale
*/

#include "stm32f407_gpio.h"

void reset_handler(void);
void reset_gpio(int x);
void reset_gpio_all();
void set_moder(GPIO *x, int state, int pin, int bit_0, int bit_1);
void set_otyper(GPIO *x, int state, int pin, int bit_0, int bit_1);
void set_ospeedr(GPIO *x, int state, int pin, int bit_0, int bit_1);
void set_pupdr(GPIO *x, int state, int pin, int bit_0, int bit_1);

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

void set_moder(GPIO *x, int state, int pin, int bit_0, int bit_1) {
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

void set_otyper(GPIO *x, int state, int pin, int bit_0, int bit_1) {
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

void set_ospeedr(GPIO *x, int state, int pin, int bit_0, int bit_1) {
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

/*
void set_pupdr(GPIO *x, int state, int pin, int bit_0, int bit_1) {
    switch (state) {
        case OSPEEDR_LOW_SPEED:
            x->OSPEEDR &= ~MASK(bit_0);
            x->OSPEEDR &= ~MASK(bit_1);
            break;
        case OSPEEDR_MEDIUM_SPEED:
            x->OSPEEDR |= MASK(bit_0);
            x->OSPEEDR &= ~MASK(bit_1);
            break;
        case OSPEEDR_HIGH_SPEED:
            x->OSPEEDR &= ~MASK(bit_0);
            x->OSPEEDR |= MASK(bit_1);
            break;
        case OSPEEDR_VERY_HIGH_SPEED:
            x->OSPEEDR |= MASK(bit_0);
            x->OSPEEDR |= MASK(bit_1);
            break;
    }
}
*/