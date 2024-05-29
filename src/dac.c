/*
Author: Vihaan Tarale
*/

#include "include/stm32f407.h"

int start() {
    set_dac(CHANEL_2, OFF);
    ENABLE_CLOCK_ADC(ADC_1_CLOCK_BIT);
    set_adc(ADC_1, RES_12, 1, GPIOA, GPIOA_VAL, PIN_0);
    SET_SQ_1(ADC_1, CHANEL_0);
    set_sampling_time(ADC_1, CHANEL_0, CYCLES_480);
    ENABLE_ADCON(ADC_1);
    // set_usart();
    char buffer[4096];
    unsigned int temp;
    unsigned int result;
    write_dac(BIT_12, 4095, CHANEL_2);
    while (1) {
        /*
        result = start_convo(ADC_1);
        for (int i = 0; i < 999; ++i)
            result = start_convo(ADC_1) + result;
        // temp = (result * 8) / 10000;
        result = result/1000;
        write_dac(BIT_12, result, CHANEL_2);*/
        for (int counter = 4095; counter > 0; counter -= 10){
            //send_string(itoa(counter, buffer, 10));
            write_dac(BIT_12, counter, CHANEL_2);
            delay(50);
            temp = DAC->DOR2;
            //send_string("\n\r");
            //send_string("BRUH:");
            //send_string(itoa(temp, buffer, 10));
            //send_string("\n\r");
        } 
        for (int counter = 0; counter < 4095; counter += 10){
            //send_string(itoa(counter, buffer, 10));
            write_dac(BIT_12, counter, CHANEL_2);
            delay(50);
            temp = DAC->DOR2;
            //send_string("\n\r");
            //send_string("BRUH:");
            //send_string(itoa(temp, buffer, 10));
            //send_string("\n\r");
        }
    }
}