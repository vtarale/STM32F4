/*
Author: Vihaan Tarale
*/

#ifndef COOLSTUFF7
#define COOLSTUFF7

#include "stm32f407_gpio.h"

struct timer {
    __vui CR1;
    __vui CR2;
    __vui SMCR;
    __vui DIER;
    __vui SR;
    __vui EGR;
    __vui CCMR1;
    __vui CCMR2;
    __vui CCER;
    __vui CNT;
    __vui PSC;
    __vui ARR;
    __vui CCR1;
    __vui CCR2;
    __vui CCR3;
    __vui CCR4;
    __vui TEMP;
    __vui DCR;
    __vui DMAR;
    __vui TIM_OR;
};

#define TIM2_ADDY 0x40000000U
#define TIM3_ADDY 0x40000400U
#define TIM4_ADDY 0x40000800U
#define TIM5_ADDY 0x40000C00U

#define TIM2_VAL 0
#define TIM3_VAL 0
#define TIM4_VAL 0
#define TIM5_VAL 0

#define TIM2 ((struct timer *)TIM2_ADDY)
#define TIM3 ((struct timer *)TIM3_ADDY)
#define TIM4 ((struct timer *)TIM4_ADDY)
#define TIM5 ((struct timer *)TIM5_ADDY)

#define ENABLE_CLOCK_TIM(x) (RCC->APB1ENR |= MASK(x))

#define CEN_BIT 0


void set_pwm(struct timer *x, int timer_val);

#endif