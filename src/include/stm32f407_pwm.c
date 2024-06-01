/*
Author: Vihaan Tarale
*/

#include "stm32f407_pwm.h"

void set_pwm(struct timer *x, int timer_val);

void set_pwm(struct timer *x, int timer_val) {
    ENABLE_CLOCK_TIM(timer_val);
    x->ARR = 8399 & 0xFFFF;
    x->CCMR1 = 7 << 4;
    x->CCER |= MASK(1);
    x->CR1 |= MASK(CEN_BIT);
}