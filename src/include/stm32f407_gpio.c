/*
Author: Vihaan Tarale
*/

#include "stm32f407_gpio.h"

void reset_handler(void);
void set_moder(GPIO *x, int state, int gpio, int bit_0, int bit_1);

void reset_handler(void) {
    start();
}

void set_moder(GPIO *x, int state, int gpio, int bit_0, int bit_1) {
    switch (state)
    {
    case MODER_INPUT:
        x->MODER &= ~MASK(bit_0);
        x->MODER &= ~MASK(bit_1);
        break;
    case MODER_OUTPUT:
        x->MODER |= MASK(bit_0);
        x->MODER &= ~MASK(bit_1);
        break;
    case MODER_AF:
        x->MODER &= ~MASK(bit_0);
        x->MODER |= MASK(bit_1);
        break;
    case MODER_ANALOG:
        x->MODER |= MASK(bit_0);
        x->MODER |= MASK(bit_1);
        break;
    }
}