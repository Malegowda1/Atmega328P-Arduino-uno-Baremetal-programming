//LED IS CONNECTED TO PB5 WHICH IS DIGITAL PIN 13 IN ARDUINO UNO (ARDUINO UNO INBULT LAMP IS CONNECTED TO THIS PIN)
#include "Common.h"
void configuration()
{
  Timer0_->TimercontrolregA = 0x00;//Normal Mode selection
  Timer0_->TimercontrolregB = 0x05;//configure the timer to  64micro, Perescale 1024
  Timer0_->OutputcompareA = 0x00;
  Timer0_->OutputcompareB = 0x00;
  TimerMask_0 = 0x00;
  Timerintrtflag_0 =0x00;
}
int delay_()//timer0
{
 for(int i=0;i<1000;i++)//1 Sec delay
{
 Timer0_->Timerconter = 100;//10milli second
 while((Timerintrtflag_0 & 0x01)==0);//Wait for overflow flag to set
 Timerintrtflag_0 = 0x01;
}
 
}
int main()
{
  // Configure PB5 (D13) as output and turn off initially
    GPIOB->Direction |= 0x20;   // Set 6th bit  (PB5) as output
    GPIOB->Bitset &= ~0x20;     // Clear 6th bit  (turn off LED)
    configuration();
while(1)
{
 GPIOB->Bitset  = 0x20;
 delay_();
 GPIOB->Bitset  = 0x00;
 delay_();
}

}
