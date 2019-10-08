#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

#include "adc.h"
#include "gpio.h"
#include "serial.h"
#include "timer.h"

ISR(TIMER0_COMPA_vect)
{
    adc_start_conversion();
}

ISR(ADC_vect)
{
    g_adc_reading[g_adc_input++] = ADCH;
}

void main (void)
{
    adc_init();
    gpio_init();
    timer0_init();
    uart_init();
    sei();

    for (;;)
    {
        led_blink();
        printf("X: %03d\tY: %03d\tZ: %03d\r", g_adc_reading[0], g_adc_reading[1], g_adc_reading[2]);
        _delay_ms(100);
    }
}

