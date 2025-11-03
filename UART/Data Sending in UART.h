//Formula = (Fosc/16*requirebaud)-1
#include"Common.h"
uint32_t UartDat;
uint32_t BaudrateSet(const uint32_t baud)
{

   uint16_t temp;
   temp = ((Systemclk)/(baudratePrescale*baud))-1;   //103 UbrrH = 0000 0000  ubbrl = 0110 0111  0000 0000 0110 0111
   USART->UBBrAn[0] = (uint8_t)temp;
   USART->UBBrAn[1] = (uint8_t)(temp>>8);
   return temp;
}


void UartInitialize()
{
   USART->UArtCSB = 0x18; // Enable TX and RX (TXEN=1, RXEN=1)
   USART->UArtCSC = 0x06;// 8-bit data, 1 stop bit, no parity
   
}

void Uart_Send(unsigned char UartDat)
{
  while (!(USART->UArtCSA & 0x20));// Wait until UDRE (data register empty)
  USART->UDn = UartDat;// Load data into transmit register
  //Serial.println(USART->UDn); check this this will work cause usign the Uart_Send('A');
}


int main()
{
 Serial.begin(9600);
 UartInitialize();
 BaudrateSet(9600);
 Uart_Send('A');

}
