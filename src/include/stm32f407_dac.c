/*
Author: Vihaan Tarale
*/

#include "stm32f407_dac.h"

void set_dac(int channel, int buffer);
void write_dac(int bit, int val, int channel);

void set_dac(int channel, int buffer) {
    ENABLE_CLOCK_GPIO(GPIOA_VAL);
    RCC->APB1ENR |= MASK(DAC_CLOCK_BIT);
    if (channel == CHANEL_1) {
        set_moder(GPIOA, MODER_ANALOG, PIN_4);
        set_pupdr(GPIOA, PUPDR_NO_PULL_UP_DOWN, PIN_4);
        DAC->CR = buffer << BOFF_1;
        DAC->CR |= MASK(EN_1);
        // DAC->CR = 7 << TSEL_1;
        // DAC->CR |= MASK(TEN_1);
    } else {
        set_moder(GPIOA, MODER_ANALOG, PIN_5);
        set_pupdr(GPIOA, PUPDR_NO_PULL_UP_DOWN, PIN_5);
        DAC->CR = buffer << BOFF_2;
        DAC->CR |= MASK(EN_2);
        // DAC->CR = 7 << TSEL_2;
        // DAC->CR |= MASK(TEN_2);
    }
}

void write_dac(int bit, int val, int channel) {
    if (channel == CHANEL_1) {
        if (bit == BIT_12) {
            DAC->DHR12R1 = 0x00;
            DAC->DHR12R1 = val & 0xFFF;
        } else {
            DAC->DHR8R1 = 0x00;
            DAC->DHR8R1 = val & 0xFF;
        }
        // DAC->SWTRIGR |= MASK(SWTRIGR_1);
    } else {
        if (bit == BIT_12) {
            // DAC->DHR12R2 = 0x00;
            DAC->DHR12R2 = val;
        } else {
            DAC->DHR8R2 = 0x00;
            DAC->DHR8R2 = val & 0xFF;
        }
        // DAC->SWTRIGR |= MASK(SWTRIGR_2);
    }
}