#ifndef ADC_H_
#define ADC_H_

#define ADC_Baseaddress 0x78

typedef struct 
{
  volatile uint8_t ADCdataregister[2];
  volatile uint8_t ADCcltr_statusReg_A;
  volatile uint8_t ADCcltrl_statusReg_B; 
  volatile uint8_t ADC_multiplexer;
  volatile uint8_t ADC_Reserved;
  volatile uint8_t digital_pin_disable_A;
  volatile uint8_t digital_pin_disable_B;
}AnalogtoDigital;

#define ADC_ ((volatile AnalogtoDigital*)ADC_Baseaddress)
#endif



