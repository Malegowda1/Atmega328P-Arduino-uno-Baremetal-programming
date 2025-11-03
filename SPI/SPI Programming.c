#include "Common.h"
void spi_inti()//Intialisation
{
  SPI_->Spi_control_Register = 0x51;//0101 0001 SPI Enable,Data order(MSB or LSB First),Master or slave select,clock polarity,clock phase,SPI Clock rate select,Prescale(16)
  SPI_->Spi_Status_Register = 0x00;
  SPI_->Spi_data_regsister = 0x00;
}

void configuration()
{
 GPIOB->Direction=0x2C;//00101100
}

void spi_send_dta()
{
  SPI_->Spi_control_Register = 0xAB;//1010 1011
   while(!((SPI_->Spi_Status_Register) & (0x80)));
   SPI_->Spi_Status_Register = 0x80;
}
int main()
{
  Serial.begin(9600);
  spi_inti();
  configuration();
  while(1)
  {
    
    Serial.println(SPI_->Spi_Status_Register);
    // spi_send_dta();
  }
  
}
