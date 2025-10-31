#include "Common.h"
#include<avr/interrupt.h>//standard avr library
volatile int count=0;
void timer_configuration()
{
  Timer1_->timercounterrega_1=0x00;//Normal mode configuration
  Timer1_->timercounterregc_1 =0x00;
  Timer1_->timercounterregb_1 = 0x05;//prescaling selection 1024
  Timer1_->timer_compareA_1 = 0x00;
  Timer1_->timer_compareB_1 = 0x00;
  TimerMask_1 = 0x01;//TOIE is enabled 
}

int main()
{
   GPIOD->Direction = 0x80;//PD7 direction set
   sei();//Enabling the global intrrupt
   timer_configuration();
   
  while(1)
{
   Timer1_->timercounter_1[0]=0xBD;//F0BD For 250milli second 
   Timer1_->timercounter_1[1]=0xF0;
  if(count<20)//for 5sec delay
  {
   GPIOB->Bitset = 0x80;
  }
  else if(count>20 && count <40)
  {
   GPIOB->Bitset = 0x00;
  }
  else 
  {
    count = 0;
  }
  }
}

ISR(TIMER1_OVF_vect)
{
 count = count + 1;
}
