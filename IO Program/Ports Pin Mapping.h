#ifndef Ioports.h
#define Ioports.h

#define PINB 0x23
#define PINC 0x26
#define PIND 0x29

typedef struct 
{
  volatile uint8_t Read;
  volatile uint8_t Direction;
  volatile uint8_t Bitset;
}GPIO_B;


typedef struct 
{
  volatile uint8_t Read;
  volatile uint8_t Direction;
  volatile uint8_t Bitset;
}GPIO_C;

typedef struct 
{
  volatile uint8_t Read;
  volatile uint8_t Direction;
  volatile uint8_t Bitset;
}GPIO_D;


#define GPIOB ((GPIO_B *)PINB)
#define GPIOC ((GPIO_C *)PINC)
#define GPIOD ((GPIO_C *)PIND)
#endif
