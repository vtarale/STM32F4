/*
Author: Vihaan Tarale
*/

#include "stm32f407_adc.h"

void set_adc(ADC *x, int res, int scan);

void set_adc(ADC *x, int res, int scan) {
    x->CR1 |= res << RES_BIT;
    if (scan == ON)
        x->CR1 |= MASK(SCAN_BIT);
    else
        x->CR1 &= ~MASK(SCAN_BIT);

    x->SQR3 |= 1 << 0; // seclecting channel 0 
}