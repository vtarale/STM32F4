/*
Author: Vihaan Tarale
*/

#ifndef COOLSTUFFF
#define COOLSTUFFF

#include "stm32f407_gpio.h"

struct adc {
    __vui SR;
    __vui CR1;
    __vui CR2;
    __vui SMPR1;
    __vui SMPR2;
    __vui JOFR1;
    __vui JOFR2;
    __vui JOFR3;
    __vui JOFR4;
    __vui HTR;
    __vui LTR; 
    __vui SQR1;
    __vui SQR2;
    __vui SQR3;
    __vui JSQR;
    __vui JDR1;
    __vui JDR2;
    __vui JDR3;
    __vui JDR4;
    __vui DR;
};

struct adc_common {
    __vui CSR;
    __vui CCR;
    __vui CDR;
};

typedef struct adc ADC;
typedef struct adc_common ADC_COM;

#define ADC_1_ADDY 0x40012000U
#define ADC_2_ADDY 0x40012000U + 0x100U
#define ADC_3_ADDY 0x40012000U + 0x200U

#define ADC_COMMON_ADDY 0x40012000U + 0x300U

#define ADC_1 ((ADC *)ADC_1_ADDY)
#define ADC_2 ((ADC *)ADC_2_ADDY)
#define ADC_3 ((ADC *)ADC_3_ADDY)

#define ADC_COMMON ((ADC_COM *)ADC_COMMON_ADDY)

#define ADC_1_CLOCK_BIT 8
#define ADC_2_CLOCK_BIT 9
#define ADC_3_CLOCK_BIT 10

#define ENABLE_CLOCK_ADC_1 (RCC->APB2ENR |= MASK(ADC_1_CLOCK_BIT))
#define ENABLE_CLOCK_ADC_2 (RCC->APB2ENR |= MASK(ADC_2_CLOCK_BIT))
#define ENABLE_CLOCK_ADC_3 (RCC->APB2ENR |= MASK(ADC_3_CLOCK_BIT))

#define DISABLE_CLOCK_ADC_1 (RCC->APB2ENR &= ~MASK(ADC_1_CLOCK_BIT))
#define DISABLE_CLOCK_ADC_2 (RCC->APB2ENR &= ~MASK(ADC_2_CLOCK_BIT))
#define DISABLE_CLOCK_ADC_3 (RCC->APB2ENR &= ~MASK(ADC_3_CLOCK_BIT))

/*
RES[1:0]: Resolution
These bits are written by software to select the resolution of the conversion
00: 12-bit (15 ADCCLK cycles)
01: 10-bit (13 ADCCLK cycles)
10: 8-bit (11 ADCCLK cycles)
11: 6-bit (9 ADCCLK cycles)
*/

#define RES_12 0
#define RES_10 1
#define RES_8 2
#define RES_6 3

#define RES_BIT 24

#define SCAN_BIT 8

void set_adc(ADC *x, int res, int scan); // regular channels only
int start_convo(ADC *x);


#endif