/*
Author: Vihaan Tarale
*/

#include "stm32f407_pwm.h"

void set_pwm(struct timer *x, int timer_val, int pwm_no, int channel, int polarity, int arr);
void set_duty_cycle(struct timer *x, int duty_cycle, int channel);

void set_pwm(struct timer *x, int timer_val, int pwm_no, int channel, int polarity, int arr) {
    ENABLE_CLOCK_TIM(timer_val);
    x->CCMR1 = 0x00;
    x->CCMR2 = 0x00;
    /*
    x->CCMR1 = 7 << 4;
    x->CCER |= MASK(1);
    x->CR1 |= MASK(CEN_BIT);
    */
    switch (channel) {
        case CHANEL_1:
            x->CCMR1 = pwm_no << OC1M_BIT;
            x->CCMR1 |= MASK(OC1PE_BIT);
            break;   
        case CHANEL_2:
            x->CCMR1 = pwm_no << OC2M_BIT;
            x->CCMR1 |= MASK(OC2PE_BIT);
            break;   
        case CHANEL_3:
            x->CCMR2 = pwm_no << OC3M_BIT;
            x->CCMR2 |= MASK(OC3PE_BIT);
            break;   
        case CHANEL_4:
            x->CCMR2 = pwm_no << OC4M_BIT;
            x->CCMR2 |= MASK(OC4PE_BIT);
            break;   
    }
    x->PSC = APB1_CLOCK_SPEED - 1;
    x->ARR = arr-1;
    x->CR1 |= MASK(ARPE_BIT);

    if (polarity == LOW) {
        switch (channel) {
        case CHANEL_1:
            x->CCER |= MASK(CC1P_BIT);
            break;   
        case CHANEL_2:
            x->CCER |= MASK(CC2P_BIT);
            break;   
        case CHANEL_3:
            x->CCER |= MASK(CC3P_BIT);
            break;   
        case CHANEL_4:
            x->CCER |= MASK(CC4P_BIT);
            break;   
        }
    }
    TURN_ON_PWM(x);
    x->CCR1 = arr;
    UPDATE_PWM(x);
    TURN_ON_PWM(x);
}

void set_duty_cycle(struct timer *x, int duty_cycle, int channel) {
    unsigned int pulse_length = ((x->ARR + 1) * duty_cycle) / 100 - 1;
    // TURN_OFF_PWM(x);
    if (channel = CHANEL_1)
        x->CCR1 = pulse_length;
    else if (channel = CHANEL_2)
        x->CCR2 = pulse_length;
    else if (channel = CHANEL_3)
        x->CCR3 = pulse_length;
    else 
        x->CCR4 = pulse_length;
    UPDATE_PWM(x);
    // TURN_ON_PWM(x);
}