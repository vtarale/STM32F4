/*
Author: Vihaan Tarale
*/

#include "stm32f407_adc.h"

void set_adc(ADC *x, int res, int no_of_convo, GPIO *y, int gpio_val, int pin);
void set_sampling_time(ADC *x, int channel, int sampling_time);
unsigned int start_convo(ADC *x);

void set_adc(ADC *x, int res, int no_of_convo, GPIO *y,int gpio_val, int pin) {
    ENABLE_CLOCK_GPIO(gpio_val);
    set_moder(y, MODER_ANALOG, pin);
    set_pupdr(y, PUPDR_NO_PULL_UP_DOWN, pin);
    x->CR1 = 0x00;
    x->CR2 = 0x00;
    x->CR1 |= MASK(CONT_BIT);
    x->CR1 |= res << RES_BIT;
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
    while(!(x->SR & MASK(EOC_BIT)));
    unsigned int result = x->DR;
    x->CR2 &= ~MASK(SWSTART_BIT);
    return x->DR;
}