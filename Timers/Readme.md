The ATmega328P microcontroller includes three hardware timers:  
1.Timer0 – 8-bit  
2.Timer1 – 16-bit  
3.Timer2 – 8-bit  
These timers are versatile and can be used for:  
1.Generating precise time delays  
2.Creating PWM signals  
3.Measuring time intervals  
4.Triggering interrupts  
Timer Modes  1. Normal ModesThe timer counts from BOTTOM (0) to MAX.
On reaching MAX, it overflows and restarts from 0.
Overflow can trigger an interrupt.
Used for simple time delays or overflow-based timing.
2. CTC Mode (Clear Timer on Compare Match)
Timer counts from BOTTOM (0) to a user-defined TOP value in OCRxA.
When TCNTx == OCRxA, the timer resets to 0.
Useful for generating periodic interrupts or precise timing.
3. PWM Modes
PWM (Pulse Width Modulation) is used to generate variable duty cycle signals.
a. Fast PWM
Timer counts from BOTTOM to TOP and resets.
TOP can be fixed (MAX) or set via OCRxA or ICRx.
Generates high-frequency PWM signals.
b. Phase Correct PWM
Timer counts up from BOTTOM to TOP, then down to BOTTOM.
Produces symmetrical PWM waveform.
Useful for motor control applications.
