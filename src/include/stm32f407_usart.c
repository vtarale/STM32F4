/*
Author: Vihaan Tarale
*/

#include "stm32f407_usart.h"
#include "stm32f407_gpio.h"

void set_usart();
void send_char(unsigned char c);
void send_string(unsigned char *s);
unsigned char get_char();
int poll_rx();
char read_usart();
void swap(char *a, char *b);
void reverse(char *str, int length);
char *itoa(int num, char *str, int base);

void set_usart() {
    ENABLE_CLOCK_GPIO(GPIOA_VAL);
    RCC->APB1ENR |= MASK(USART_CLOCK_BIT);
    set_moder(GPIOA, MODER_AF, USART_PIN_0);
    set_moder(GPIOA, MODER_AF, USART_PIN_1);
    set_af(GPIOA, AF_7, USART_PIN_0);
    set_af(GPIOA, AF_7, USART_PIN_1);
    set_ospeedr(GPIOA, OSPEEDR_VERY_HIGH_SPEED, USART_PIN_0);
    set_ospeedr(GPIOA, OSPEEDR_VERY_HIGH_SPEED, USART_PIN_1);
    USART->CR1 = 0x00;
    USART->CR1 &= ~MASK(M_BIT);
    USART->BRR = 0x8A;
    USART->CR1 |= MASK(UE_BIT);
    USART->CR1 |= MASK(TX_BIT); 
    USART->CR1 |= MASK(RX_BIT);
    return;
}

void send_char(unsigned char c) {
    while(!(USART->SR & MASK(TC_BIT)));
    USART->DR = c;
    return;
}

void send_string(unsigned char *s) {
    while (*s)
        send_char((*s++));
    return;
}

unsigned char get_char() {
    while(!(USART->SR & MASK(RXNE_BIT)));
    return (unsigned char)USART->DR;
}

int poll_rx() {
    if ((USART->SR & MASK(RXNE_BIT)))
        return HIGH;
    return LOW;
}

char read_usart() {
    return (char)USART->DR;
}

// Taken from github

void swap(char *a, char *b) {    
    if(!a || !b)
        return;

    char temp = *(a);
    *(a) = *(b);
    *(b) = temp;
}

void reverse(char *str, int length) { 
	int start = 0; 
	int end = length -1; 
	while (start < end) { 
		swap((str+start), (str+end)); 
		start++; 
		end--; 
	} 
} 

char *itoa(int num, char *str, int base) { 
	int i = 0; 
	int isNegative = LOW; 

	if (num == 0) { 
		str[i++] = '0'; 
		str[i] = '\0'; 
		return str; 
	}

	if (num < 0 && base == 10) { 
		isNegative = HIGH;
		num = -num; 
	} 

	while (num != 0) { 
		int rem = num % base; 
		str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
		num = num/base; 
	}

	if (isNegative == HIGH) 
		str[i++] = '-'; 

	str[i] = '\0';
	reverse(str, i); 
	return str;
}