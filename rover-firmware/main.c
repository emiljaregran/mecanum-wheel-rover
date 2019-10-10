#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gpio.h"
#include "serial.h"
#include "stepper.h"
#include "timer.h"

int main(void)
{
    joystick_t joystick;

    gpio_init();
    stepper_init();
    timer0_init();
    uart_init(&joystick);
    sei();

    for (;;)
    {
        uart_read_bytes((uint8_t *) &joystick, sizeof(joystick_t));

        // Move north.
        if ((0 == joystick.x) && (joystick.y > 0) && (0 == joystick.z))
        {
            step_move_north(255 - (uint8_t) joystick.y);
        }

        // Move south.
        else if ((0 == joystick.x) && (joystick.y < 0) && (0 == joystick.z))
        {
            step_move_south(255 - (uint8_t) abs(joystick.y));
        }

        // Move east.
        else if ((joystick.x > 0) && (0 == joystick.y) && (0 == joystick.z))
        {
            step_move_east(255 - (uint8_t) joystick.x);
        }

        // Move west.
        else if ((joystick.x < 0) && (0 == joystick.y) && (0 == joystick.z))
        {
            step_move_west(255 - (uint8_t) abs(joystick.x));
        }

        // Move north west.
        else if ((joystick.x < 0) && (joystick.y > 0) && (0 == joystick.z))
        {
            double x = (double) abs(joystick.x);
            double y = (double) joystick.y;
            uint8_t speed = (uint8_t) ((double) 255 - hypot(x, y));

            step_move_north_west(speed);
        }

        // Move north east.
        else if ((joystick.x > 0) && (joystick.y > 0) && (0 == joystick.z))
        {
            double x = (double) joystick.x;
            double y = (double) joystick.y;
            uint8_t speed = (uint8_t) ((double) 255 - hypot(x, y));

            step_move_north_east(speed);
        }

        // Move south west.
        else if ((joystick.x < 0) && (joystick.y < 0) && (0 == joystick.z))
        {
            double x = (double) abs(joystick.x);
            double y = (double) abs(joystick.y);
            uint8_t speed = (uint8_t) ((double) 255 - hypot(x, y));

            step_move_south_west(speed);
        }

        // Move south east.
        else if ((joystick.x > 0) && (joystick.y < 0) && (0 == joystick.z))
        {
            double x = (double) joystick.x;
            double y = (double) abs(joystick.y);
            uint8_t speed = (uint8_t) ((double) 255 - hypot(x, y));

            step_move_south_east(speed);
        }

        // Stand still.
        else
        {
            step_stop();
        }

        _delay_ms(12);
    }

    return 0;
}

