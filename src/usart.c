/*
Author: Vihaan Tarale
*/

#include "include/stm32f407_usart.h"

int start() {
    set_usart();
    int check;
    char c;
    while (1) {
        send_string("HELLO_WORLD");
        check = poll_rx();
        if (check == HIGH)
            c = read_usart();
            send_char(c);
    }
}