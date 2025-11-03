#include "Common.h"

uint32_t final_data = 0;
void ADC_configuration()
{
  ADC_->ADC_multiplexer = 0x40;//1100 0000
  ADC_->ADCcltr_statusReg_A = 0xAE;
  ADC_->ADCcltrl_statusReg_B = 0x00;
  ADC_->digital_pin_disable_A = 0x01;
  ADC_->ADCcltr_statusReg_A | = 0x40
}

int main()
{
  ADC_configuration();
  Serial.begin(9600);
 while(1)
   {
    //ADC_->ADCcltr_statusReg_A | = 0x40;
   while((ADC_->ADCcltr_statusReg_A) & (0x10))== 0);
   ADC_->ADCcltr_statusReg_A |=0x10;
  // ADC_->ADCcltr_statusReg_A &=~(0x40);
    final_data = (((uint8_t)ADC_->ADCdataregister[0]) | ((uint16_t)ADC_->ADCdataregister[1] << 8));
   Serial.println(final_data);
   }
}
