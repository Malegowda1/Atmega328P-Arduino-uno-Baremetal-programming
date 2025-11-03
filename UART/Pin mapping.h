#ifndef UART_T_H_
#define UART_T_H_
/*
1.data register
2.Control and status Register A,B and C
3.Baudrate register high and Low
*/

#define UsartCTRLST0A 0xC0
#define UsartCTRLST0B 0xC1
#define UsartCTRLST0C 0xC2
#define reserved      0xC3

typedef struct
{

 volatile uint8_t UArtCSA;
 volatile uint8_t UArtCSB;
 volatile uint8_t UArtCSC;
 volatile uint8_t Dummy;
 volatile uint8_t UBBrAn[2];
 volatile uint8_t UDn;

}USART0;

#define USART0_ ((volatile USART0 *)UsartCTRLST0A)
#endif
