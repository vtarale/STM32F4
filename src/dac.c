/*
Author: Vihaan Tarale
*/

#include "include/stm32f407.h"

int start() {
    set_dac(CHANEL_2, OFF);
    set_usart();
    char buffer[4096];
    write_dac(BIT_12, 4096, CHANEL_2);
    while(1);
    /*
    for (int counter = 4096; counter > 0; counter=counter-10){
        send_string(itoa(counter, buffer, 10));
        send_string("\n\r");
        write_dac(BIT_12, counter, CHANEL_1);
        delay(500000);
    }
    */
}