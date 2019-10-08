#include <avr/io.h>

#include "adc.h"

volatile uint8_t g_adc_reading[3] = { 0, 0, 0 };
volatile uint8_t g_adc_input = 0;

void adc_init(void)
{
    // Disable digital input buffer on ADC2, ADC1 and ADC0.
    DIDR0 |= ((1 << ADC2D) | (1 << ADC1D) | (1 << ADC0D));

    // Select AVcc as ADC Voltage Reference.
    ADMUX |= (1 << REFS0);

    // Left adjust the ADC conversion result (8 bit resolution).
    ADMUX |= (1 << ADLAR);

    // Set ADC prescaler to F_CPU / 16 for 76.9kSPS.
    ADCSRA |= (1 << ADPS2);

    // Enable ADC Conversion Complete interrupt.
    ADCSRA |= (1 << ADIE);

    // Enable the ADC.
    ADCSRA |= (1 << ADEN);
}

void adc_start_conversion(void)
{
    if (g_adc_input > 2)
    {
        g_adc_input = 0;
    }

    // Select ADC MUX.
    ADMUX = ((ADMUX & 0xF0) | g_adc_input);

    // Start the ADC conversion.
    ADCSRA |= (1 << ADSC);
}

