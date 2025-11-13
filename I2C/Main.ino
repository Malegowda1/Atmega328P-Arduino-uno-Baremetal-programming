#include"Common.h"
#include <avr/interrupt.h>
int main()
{
TWI_Clock();
DDRB = 0x04;
DDRB |= (1<<5);
char data;
sei();                                                       // Global interrupt are enabled 
Serial.begin(9600); 
while(1)
{
   
  TwI_SendSlave_address(1,0x4F); //0 for writing and (1,4F) reading   
  data = TwI_SendSlave_data();
  // TwI_SendSlave_data(0x30);//For sending the data
  // TwI_SendSlave_data(0x60);
  TwI_SendStop();
}
