/*
Author: Vihaan Tarale
*/

// running test program to check header file and code

#include "include/stm32f407.h"

int start() {
    ENABLE_CLOCK_GPIO(GPIOD_VAL);
    set_moder(GPIOD, MODER_OUTPUT, PIN_12);
    set_otyper(GPIOD, OTYPER_PUSH_PULL, PIN_12);
    set_ospeedr(GPIOD, OSPEEDR_LOW_SPEED, PIN_12);
    set_pupdr(GPIOD, PUPDR_NO_PULL_UP_DOWN, PIN_12);
    while(1) {
        digital_write(GPIOD, LOW, PIN_12);
        delay(500000);
        digital_write(GPIOD, HIGH, PIN_12);
        delay(500000);
    }
}