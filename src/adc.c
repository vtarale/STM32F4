#include "include/stm32f407_adc.h"

int start() {
    ENABLE_CLOCK_ADC(ADC_1_CLOCK_BIT);
    set_adc(ADC_1, RES_12, ON, 1);
    SET_SQ_1(ADC_1, CHANEL_0);
    set_sampling_time(ADC_1, CHANEL_0, CYCLES_480);
    ENABLE_ADCON(ADC_1);

    unsigned int result;

    while(1) {
        result = start_convo(ADC_1);
    }
}