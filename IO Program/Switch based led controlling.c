//lED IS CONNECTED TO D5(ARDUINO UNO) AND SWITCH IS CONNECTED TO D12
#include "Ioports.h"
int main()
{
    // Configure PD5 (D5) as output and turn off initially
    GPIOD->Direction |= 0x20;   // Set 6th bit  (PD5) as output
    GPIOD->Bitset &= ~0x20;     // Clear 6th bit  (turn off LED)

    // Configure PB4 (D12) as input
    GPIOB->Direction &= ~0x10;  // Clear 5th bit (PB4)

    while(1)
    {
        // Read switch state on PB4
        if(GPIOB->Bitset & 0x10)  // Check 5th bit (PB4)
        {
            GPIOD->Bitset |= 0x20;   // Set 6th bit (PD5) - turn on LED
        }
        else
        {
            GPIOD->Bitset &= ~0x20;  // Clear 6th bit (PD5) - turn off LED
        }
    }
}
