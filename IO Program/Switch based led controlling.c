
// LED is connected to Digital Pin 5 of the Arduino Uno, and the switch is connected to Digital Pin 12 of the Arduino Uno. Based on the switch position, the LED will
// be turned on and off.
#include "Ioports.h"//It is the pin mapping library which is specified in the Ports pin Mapping.h file
int main()
{
    // Configure PD5(D5) (LED) as output and turn off initially
    GPIOD->Direction | = 0x20;   // Set bit 6 (D5) as output: 0b0010 0000
    GPIOD->Bitset & = 0xDF;      // Clear bit 6 (D5): 0b1101 1111
    
    // Configure PB4(D12) (switch) as input
    GPIOD->Direction &= 0xEF;   // Clear bit 5 (D12): 0b1110 1111

    while(1)
    {
        // Read switch state on D12
        if(GPIOD->Bitset & 0x10)  // Check bit 5 (D12): 0b0001 0000
        {
            GPIOD->Bitset |= 0x20;   // Set bit 6 (D12): 0b0010 0000
        }
        else
        {
            GPIOD->Bitset &= 0xDF;   // Clear bit 6 (D12): 0b1101 1111
        }
    }
}
