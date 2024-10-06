/*
Author: Vihaan Tarale
*/

#ifndef COOLSTUFF7
#define COOLSTUFF7

#include "stm32f407_gpio.h"
#include "stm32f407_adc.h"

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
    __vui RESERVED_1;
    __vui CCR1;
    __vui CCR2;
    __vui CCR3;
    __vui CCR4;
    __vui RESERVED_2;
    __vui DCR;
    __vui DMAR;
    __vui TIM_OR;
};

#define TIM2_ADDY 0x40000000U
#define TIM3_ADDY 0x40000400U
#define TIM4_ADDY 0x40000800U
#define TIM5_ADDY 0x40000C00U

#define TIM2_VAL 0
#define TIM3_VAL 1
#define TIM4_VAL 2
#define TIM5_VAL 3

#define TIM2 ((struct timer *)TIM2_ADDY)
#define TIM3 ((struct timer *)TIM3_ADDY)
#define TIM4 ((struct timer *)TIM4_ADDY)
#define TIM5 ((struct timer *)TIM5_ADDY)

#define PWM1 6
#define PWM2 7

#define ENABLE_CLOCK_TIM(x) (RCC->APB1ENR |= MASK(x))

#define APB1_CLOCK_SPEED 42

#define CEN_BIT 0

#define OC1M_BIT 4
#define OC2M_BIT 12
#define OC3M_BIT 4
#define OC4M_BIT 12

#define CC1P_BIT 1
#define CC2P_BIT 5
#define CC3P_BIT 9
#define CC4P_BIT 13

#define OC1PE_BIT 3
#define OC2PE_BIT 11
#define OC3PE_BIT 3
#define OC4PE_BIT 11

#define ARPE_BIT 7

#define UG_BIT 0

#define UPDATE_PWM(x) (x->EGR |= MASK(UG_BIT))
#define TURN_ON_PWM(x) (x->CR1 |= MASK(CEN_BIT))
#define TURN_OFF_PWM(x) (x->CR1 &= ~(MASK(CEN_BIT)))

void set_pwm(struct timer *x, int timer_val, int pwm_no, int channel, int polarity, int arr);
void set_duty_cycle(struct timer *x, int duty_cycle, int channel);

#endif