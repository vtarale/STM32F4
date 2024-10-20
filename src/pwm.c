/*
Author: Vihaan Tarale
*/

#include "include/stm32f407.h"
#include "include/stm32f407_gpio.h"

int set_gpio() {
    ENABLE_CLOCK_GPIO(GPIOD_VAL);
    int led_pin = PIN_13;
    set_moder(GPIOD, MODER_AF, led_pin);
    set_otyper(GPIOD, OTYPER_PUSH_PULL, led_pin);
    set_ospeedr(GPIOD, OSPEEDR_VERY_HIGH_SPEED, led_pin);
    set_pupdr(GPIOD, PUPDR_NO_PULL_UP_DOWN, led_pin);
    set_af(GPIOD, AF_2, led_pin);
}

int start() {
    set_gpio();
    set_usart();
    set_pwm(TIM4, TIM4_VAL, PWM2, CHANEL_2, LOW, 100);
    send_string("ok\n\r");
    // set_duty_cycle(TIM4, 100, CHANEL_2);
    while(1) {}
}