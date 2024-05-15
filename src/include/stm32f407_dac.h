/*
Author: Vihaan Tarale
*/

#ifndef COOLSTUFFF4
#define COOLSTUFFF4

#include "stm32f407_gpio.h"

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

typedef struct dac DAC;

#define DAC_ADDY 0x40007400U

#endif