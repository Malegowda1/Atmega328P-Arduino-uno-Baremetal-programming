
UART (Universal Asynchronous Receiver/Transmitter) is a hardware communication protocol used for asynchronous serial communication between devices. It is widely used in 
embedded systems for transmitting and receiving data over a simple two-wire interface: TX (Transmit) and RX (Receive).  
**Note**   
Unlike synchronous protocols (like SPI or I²C), UART does not require a clock signal. Instead, both devices agree on a common baud rate (bits per second) to ensure proper 
timing.  
**Key Features**
1.Asynchronous Communication: No clock signal; timing is based on baud rate.
2.Full-Duplex: Data can be transmitted and received simultaneously.
3.Simple Wiring: Requires only two data lines (TX and RX) plus ground.  
**Configurable Parameters:**
1.Baud Rate (e.g., 9600, 115200)
2.Data Bits (usually 8 bits)
3.Parity (None, Even, Odd)
4.Stop Bits (1 or 2)  
**UART Working**  
**1.Data Framing:** Each data packet consists of:
1.Start Bit: Indicates the beginning of transmission.
2.Data Bits: Actual payload (typically 8 bits).
3.Optional Parity Bit: For error checking.
4.Stop Bit(s): Marks the end of the packet.  
**Transmission:**
The transmitter converts parallel data into serial form and sends it bit by bit.
The receiver reconstructs the serial data back into parallel form.

