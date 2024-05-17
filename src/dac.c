/*
Author: Vihaan Tarale
*/

#include "include/stm32f407.h"

int start() {
    set_dac(CHANEL_1, OFF);
    set_usart();
    char buffer[4096];
    for (int counter = 4096; counter > 0; --counter){
        send_string(itoa(counter, buffer, 10));
        write_dac(BIT_12, counter, CHANEL_1);
        delay(500000);
    }
}