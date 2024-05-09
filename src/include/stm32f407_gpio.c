/*
Author: Vihaan Tarale
*/

#include "stm32f407_gpio.h"

int start();
void reset_handler(void);
void enable_all_clock();
void disable_all_clock();
void set_moder(GPIO *x, int state, int pin);
void set_otyper(GPIO *x, int state, int pin);
void set_ospeedr(GPIO *x, int state, int pin);
void set_pupdr(GPIO *x, int state, int pin);
void set_bsrr(GPIO *x, int state, int pin);
void write(GPIO *x, int state, int pin);
int read(GPIO *x, int pin);
void set_af(GPIO *x, int function, int pin);

void reset_handler(void) {
    start();
}

extern int __stack_top__;

// Vector Table 
unsigned int vector_table[96] __attribute__((section(".vec"))) = {
	(unsigned int)&__stack_top__, GET_FUNC_ADDY(reset_handler),
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
};

void enable_all_clock() {
    ENABLE_CLOCK_GPIO(GPIOA_VAL);
    ENABLE_CLOCK_GPIO(GPIOB_VAL);
    ENABLE_CLOCK_GPIO(GPIOC_VAL);
    ENABLE_CLOCK_GPIO(GPIOD_VAL);
    ENABLE_CLOCK_GPIO(GPIOE_VAL);
    ENABLE_CLOCK_GPIO(GPIOF_VAL);
    ENABLE_CLOCK_GPIO(GPIOG_VAL);
    ENABLE_CLOCK_GPIO(GPIOH_VAL);
    ENABLE_CLOCK_GPIO(GPIOI_VAL);
    ENABLE_CLOCK_GPIO(GPIOJ_VAL);
    ENABLE_CLOCK_GPIO(GPIOK_VAL);
}

void disable_all_clock() {
    DISABLE_CLOCK_GPIO(GPIOA_VAL);
    DISABLE_CLOCK_GPIO(GPIOB_VAL);
    DISABLE_CLOCK_GPIO(GPIOC_VAL);
    DISABLE_CLOCK_GPIO(GPIOD_VAL);
    DISABLE_CLOCK_GPIO(GPIOE_VAL);
    DISABLE_CLOCK_GPIO(GPIOF_VAL);
    DISABLE_CLOCK_GPIO(GPIOG_VAL);
    DISABLE_CLOCK_GPIO(GPIOH_VAL);
    DISABLE_CLOCK_GPIO(GPIOI_VAL);
    DISABLE_CLOCK_GPIO(GPIOJ_VAL);
    DISABLE_CLOCK_GPIO(GPIOK_VAL);
}

void set_moder(GPIO *x, int state, int pin) {
    x->MODER |= state << (pin * 2);
}

void set_otyper(GPIO *x, int state, int pin) {
    x->OTYPER |= state << pin;
}

void set_ospeedr(GPIO *x, int state, int pin) {
    x->OSPEEDR |= state << (pin * 2);
}

void set_pupdr(GPIO *x, int state, int pin) {
    x->PUPDR |= state << (pin * 2);
}

void set_bsrr(GPIO *x, int state, int pin) {
    int bit = pin;
    if (state > 1)
        bit = pin * 2;
    x->BSRR |= state << bit;
}

void write(GPIO *x, int state, int pin) {
    if (state == HIGH)
        x->ODR |= MASK(pin);
    else
        x->ODR &= ~MASK(pin);
}

int read(GPIO *x, int pin) {
    if (!(x->IDR &(MASK(pin))))
        return HIGH;
    return LOW;
}

void set_af(GPIO *x, int function, int pin) {
    if (pin < 8)
        x->AFR_1 |= function << (pin * 4);
    else
        x->AFR_2 |= function << (pin * 4);
}