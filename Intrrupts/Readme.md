**Intrrupts**
Interrupts are hardware-triggered events that temporarily pause the main program flow to execute a specific function called an Interrupt Service Routine (ISR).  
This allows the microcontroller to respond immediately to time-critical events like timer overflows, external signals, or communication events.  
**Interrupt Service Routines (ISRs)**  
An ISR is a special function that runs automatically when a specific interrupt occurs. It is defined using the ISR() macro in AVR C.  
Key Properties:  
1.No return value  
2.No parameters  
3.Should be short and fast  
4.Automatically triggered by hardware  
**Note**  
To use interrupts in ATmega328P we should enable global intrrupts(sei()) and and for clear in the global intrrupt we should use cli() syntax
