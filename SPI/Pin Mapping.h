#ifndef SPI_H_
#define SPI_H_

#define Spibaseaddres 0x4C

typedef struct 
{
  volatile uint8_t Spi_control_Register;
  volatile uint8_t Spi_Status_Register;
  volatile uint8_t Spi_data_regsister;

}Spi_config;

#define  SPI_ ((volatile Spi_config *)Spibaseaddres)
#endif
