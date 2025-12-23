#include"TWI.h"
#include"Clock.h"

#define TWI_freq 400000
#define TWI_constant 16
#define TWI_prescale 1

char TWI_Clock()
{
  char Baudrate_Value = ((((Systemclk/TWI_freq*TWI_prescale)-TWI_constant)) / 2);
  TWI_config->TWI_BAudRate_register = Baudrate_Value;
  return   TWI_config->TWI_BAudRate_register;

}

TWI_Status TwIstart(void)
{
TWI_Status temp;

  TWI_config->TWI_Control_register = (1<<2)|(1<<5)|(1<<7);
  while(((TWI_config->TWI_Control_register)&0x80) == 0);

  if((TWI_config->TWI_Status_register & start) == start)
  {
    
    temp = pass;
    
  }
  else
  {
    
    temp = Fail;

  }
return temp;

}



TWI_Status TwI_SendSlave_address(char Action, char slaveaddress)
{
    TWI_Status temp;
     temp = TwIstart();

    if(temp == pass)
    {
      
      TWI_config->TWI_Data_register = slaveaddress+Action;
      TWI_config->TWI_Control_register = (1<<7)|(1<<2);
      while((TWI_config->TWI_Control_register & 0x80) == 0);
      
      if(Action == 0)
      {
      if(((TWI_config->TWI_Status_register)&(Sla_W_Ack)) == Sla_W_Ack)
      {
        temp = pass;
       PORTB |= (1<<5);//Debugging with on board led
      }
      }
      else
      {
        if(Action == 1)
        {
          if( if(((TWI_config->TWI_Status_register)&(Sla_R_Ack)) == Sla_R_Ack))
          {
             temp = pass;
          }    
        }
      }
    }
    else
    {
      temp = Fail;
      PORTB &=~ (1<<5);
    }

return temp;

}

TWI_Status TwI_SendSlave_data(char data)
{
    TWI_Status temp;
        
      TWI_config->TWI_Data_register = data;
      TWI_config->TWI_Control_register = (1<<7)|(1<<2);
      while((TWI_config->TWI_Control_register & 0x80) == 0);
      
      if(((TWI_config->TWI_Status_register)&(Data_byte_ack)) == Data_byte_ack)
      {
        temp = pass;
       PORTB |= (1<<5);
      }

    
    else
    {
      temp = Fail;
      PORTB &=~ (1<<5);
    }

return temp;

}

char TwI_SendSlave_data()
{
   char localfortwi = 0;  

   TWI_config->TWI_Control_register = (1<<7)|(1<<2);
   while((TWI_config->TWI_Control_register & 0x80) == 0);
   localfortwi = TWI_config->TWI_Data_register;
    
   retrun  localfortwi;

}

void TwI_SendStop(void)
{
    

  TWI_config->TWI_Control_register = (1<<2)|(1<<4)|(1<<7);
  while(((TWI_config->TWI_Control_register)&0x80) == 0);

}
