/*
Author: Vihaan Tarale
*/

#include "stm32f407_gpio.h"

int start();
void reset_handler(void);
void reset_gpio(int x);
void enable_all_clock();
void reset_gpio_all();
void set_moder(GPIO *x, int state, int pin);
void set_otyper(GPIO *x, int state, int pin);
void set_ospeedr(GPIO *x, int state, int pin);
void set_pupdr(GPIO *x, int state, int pin);
void set_bsrr(GPIO *x, int state, int pin);
void write(GPIO *x, int state, int pin);
int read(GPIO *x, int pin);
void set_af(GPIO *x, int state, int pin);

void reset_handler(void) {
    start();
}

// Vector Table 
unsigned int vector_table[96] __attribute__((section(".vec"))) = {
	0x20001000u, GET_FUNC_ADDY(reset_handler),
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

void reset_gpio(int x) {
    RCC->AHB1RSTR |= MASK(x); // use of GPIOx_VAL
    RCC->AHB1RSTR &= ~MASK(x);
}

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

void reset_gpio_all() {
    RCC->AHB1RSTR |= MASK(GPIOA_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOA_VAL);
    RCC->AHB1RSTR |= MASK(GPIOB_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOB_VAL);
    RCC->AHB1RSTR |= MASK(GPIOC_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOC_VAL);
    RCC->AHB1RSTR |= MASK(GPIOD_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOD_VAL);
    RCC->AHB1RSTR |= MASK(GPIOE_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOE_VAL);
    RCC->AHB1RSTR |= MASK(GPIOF_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOF_VAL);
    RCC->AHB1RSTR |= MASK(GPIOG_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOG_VAL);
    RCC->AHB1RSTR |= MASK(GPIOI_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOI_VAL);
    RCC->AHB1RSTR |= MASK(GPIOJ_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOJ_VAL);
    RCC->AHB1RSTR |= MASK(GPIOK_VAL);
    RCC->AHB1RSTR &= ~MASK(GPIOK_VAL);
}

void set_moder(GPIO *x, int state, int pin) {
    int bit_0 = pin * 2;
    int bit_1 = bit_0 + 1;
    switch (state) {
        case MODER_INPUT:
            x->MODER |= MASK(bit_0);
            x->MODER &= ~MASK(bit_0);
            x->MODER |= MASK(bit_1);
            x->MODER &= ~MASK(bit_1);
            break;
        case MODER_OUTPUT:
            x->MODER |= MASK(bit_0);
            x->MODER |= MASK(bit_1);
            x->MODER &= ~MASK(bit_1);
            break;
        case MODER_AF:
            x->MODER |= MASK(bit_0);
            x->MODER &= ~MASK(bit_0);
            x->MODER |= MASK(bit_1);
            break;
        case MODER_ANALOG:
            x->MODER |= MASK(bit_0);
            x->MODER |= MASK(bit_1);
            break;
    }
}

void set_otyper(GPIO *x, int state, int pin) {
    switch (state) {
        case OTYPER_PUSH_PULL:
            x->OTYPER |= MASK(pin);
            x->OTYPER &= ~MASK(pin);
            break;
        case OTYPER_OPEN_DRAIN:
            x->OTYPER |= MASK(pin);
            break;
    }
}

void set_ospeedr(GPIO *x, int state, int pin) {
    int bit_0 = pin * 2;
    int bit_1 = bit_0 + 1;
    switch (state) {
        case OSPEEDR_LOW_SPEED:
            x->OSPEEDR |= MASK(bit_0);
            x->OSPEEDR &= ~MASK(bit_0);
            x->OSPEEDR |= MASK(bit_1);
            x->OSPEEDR &= ~MASK(bit_1);
            break;
        case OSPEEDR_MEDIUM_SPEED:
            x->OSPEEDR |= MASK(bit_0);
            x->OSPEEDR |= MASK(bit_1);
            x->OSPEEDR &= ~MASK(bit_1);
            break;
        case OSPEEDR_HIGH_SPEED:
            x->OSPEEDR |= MASK(bit_0);
            x->OSPEEDR &= ~MASK(bit_0);
            x->OSPEEDR |= MASK(bit_1);
            break;
        case OSPEEDR_VERY_HIGH_SPEED:
            x->OSPEEDR |= MASK(bit_0);
            x->OSPEEDR |= MASK(bit_1);
            break;
    }
}

void set_pupdr(GPIO *x, int state, int pin) {
    int bit_0 = pin * 2;
    int bit_1 = bit_0 + 1;
    switch (state) {
        case PUPDR_NO_PULL_UP_DOWN:
            x->PUPDR &= ~MASK(bit_0);
            x->PUPDR &= ~MASK(bit_1);
            break;
        case PUPDR_PULL_UP:
            x->PUPDR |= MASK(bit_0);
            x->PUPDR &= ~MASK(bit_1);
            break;
        case PUPDR_PULL_DOWN:
            x->PUPDR &= ~MASK(bit_0);
            x->PUPDR |= MASK(bit_1);
            break;
    }
}

void set_bsrr(GPIO *x, int state, int pin) {
    int bit = pin;
    if (state > 1) {
        bit = pin * 2;
    }
    switch (state) {
        case BR_NO_ACTION:
            x->BSRR |= MASK(bit);
            x->BSRR &= ~MASK(bit);
            break;
        case BR_RESET:
            x->BSRR |= MASK(bit);
            break;
        case BS_NO_ACTION:
            x->BSRR |= MASK(bit);
            x->BSRR &= ~MASK(bit);
            break;
        case BS_SET:
            x->BSRR |= MASK(bit);
            break;
    }
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
    if ((x->IDR &(MASK(pin))))
        return LOW;
}

void set_af(GPIO *x, int state, int pin) {
    if (pin < 8) {
        switch (state) {
            case AF_0:
                break; // 0000
            case AF_1:
                x->AFR_1 |= MASK(pin * 4); // 0001
                break;
            case AF_2:
                x->AFR_1 |= MASK((pin * 4) + 1); // 0010
                break;
            case AF_3:
                x->AFR_1 |= MASK(pin * 4); // 0011
                x->AFR_1 |= MASK((pin * 4) + 1);
                break;
            case AF_4:
                x->AFR_1 |= MASK((pin * 4) + 2); // 0100
                break;
            case AF_5:
                x->AFR_1 |= MASK(pin * 4); // 0101
                x->AFR_1 |= MASK((pin * 4) + 2);
                break;
            case AF_6:
                x->AFR_1 |= MASK((pin * 4) + 1); // 0110
                x->AFR_1 |= MASK((pin * 4) + 2);
                break;
            case AF_7:
                x->AFR_1 |= MASK(pin * 4); // 0111
                x->AFR_1 |= MASK((pin * 4) + 1);
                x->AFR_1 |= MASK((pin * 4) + 2);
                break;
            case AF_8:
                x->AFR_1 |= MASK((pin * 4) + 3); // 1000
                break;
            case AF_9:
                x->AFR_1 |= MASK(pin * 4); // 1001
                x->AFR_1 |= MASK((pin * 4) + 3);
                break;
            case AF_10:
                x->AFR_1 |= MASK((pin * 4) + 1); // 1010
                x->AFR_1 |= MASK((pin * 4) + 3);
                break;
            case AF_11:
                x->AFR_1 |= MASK(pin * 4); // 1011
                x->AFR_1 |= MASK((pin * 4) + 1);
                x->AFR_1 |= MASK((pin * 4) + 3);
                break;
            case AF_12:
                x->AFR_1 |= MASK((pin * 4) + 2); // 1100
                x->AFR_1 |= MASK((pin * 4) + 3);
                break;
            case AF_13:
                x->AFR_1 |= MASK(pin * 4); // 1101
                x->AFR_1 |= MASK((pin * 4) + 2);
                x->AFR_1 |= MASK((pin * 4) + 3);
                break;
            case AF_14:
                x->AFR_1 |= MASK((pin * 4) + 1); // 1110
                x->AFR_1 |= MASK((pin * 4) + 2);
                x->AFR_1 |= MASK((pin * 4) + 3);
                break;
            case AF_15:
                x->AFR_1 |= MASK(pin * 4); // 1111
                x->AFR_1 |= MASK((pin * 4) + 1);
                x->AFR_1 |= MASK((pin * 4) + 2);
                x->AFR_1 |= MASK((pin * 4) + 3);
                break;
        }
    } else {
        switch (state) {
            case AF_0:
                break; // 0000
            case AF_1:
                x->AFR_2 |= MASK(pin * 4); // 0001
                break;
            case AF_2:
                x->AFR_2 |= MASK((pin * 4) + 1); // 0010
                break;
            case AF_3:
                x->AFR_2 |= MASK(pin * 4); // 0011
                x->AFR_2 |= MASK((pin * 4) + 1);
                break;
            case AF_4:
                x->AFR_2 |= MASK((pin * 4) + 2); // 0100
                break;
            case AF_5:
                x->AFR_2 |= MASK(pin * 4); // 0101
                x->AFR_2 |= MASK((pin * 4) + 2);
                break;
            case AF_6:
                x->AFR_2 |= MASK((pin * 4) + 1); // 0110
                x->AFR_2 |= MASK((pin * 4) + 2);
                break;
            case AF_7:
                x->AFR_2 |= MASK(pin * 4); // 0111
                x->AFR_2 |= MASK((pin * 4) + 1);
                x->AFR_2 |= MASK((pin * 4) + 2);
                break;
            case AF_8:
                x->AFR_2 |= MASK((pin * 4) + 3); // 1000
                break;
            case AF_9:
                x->AFR_2 |= MASK(pin * 4); // 1001
                x->AFR_2 |= MASK((pin * 4) + 3);
                break;
            case AF_10:
                x->AFR_2 |= MASK((pin * 4) + 1); // 1010
                x->AFR_2 |= MASK((pin * 4) + 3);
                break;
            case AF_11:
                x->AFR_2 |= MASK(pin * 4); // 1011
                x->AFR_2 |= MASK((pin * 4) + 1);
                x->AFR_2 |= MASK((pin * 4) + 3);
                break;
            case AF_12:
                x->AFR_2 |= MASK((pin * 4) + 2); // 1100
                x->AFR_2 |= MASK((pin * 4) + 3);
                break;
            case AF_13:
                x->AFR_2 |= MASK(pin * 4); // 1101
                x->AFR_2 |= MASK((pin * 4) + 2);
                x->AFR_2 |= MASK((pin * 4) + 3);
                break;
            case AF_14:
                x->AFR_2 |= MASK((pin * 4) + 1); // 1110
                x->AFR_2 |= MASK((pin * 4) + 2);
                x->AFR_2 |= MASK((pin * 4) + 3);
                break;
            case AF_15:
                x->AFR_2 |= MASK(pin * 4); // 1111
                x->AFR_2 |= MASK((pin * 4) + 1);
                x->AFR_2 |= MASK((pin * 4) + 2);
                x->AFR_2 |= MASK((pin * 4) + 3);
                break;
        }
    }
}