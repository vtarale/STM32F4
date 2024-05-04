/*
Author: Vihaan Tarale
*/

#include "include/stm32f407_usart.h"

void delay(int time) {
    volatile int x = time;
    while (x != 0)
        --x;
}

int start() {
    set_usart();
    ENABLE_CLOCK_GPIO(GPIOD_VAL);
    set_moder(GPIOD, MODER_OUTPUT, PIN_12);
    set_otyper(GPIOD, OTYPER_PUSH_PULL, PIN_12);
    set_ospeedr(GPIOD, OSPEEDR_LOW_SPEED, PIN_12);
    set_pupdr(GPIOD, PUPDR_NO_PULL_UP_DOWN, PIN_12);
    int check;
    char c;
    while (1) {
        check = LOW;
        send_char('h');
        write(GPIOD, HIGH, PIN_12);
        delay(500000);
        check = poll_rx();
        if (check == HIGH){
            c = read_usart();
            send_char(c);
            write(GPIOD, LOW, PIN_12);
            delay(500000);
        }
    }
}