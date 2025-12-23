//Steps configuration(Pins directions),Initialisation(Control register),sending and Receiving the data
#include "Common.h"
void spi_inti()//Intialisation
{
  SPI_->Spi_control_Register = 0x51;//0101 0001 SPI Enable,Data order(MSB or LSB First),Master or slave select,clock polarity,clock phase,SPI Clock rate select,Prescale(16)
  SPI_->Spi_Status_Register = 0x00;
  SPI_->Spi_data_regsister = 0x00;
}

void gpio_configuration()
{
 GPIOB->Direction=0x2C;// 0010 1100 MOSI (PB3), SCK (PB5), SS (PB2) as output.MISO (PB4) as input.
}

void spi_send_dta(uint8_t data)
{
  SPI_->Spi_data_regsisterr = data;//1010 1011 
  while(!((SPI_->Spi_Status_Register) & (0x80)));// wait for the complete transfering of the data
  SPI_->Spi_Status_Register = 0x80;//clearing the intrrupt flag
}
uint8_t spi_receive_dat()
{
 while(!((SPI_->Spi_Status_Register) & (0x80)));
 return  SPI_->Spi_data_regsister ;  
}
int main()
{
  Serial.begin(9600);
  spi_inti();
  gpio_configuration();
  while(1)
  {
    spi_send_dta(0xAA);
    uint8_t spi_receiced = spi_receive_dat();
    Serial.Println(spi_receiced);
  }
  
}
