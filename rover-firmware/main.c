#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "gpio.h"
#include "serial.h"
#include "stepper.h"
#include "timer.h"

int main(void)
{
    joystick_data_t joystick_data;

    gpio_init();
    stepper_init();
    timer0_init();
    uart_init(&joystick_data);
    sei();

    for (;;)
    {
        uart_read_bytes((uint8_t *) &joystick_data, sizeof(joystick_data_t));

        if (0 == joystick_data.x_position)
        {
            stepper_x_move = 0;
        }
        else if (joystick_data.x_position > 0)
        {
            PORTC &= ~(1 << STEPPER_1_DIR);
            stepper_x_move = 1;
            uint8_t speed = 255 - (((uint8_t) joystick_data.x_position) * 2);

            if (speed > 60)
            {
                OCR0A = speed;
            }
            else
            {
                OCR0A = 60;
            }

            led_on();
        }
        else if (joystick_data.y_position > 40)
        {
            led_on();
        }
        else if (joystick_data.z_position > 40)
        {
            led_on();
        }
        else if (joystick_data.x_position < 0)
        {
            PORTC |= (1 << STEPPER_1_DIR);
            stepper_x_move = 1;
            uint8_t speed = 255 - ((uint8_t) (joystick_data.x_position * -2));

            if (speed > 60)
            {
                OCR0A = speed;
            }
            else
            {
                OCR0A = 60;
            }

            led_off();
        }
        else if (joystick_data.y_position < -40)
        {
            led_off();
            PORTD &= ~(1 << STEPPER_1_EN);
        }
        else if (joystick_data.z_position < -40)
        {
            led_off();
        }

        _delay_ms(5);
    }

    return 0;
}

