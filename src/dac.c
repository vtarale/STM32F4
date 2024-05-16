/*
Author: Vihaan Tarale
*/

#include "include/stm32f407.h"

int start() {
    set_dac(CHANEL_1, OFF);
    for (int counter = 4096; counter > 0; --counter)
        write_dac(BIT_12, counter, CHANEL_1);
}