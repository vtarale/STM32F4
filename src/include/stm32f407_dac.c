/*
Author: Vihaan Tarale
*/

#include "stm32f407_dac.h"

void set_dac(int channel, int buffer);
void write_dac(int bit, int val, int channel);

void set_dac(int channel, int buffer) {
    DAC->CR = 0x00;
    if (channel == CHANEL_1) {
        DAC->CR = buffer << 17;
        DAC->CR |= MASK(16);
    } else if (channel == CHANEL_2) {
        DAC->CR = buffer << 1;
        DAC->CR |= MASK(0);
    } else {
        return;
    }
}

void write_dac(int bit, int val, int channel) {
    int buffer;
    if (channel == CHANEL_1) {
        if (bit == BIT_12) {
            DAC->DHR12R1 = 0x00;
            DAC->DHR12R1 = val << 0;
        } else {
            DAC->DHR8R1 = 0x00;
            DAC->DHR8R1 = val << 0;
        }
    } else if (channel == CHANEL_2) {
        if (bit == BIT_12) {
            DAC->DHR12R2 = 0x00;
            DAC->DHR12R2 = val << 0;
        } else {
            DAC->DHR8R2 = 0x00;
            DAC->DHR8R2 = val << 0;
        }
    } else {
        return;
    }
}