/*
Author: Vihaan Tarale
*/

#ifndef COOLSTUFFF2
#define COOLSTUFFF2

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

#define ENABLE_CLOCK_ADC(x) (RCC->APB2ENR |= MASK(x))
#define DISABLE_CLOCK_ADC(x) (RCC->APB2ENR &= ~MASK(x))

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
#define ALIGN_BIT 11
#define SWSTART_BIT 30
#define ADCON_BIT 0
#define EOCS_BIT 10
#define EOC_BIT 1

#define CHANEL_0 0
#define CHANEL_1 1
#define CHANEL_2 2
#define CHANEL_3 3
#define CHANEL_4 4
#define CHANEL_5 5
#define CHANEL_6 6
#define CHANEL_7 7
#define CHANEL_8 8
#define CHANEL_9 9
#define CHANEL_10 10
#define CHANEL_11 11
#define CHANEL_12 12
#define CHANEL_13 13
#define CHANEL_14 14
#define CHANEL_15 15
#define CHANEL_16 16
#define CHANEL_17 17
#define CHANEL_18 18

#define CYCLES_3 0
#define CYCLES_15 1
#define CYCLES_28 2
#define CYCLES_56 3
#define CYCLES_84 4
#define CYCLES_112 5
#define CYCLES_144 6
#define CYCLES_480 7

#define SET_SQ_1(x, y) (x->SQR3 |= y << 0) 
#define SET_SQ_2(x, y) (x->SQR3 |= y << 5) 
#define SET_SQ_3(x, y) (x->SQR3 |= y << 10) 
#define SET_SQ_4(x, y) (x->SQR3 |= y << 15) 
#define SET_SQ_5(x, y) (x->SQR3 |= y << 20)
#define SET_SQ_6(x, y) (x->SQR3 |= y << 25)  

#define SET_SQ_7(x, y) (x->SQR2 |= y << 0) 
#define SET_SQ_8(x, y) (x->SQR2 |= y << 5) 
#define SET_SQ_9(x, y) (x->SQR2 |= y << 10) 
#define SET_SQ_10(x, y) (x->SQR2 |= y << 15) 
#define SET_SQ_11(x, y) (x->SQR2 |= y << 20)
#define SET_SQ_12(x, y) (x->SQR2 |= y << 25) 

#define SET_SQ_13(x, y) (x->SQR1 |= y << 0) 
#define SET_SQ_14(x, y) (x->SQR1 |= y << 5) 
#define SET_SQ_15(x, y) (x->SQR1 |= y << 10) 
#define SET_SQ_16(x, y) (x->SQR1 |= y << 15) 

#define SET_NO_OF_CONVERSIONS(x, y) (x->SQR1 |= y << 20)

#define ENABLE_ADCON(x) (x->CR2 |= MASK(ADCON_BIT))
#define DISABLE_ADCON(x) (x->CR2 &= ~MASK(ADCON_BIT))

#define ENABLE_EOCS(x) (x->CR2 |= MASK(EOCS_BIT))
#define DISABLE_EOCS(x) (x->CR2 &= ~MASK(EOCS_BIT))

void set_adc(ADC *x, int res, int scan, int no_of_convo); // regular channels only
void set_sampling_time(ADC *x, int channel, int sampling_time);
unsigned int start_convo(ADC *x);


#endif