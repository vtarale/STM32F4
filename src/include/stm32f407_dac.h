/*
Author: Vihaan Tarale
*/

#ifndef COOLSTUFFF4
#define COOLSTUFFF4

#include "stm32f407_gpio.h"
#include "stm32f407_adc.h"

struct dac {
    __vui CR;
    __vui SWTRIGR;
    __vui DHR12R1;
    __vui DHR12L1;
    __vui DHR8R1;
    __vui DHR12R2;
    __vui DHR12L2;
    __vui DHR8R2;
    __vui DHR12RD;
    __vui DHR12LD;
    __vui DHR8RD;
    __vui DOR1;
    __vui DOR2;
    __vui SR;    
};

#define DAC_ADDY 0x40007400U

#define DAC ((struct dac *)DAC_ADDY)

#define BIT_8 0
#define BIT_12 1

void set_dac(int channel, int buffer);
void write_dac(int bit, int val, int channel);

#endif