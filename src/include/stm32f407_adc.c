/*
Author: Vihaan Tarale
*/

#include "stm32f407_adc.h"

void set_adc(ADC *x, int res, int scan, int no_of_convo);

void set_adc(ADC *x, int res, int scan,int no_of_convo) {
    x->CR1 |= res << RES_BIT;

    if (scan == ON)
        x->CR1 |= MASK(SCAN_BIT);
    else
        x->CR1 &= ~MASK(SCAN_BIT);
        
    SET_NO_OF_CONVERSIONS(x, no_of_convo);
}