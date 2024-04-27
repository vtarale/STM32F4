#include "stm32f407.h"

unsigned int mask(unsigned int shift);
void reset_handler(void);

unsigned int mask(unsigned int shift) {
    return 1UL << shift;
}