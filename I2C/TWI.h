
#ifndef TWI_H_
#define TWI_H_
#include <avr/io.h>
#define TWI_Base_Address 0xB8

char TWI_Clock();


typedef struct{
  
  char TWI_BAudRate_register;
  char TWI_Status_register; 
  char TWI_Address_register;               // slave mode only
  char TWI_Data_register;
  char TWI_Control_register;
  char TWI_AddressMask_register;          // slave mode only 

}I2c__;

#define TWI_config ((volatile I2c__*)TWI_Base_Address)

typedef enum{ start = 0x08, R_start = 0x10, Sla_W_Ack = 0x18, Sla_W_NotAck = 0x20, 
      Data_byte_ack = 0x28, Data_byte_Notack = 0x28,Fail = 0, pass = 1,Sla_R_Ack = 0x40,
       }TWI_Status;

TWI_Status TwIstart(void);
TWI_Status TwI_SendSlave_address(char , char );
TWI_Status TwI_SendSlave_data(char );
void TwI_SendStop(void);

#endif
