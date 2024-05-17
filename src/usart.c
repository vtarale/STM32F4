/*
Author: Vihaan Tarale
*/

#include "include/stm32f407.h"

int start() {
    set_usart();
    ENABLE_CLOCK_GPIO(GPIOD_VAL);
    set_moder(GPIOD, MODER_OUTPUT, PIN_12);
    set_otyper(GPIOD, OTYPER_PUSH_PULL, PIN_12);
    set_ospeedr(GPIOD, OSPEEDR_LOW_SPEED, PIN_12);
    set_pupdr(GPIOD, PUPDR_NO_PULL_UP_DOWN, PIN_12);
    int check;
    char c;
    char buf[10];
    while (1) {
        check = LOW;
        send_string(itoa(69, buf, 10));
        send_string("\n\r");
        send_string(itoa(420, buf, 10));
        send_string("\n\r");
        send_string("Skibbidy toilet, gyattt!!!!");
        send_string("\n\r");
        digital_write(GPIOD, HIGH, PIN_12);
        delay(500000);
        check = poll_rx();
        if (check == HIGH){
            c = read_usart();
            send_char(c);
            digital_write(GPIOD, LOW, PIN_12);
            delay(500000);
        }
    }
}