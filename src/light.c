/*
Author: Vihaan Tarale
*/

// running test program to check header file and code

#include "include/stm32f407_gpio.h"

int start() {
    reset_gpio_all();
    ENABLE_CLOCK_GPIO(GPIOA_VAL);
    set_moder(GPIOA, MODER_OUTPUT, PIN_5, PIN_5_BIT_0, PIN_5_BIT_1);
    set_otyper(GPIOA, OTYPER_PUSH_PULL, PIN_5, PIN_5_BIT_0, PIN_5_BIT_1);
    set_ospeedr(GPIOA, OSPEEDR_HIGH_SPEED, PIN_5, PIN_5_BIT_0, PIN_5_BIT_1);
}