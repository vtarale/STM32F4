/*
Author: Vihaan Tarale
*/

#include "stm32f407_pwm.h"

void set_pwm(struct timer *x, int timer_val, int pwm_no, int channel, int polarity);

void set_pwm(struct timer *x, int timer_val, int pwm_no, int channel, int polarity) {
    ENABLE_CLOCK_TIM(timer_val);
    x->ARR = 8399 & 0xFFFF;
    /*
    x->CCMR1 = 7 << 4;
    x->CCER |= MASK(1);
    x->CR1 |= MASK(CEN_BIT);
    */
    switch (channel) {
        case CHANEL_1:
            x->CCMR1 = pwm_no << OC1M_BIT;
            break;   
        case CHANEL_2:
            x->CCMR1 = pwm_no << OC2M_BIT;
            break;   
        case CHANEL_3:
            x->CCMR2 = pwm_no << OC3M_BIT;
            break;   
        case CHANEL_4:
            x->CCMR2 = pwm_no << OC4M_BIT;
            break;   
    }
    if (polarity = LOW) {
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
        
   
}