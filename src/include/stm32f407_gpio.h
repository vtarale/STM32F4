/*
Author: Vihaan Tarale
*/

#ifndef COOLSTUFF1
#define COOLSTUFF1

#define __vui volatile unsigned int

#define HIGH 1
#define LOW 0

#define ON 1
#define OFF 0

#define GET_FUNC_ADDY(x) (unsigned int)&x

#define GPIOA_ADDY 0x40020000U
#define GPIOB_ADDY 0x40020400U
#define GPIOC_ADDY 0x40020800U
#define GPIOD_ADDY 0x40020C00U
#define GPIOE_ADDY 0x40021000U
#define GPIOF_ADDY 0x40021400U
#define GPIOG_ADDY 0x40021800U
#define GPIOH_ADDY 0x40021C00U
#define GPIOI_ADDY 0x40022000U
#define GPIOJ_ADDY 0x40022400U
#define GPIOK_ADDY 0x40022800U

#define RCC_ADDY 0x40023800U

#define GPIOA_VAL 0
#define GPIOB_VAL 1
#define GPIOC_VAL 2
#define GPIOD_VAL 3
#define GPIOE_VAL 4
#define GPIOF_VAL 5
#define GPIOG_VAL 6
#define GPIOH_VAL 7
#define GPIOI_VAL 8
#define GPIOJ_VAL 9
#define GPIOK_VAL 10

struct rcc {
	__vui CR;
	__vui PLLCFGR;
	__vui CFGR;
	__vui CIR;
	__vui AHB1RSTR;
	__vui AHB2RSTR;
	__vui AHB3RSTR;
	__vui RESERVED_1;
	__vui APB1RSTR;
	__vui APB2RSTR;
	__vui RESERVED_2[2];
	__vui AHB1ENR;
	__vui AHB2ENR;
	__vui AHB3ENR;
	__vui RESERVED_3;
	__vui APB1ENR;
	__vui APB2ENR;
	__vui RESERVED_4[2];
	__vui AHB1LPENR;
	__vui AHB2LPENR;
	__vui AHB3LPENR;
	__vui RESERVED_5;
	__vui APB1LPENR;
	__vui APB2LPENR;
	__vui RESERVED_6[2];
	__vui BDCR;
	__vui CSR;
	__vui RESERVED_7[2];
	__vui SSCGR;
	__vui PLLI2SCFGR ;
};

struct gpio {
	__vui MODER;	
	__vui OTYPER;	
	__vui OSPEEDR;	
	__vui PUPDR;	
	__vui IDR;	
	__vui ODR;	
	__vui BSRR;	
	__vui LCKR;	
	__vui AFR_1;
	__vui AFR_2;
};

typedef struct rcc RCC_struct;
typedef struct gpio GPIO;

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
#define PIN_8 8
#define PIN_9 9
#define PIN_10 10
#define PIN_11 11
#define PIN_12 12
#define PIN_13 13
#define PIN_14 14
#define PIN_15 15

#define GPIOA ((GPIO *)GPIOA_ADDY)
#define GPIOB ((GPIO *)GPIOB_ADDY)
#define GPIOC ((GPIO *)GPIOC_ADDY)
#define GPIOD ((GPIO *)GPIOD_ADDY)
#define GPIOE ((GPIO *)GPIOE_ADDY)
#define GPIOF ((GPIO *)GPIOF_ADDY)
#define GPIOG ((GPIO *)GPIOG_ADDY)
#define GPIOH ((GPIO *)GPIOH_ADDY)
#define GPIOI ((GPIO *)GPIOI_ADDY)
#define GPIOJ ((GPIO *)GPIOJ_ADDY)
#define GPIOK ((GPIO *)GPIOK_ADDY)

#define RCC ((RCC_struct *)RCC_ADDY)

#define MASK(x) (1UL << x)

#define ENABLE_CLOCK_GPIO(x) (RCC->AHB1ENR |= (MASK(x)))
#define DISABLE_CLOCK_GPIO(x) (RCC->AHB1ENR &= ~MASK(x))

/*
	MODERy[1:0]:Port x configuration bits(y=0..15)
	These bits are written by software to configure the I/O direction mode.
	00: Input (reset state)
	01: General purpose output mode
	10: Alternate function mode
	11: Analog mode
*/

#define MODER_INPUT 0
#define MODER_OUTPUT 1
#define MODER_AF 2
#define MODER_ANALOG 3

/*
	OTy:Port x configuration bits(y=0..15)
	These bits are written by software to configure the output type of the I/O port.
	0: Output push-pull (reset state)
	1: Output open-drain
*/

#define OTYPER_PUSH_PULL 0
#define OTYPER_OPEN_DRAIN 1

/*
	OSPEEDRy[1:0]:Port x configuration bits(y=0..15)
	These bits are written by software to configure the I/O output speed.
	00: Low speed
	01: Medium speed
	10: High speed
	11: Very high speed
*/

#define OSPEEDR_LOW_SPEED 0
#define OSPEEDR_MEDIUM_SPEED 1
#define OSPEEDR_HIGH_SPEED 2
#define OSPEEDR_VERY_HIGH_SPEED 3

/*
	PUPDRy[1:0]:Port x configuration bits(y=0..15)
	These bits are written by software to configure the I/O pull-up or pull-down
	00: No pull-up, pull-down 
	01: Pull-up
	10: Pull-down
	11: Reserved
*/

#define PUPDR_NO_PULL_UP_DOWN 0
#define PUPDR_PULL_UP 1
#define PUPDR_PULL_DOWN 2

/*
	BRy:Port x reset bit y(y=0..15)
	These bits are write-only and can be accessed in word, half-word or byte mode. A read to these bits returns the value 0x0000.
	0: No action on the corresponding ODRx bit
	1: Resets the corresponding ODRx bit
*/

#define BR_NO_ACTION 0
#define BR_RESET 1

/*
	BSy:Port x set bit y(y=0..15)
	These bits are write-only and can be accessed in word, half-word or byte mode. A read to these bits returns the value 0x0000.
	0: No action on the corresponding ODRx bit
	1: Sets the corresponding ODRx bit
*/

#define BS_NO_ACTION 0
#define BS_SET 1

/*
	for AFRL and AFRH: 
	0000: AF0
	0001: AF1
	0010: AF2
	0011: AF3 
	0100: AF4 
	0101: AF5 
	0110: AF6 
	0111: AF7
	1000: AF8 
	1001: AF9 
	1010: AF10 
	1011: AF11 
	1100: AF12 
	1101: AF13 
	1110: AF14 
	1111: AF15
*/

#define AF_0 0
#define AF_1 1
#define AF_2 2
#define AF_3 3
#define AF_4 4
#define AF_5 5
#define AF_6 6
#define AF_7 7
#define AF_8 8
#define AF_9 9
#define AF_10 10
#define AF_11 11
#define AF_12 12
#define AF_13 13
#define AF_14 14
#define AF_15 15

void reset_handler(void);
void enable_all_clock();
void disable_all_clock();
void set_moder(GPIO *x, int state, int pin);
void set_otyper(GPIO *x, int state, int pin);
void set_ospeedr(GPIO *x, int state, int pin);
void set_pupdr(GPIO *x, int state, int pin);
void set_bsrr(GPIO *x, int state, int pin);
void digital_write(GPIO *x, int state, int pin);
int digital_read(GPIO *x, int pin);
void set_af(GPIO *x, int function, int pin);
void delay(int time);

#endif