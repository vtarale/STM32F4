/*
Author: Vihaan Tarale
*/

#include "include/stm32f407_adc.h"

void delay(int time) {
    volatile int x = time;
    while (x != 0)
        --x;
}

int start() {
    ENABLE_CLOCK_ADC(ADC_1_CLOCK_BIT);
    set_adc(ADC_1, RES_8, 1, GPIOA, GPIOA_VAL, PIN_0);
    SET_SQ_1(ADC_1, CHANEL_0);
    set_sampling_time(ADC_1, CHANEL_0, CYCLES_480);
    ENABLE_ADCON(ADC_1);

    ENABLE_CLOCK_GPIO(GPIOD_VAL);
    set_moder(GPIOD, MODER_OUTPUT, PIN_12);
    set_otyper(GPIOD, OTYPER_PUSH_PULL, PIN_12);
    set_ospeedr(GPIOD, OSPEEDR_LOW_SPEED, PIN_12);
    set_pupdr(GPIOD, PUPDR_NO_PULL_UP_DOWN, PIN_12);

    set_usart();
    unsigned int result = 0;
    char buf[4096];
    char buf2[1024];
    int counter = 0;
    int temp;

    while(1) {
        result = start_convo(ADC_1);
        temp = (result * 8) / 10000;
        temp = (result/4095*3000);
        send_string(itoa(counter, buf2, 10));
        send_string("Convo start\n\r");
        send_string(itoa(result, buf, 10));
        send_string("\n\r");
        ++counter;
        if (result != 57 || result != 58 || result != 59)
            write(GPIOD, HIGH, PIN_12);
        else
            write(GPIOD, LOW, PIN_12);
        delay(500000);
    }
}