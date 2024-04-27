#ifndef COOLSTUFF
#define COOLSTUFF

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

#define __vui volatile unsigned int

typedef struct {
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
}RCC;

typedef struct {
	__vui MODER;	
	__vui OTYPER;	
	__vui OSPEEDR;	
	__vui PUPDR;	
	__vui IDR;	
	__vui ODR;	
	__vui BSRR;	
	__vui LCKR;	
	__vui AFR[2];
}GPIO;

#endif