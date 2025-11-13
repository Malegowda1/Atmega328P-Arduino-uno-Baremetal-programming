I2C (Inter-Integrated Circuit) is a synchronous, multi-master, multi-slave, packet-switched, single-ended, serial communication bus. It’s widely used for connecting low-speed peripherals 
to microcontrollers and its data transmitting speeds are Standard (100 kbps), Fast (400 kbps), High-speed (3.4 Mbps).  
**Registers Involved**  
1.TWBR – Bit Rate Register  
2.TWSR – Status Register  
3.TWAR – Address Register  
4.TWDR – Data Register  
5.TWCR – Control Register  
**I2C Frame**  
Start Slave+R/W Ack data Ack stop  
**steps**  
1.Set TWCR with int,en and start bit and wait for the intrrupt to be generate,check the status register with the start condition and show the error if started.  
2.Load TWDR with the slave address and clear the intrrupt along with enable wait for the intrrupt flag to set and ack and nack will be shown with check the status.  
3.Load the data to the TWDR and clear the intrrupt and enable(set) wait for the intrrupt flag to set check with acknowledgement .  
4.To stop enable intrrupt and enbale(set) and stop bit


