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

#define DAC_CLOCK_BIT 29

#define SWTRIGR_1 0
#define SWTRIGR_2 1
#define TEN_1 2
#define TEN_2 18
#define TSEL_1 3
#define TSEL_2 19
#define BOFF_1 1
#define BOFF_2 17
#define EN_1 0
#define EN_2 16

void set_dac(int channel, int buffer);
void write_dac(int bit, int val, int channel);

#endif