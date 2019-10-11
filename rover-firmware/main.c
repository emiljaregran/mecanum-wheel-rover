#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gpio.h"
#include "rover.h"
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
            rover_move_north(255 - (uint8_t) joystick.y);
        }

        // Move south.
        else if ((0 == joystick.x) && (joystick.y < 0) && (0 == joystick.z))
        {
            rover_move_south(255 - (uint8_t) abs(joystick.y));
        }

        // Move east.
        else if ((joystick.x > 0) && (0 == joystick.y) && (0 == joystick.z))
        {
            rover_move_east(255 - (uint8_t) joystick.x);
        }

        // Move west.
        else if ((joystick.x < 0) && (0 == joystick.y) && (0 == joystick.z))
        {
            rover_move_west(255 - (uint8_t) abs(joystick.x));
        }

        // Move north west.
        else if ((joystick.x < 0) && (joystick.y > 0) && (0 == joystick.z))
        {
            double x = (double) abs(joystick.x);
            double y = (double) joystick.y;
            uint8_t speed = (uint8_t) ((double) 255 - hypot(x, y));

            rover_move_north_west(speed);
        }

        // Move north east.
        else if ((joystick.x > 0) && (joystick.y > 0) && (0 == joystick.z))
        {
            double x = (double) joystick.x;
            double y = (double) joystick.y;
            uint8_t speed = (uint8_t) ((double) 255 - hypot(x, y));

            rover_move_north_east(speed);
        }

        // Move south west.
        else if ((joystick.x < 0) && (joystick.y < 0) && (0 == joystick.z))
        {
            double x = (double) abs(joystick.x);
            double y = (double) abs(joystick.y);
            uint8_t speed = (uint8_t) ((double) 255 - hypot(x, y));

            rover_move_south_west(speed);
        }

        // Move south east.
        else if ((joystick.x > 0) && (joystick.y < 0) && (0 == joystick.z))
        {
            double x = (double) joystick.x;
            double y = (double) abs(joystick.y);
            uint8_t speed = (uint8_t) ((double) 255 - hypot(x, y));

            rover_move_south_east(speed);
        }

        // Rotate clockwise.
        else if ((0 == joystick.x) && (0 == joystick.y) && (joystick.z > 30))
        {
            rover_rotate_cw(255 - (uint8_t) joystick.z);
        }

        // Rotate counterclockwise.
        else if ((0 == joystick.x) && (0 == joystick.y) && (joystick.z < -20))
        {
            rover_rotate_ccw(255 - (uint8_t) abs(joystick.z));
        }

        // Move forward and turn right.


        // Move forward and turn left.


        // Move backward and turn right.


        // Move backward and turn left.


        // Stand still.
        else
        {
            stepper_stop_all();
        }

        _delay_ms(12);
    }

    return 0;
}

