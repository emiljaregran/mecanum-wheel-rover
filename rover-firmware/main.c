#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>

#include "gpio.h"
#include "serial.h"

int main(void)
{
    data_packet_t data_packet;

    gpio_init();
    uart_init(&data_packet);
    sei();

    for (;;)
    {
        uart_read_bytes((uint8_t *) &data_packet, sizeof(data_packet));

        if (data_packet.joystick_x > 40)
        {
            led_on();
        }
        else if (data_packet.joystick_y > 40)
        {
            led_on();
        }
        else if (data_packet.joystick_z > 40)
        {
            led_on();
        }
        else if (data_packet.joystick_x < -40)
        {
            led_off();
        }
        else if (data_packet.joystick_y < -40)
        {
            led_off();
        }
        else if (data_packet.joystick_z < -40)
        {
            led_off();
        }
    }

    return 0;
}

