/*
Author: Vihaan Tarale
*/

#include "stm32f407_adc.h"

void set_adc(ADC *x, int res, int scan);

void set_adc(ADC *x, int res, int scan) {
    switch (res) {
        case RES_12:
            break;
        case RES_10:
            x->CR1 |= MASK(RES_BIT_0);
            break;
        case RES_8:
            x->CR1 |= MASK(RES_BIT_1);
            break;
        case RES_6:
            x->CR1 |= MASK(RES_BIT_0) | MASK(RES_BIT_1);
    }
    
    if (scan == ON)
        x->CR1 |= MASK(SCAN_BIT);
    else
        x->CR1 &= ~MASK(SCAN_BIT);
}