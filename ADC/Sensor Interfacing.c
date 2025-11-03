#include "Common.h"

uint32_t final_data = 0;
void ADC_configuration()
{
  ADC_->ADC_multiplexer = 0x40;//0100 0000 AVCC with external capacitor at AREF pin (control input voltage)
  ADC_->ADCcltr_statusReg_A = 0xAE;//1010 1110  ADC Enable,ADATE, ADIE,prescal it to 64
  ADC_->ADCcltrl_statusReg_B = 0x00;//Free running mode
  ADC_->digital_pin_disable_A = 0x01;//pin disable
}

int main()
{
  ADC_configuration();
  Serial.begin(9600);
 while(1)
   {
    ADC_->ADCcltr_statusReg_A | = 0x40;//start the conversion
    while((ADC_->ADCcltr_statusReg_A) & (0x10))== 0);//ADIF monitoring
    ADC_->ADCcltr_statusReg_A |=0x10;//ADIF clearing
  // ADC_->ADCcltr_statusReg_A &=~(0x40);
    final_data = (((uint8_t)ADC_->ADCdataregister[0]) | ((uint16_t)ADC_->ADCdataregister[1] << 8));
   Serial.println(final_data);
   }
}
