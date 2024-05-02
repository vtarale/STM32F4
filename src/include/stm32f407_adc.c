/*
Author: Vihaan Tarale
*/

#include "stm32f407_adc.h"

void set_adc(ADC *x, int res, int scan, int no_of_convo);
void set_sampling_time(ADC *x, int channel, int sampling_time);
unsigned int start_convo(ADC *x);

void set_adc(ADC *x, int res, int scan, int no_of_convo) {
    x->CR1 |= res << RES_BIT;

    if (scan == ON)
        x->CR1 |= MASK(SCAN_BIT);
    else
        x->CR1 &= ~MASK(SCAN_BIT);

    x->CR2 &= ~MASK(ALIGN_BIT);
    SET_NO_OF_CONVERSIONS(x, (no_of_convo - 1));
}

void set_sampling_time(ADC *x, int channel, int sampling_time) {
    if (channel < 10)
        x->SMPR2 |= sampling_time << (channel * 3);
    else
        x->SMPR1 |= sampling_time << (channel * 3);
}

unsigned int start_convo(ADC *x) {
    x->CR2 |= MASK(SWSTART_BIT);
    while(!(x->SR & EOC_BIT));
    unsigned int result = x->DR;
    return result;
}