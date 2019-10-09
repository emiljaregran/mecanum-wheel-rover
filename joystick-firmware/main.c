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

ISR(TIMER1_COMPA_vect)
{
    joystick_data_t joystick_data = joystick_get_data();
    uart_putstruct((uint8_t *) &joystick_data, sizeof(joystick_data_t));
    led_blink();
}

ISR(ADC_vect)
{
    g_adc_reading[g_adc_input++] = ADCH;
}

int main(void)
{
    adc_init();
    gpio_init();
    timer0_init();
    uart_init();
    sei();

    _delay_ms(500);
    joystick_set_center();
    timer1_init();

    for (;;)
    {
    }

    return 0;
}

