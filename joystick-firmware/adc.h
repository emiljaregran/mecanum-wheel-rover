#ifndef ADC_H
#define ADC_H

extern volatile uint8_t g_adc_reading[3];
extern volatile uint8_t g_adc_input;

void adc_init(void);
void adc_start_conversion(void);

#endif // ADC_H

