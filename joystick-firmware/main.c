#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#include "adc.h"
#include "gpio.h"
#include "serial.h"
#include "timer.h"
#include "joystick.h"

typedef struct
{
    int8_t joystick_x;
    int8_t joystick_y;
    int8_t joystick_z;
} data_packet_t;

volatile data_packet_t data_packet;

ISR(TIMER0_COMPA_vect)
{
    adc_start_conversion();
}

ISR(TIMER1_COMPA_vect)
{
    led_blink();
    //printf("X: %04d\tY: %04d\tZ: %04d\r", joystick_get_x(), joystick_get_y(), joystick_get_z());

    data_packet.joystick_x = joystick_get_x();
    data_packet.joystick_y = joystick_get_y();
    data_packet.joystick_z = joystick_get_z();

    uart_putstruct((uint8_t *) &data_packet, sizeof(data_packet));
}

ISR(ADC_vect)
{
    g_adc_reading[g_adc_input++] = ADCH;
}

void main (void)
{
    data_packet.joystick_x = 0;
    data_packet.joystick_y = 0;
    data_packet.joystick_z = 0;

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
}

