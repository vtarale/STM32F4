/*
Author: Vihaan Tarale
*/

#include "stm32f407_dac.h"

void set_dac(int channel, int buffer);
void write_dac(int bit, int val, int channel);

void set_dac(int channel, int buffer) {
    ENABLE_CLOCK_GPIO(GPIOA_VAL);
    RCC->APB1ENR |= MASK(29);
    if (channel == CHANEL_1) {
        set_moder(GPIOA, MODER_ANALOG, PIN_4);
        set_pupdr(GPIOA, PUPDR_NO_PULL_UP_DOWN, PIN_4);
        DAC->CR = buffer << 1;
        DAC->CR |= MASK(0);
        DAC->CR = 3 << 2;
        DAC->CR |= MASK(3);
    } else {
        set_moder(GPIOA, MODER_ANALOG, PIN_5);
        set_pupdr(GPIOA, PUPDR_NO_PULL_UP_DOWN, PIN_5);
        DAC->CR = buffer << 17;
        DAC->CR |= MASK(16);
        DAC->CR = 3 << 19;
        DAC->CR |= MASK(18);
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
        DAC->SWTRIGR |= MASK(0);
    } else {
        if (bit == BIT_12) {
            DAC->DHR12R2 = 0x00;
            DAC->DHR12R2 = val & 0xFFF;
        } else {
            DAC->DHR8R2 = 0x00;
            DAC->DHR8R2 = val & 0xFF;
        }
        DAC->SWTRIGR |= MASK(0);
    }
}