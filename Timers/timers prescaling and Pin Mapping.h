//Timer prescaling
#ifndef SYSTEMCLOCK
#define SYSTEMCLOCK  16000000
#define baud_prescal 16
#endif

//Timer Pin Mapping
#ifndef My_TIMER_h
#define My_TIMER_h

#define TimerBase_0 0x44
#define TimerBase_1 0x80
#define TimerBase_2 0xB0
#define Timerinterupt_0 0x35
#define timermask_0 0x6E
#define Timerinterupt_2 0x37
#define timermask_2 0x70
#define Timerinterupt_1 0x36
#define timermask_1 0x6F

typedef struct
{

 volatile uint8_t TimercontrolregA;
 volatile uint8_t TimercontrolregB;
 volatile uint8_t Timerconter;
 volatile uint8_t OutputcompareA;
 volatile uint8_t OutputcompareB;
}Timer_a;

typedef struct 
{
  volatile uint8_t timercounterrega_1;
  volatile uint8_t timercounterregb_1;
  volatile uint8_t timercounterregc_1;
  volatile uint8_t reserved_1;
  volatile uint8_t timercounter_1[2];
  volatile uint8_t timer_capture[2];
  volatile uint8_t timer_compareA_1[2];
  volatile uint8_t timer_compareB_1[2];  
}Timer_b;

typedef struct 
{
 volatile uint8_t timercounterorcontrolrega;
 volatile uint8_t timercounterorcontrolregb;
 volatile uint8_t timercounter_2;
 volatile uint8_t OutputcomparA_2;
 volatile uint8_t OutputcompareB_2;

}Timer_c;


#define Timer0_ ((volatile Timer_a *)TimerBase_0)
#define Timer1_ ((volatile Timer_b *)TimerBase_1)
#define Timer2_ ((volatile Timer_c *)TimerBase_2)
#define Timerintrtflag_0 (*(volatile uint8_t *)Timerinterupt_0)
#define TimerMask_0 (*(volatile uint8_t *)timermask_0)
#define Timerintrtflag_2 (*(volatile uint8_t *)Timerinterupt_2)
#define TimerMask_2 (*(volatile uint8_t *)timermask_2)
#define Timerintrtflag_1 (*(volatile uint8_t *)Timerinterupt_1)
#define TimerMask_1 (*(volatile uint8_t *)timermask_1)
#endif


