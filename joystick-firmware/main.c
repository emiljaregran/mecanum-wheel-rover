#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#include "adc.h"
#include "gpio.h"
#include "serial.h"
#include "timer.h"
#include "joystick.h"

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

    _delay_ms(500);
    joystick_set_center();

    for (;;)
    {
        led_blink();
        printf("X: %04d\tY: %04d\tZ: %04d\r", joystick_get_x(), joystick_get_y(), joystick_get_z());
        _delay_ms(100);
    }
}

