/*
Author: Vihaan Tarale
*/

#include "include/stm32f407.h"

int start() {
    set_dac(CHANEL_2, OFF);
    set_usart();
    char buffer[4096];
    unsigned int temp;
    write_dac(BIT_12, 4095, CHANEL_2);
    delay(500000);
    for (int counter = 4095; counter > 0; counter=counter-10){
        send_string(itoa(counter, buffer, 10));
        write_dac(BIT_12, counter, CHANEL_2);
        delay(500000);
        temp = DAC->DOR2;
        send_string("\n\r");
        send_string("BRUH:");
        send_string(itoa(temp, buffer, 10));
        send_string("\n\r");
    }
}