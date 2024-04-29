/*
Author: Vihaan Tarale
*/

// running test program to check header file and code

#include "include/stm32f407_gpio.h"

void delay(int time) {
    volatile int x = time * 100;
    while (x != 0)
        --x;
}

int start() {
    reset_gpio_all();
    ENABLE_CLOCK_GPIO(GPIOA_VAL);
    set_moder(GPIOA, MODER_OUTPUT, PIN_5, PIN_5_BIT_0, PIN_5_BIT_1);
    set_otyper(GPIOA, OTYPER_PUSH_PULL, PIN_5, PIN_5_BIT_0, PIN_5_BIT_1);
    set_ospeedr(GPIOA, OSPEEDR_HIGH_SPEED, PIN_5, PIN_5_BIT_0, PIN_5_BIT_1);
    set_pupdr(GPIOA, PUPDR_NO_PULL_UP_DOWN, PIN_5, PIN_5_BIT_0, PIN_5_BIT_1);

    while(1) {
        write(GPIOA, HIGH, PIN_5);
        delay(2000000);
        write(GPIOA, LOW, PIN_5);
        delay(2000000);
    }
}