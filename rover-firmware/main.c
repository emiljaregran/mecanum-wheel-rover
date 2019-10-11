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
    timer1_init();
    timer2_init();
    uart_init(&joystick);
    sei();

    for (;;)
    {
        uart_read_bytes((uint8_t *) &joystick, sizeof(joystick_t));

        if (timer_run_main)
        {
            timer_run_main = 0;

            // Move north.
            if ((0 == joystick.x) && (joystick.y > 0) && (0 == joystick.z))
            {
                rover_move_north(255 - ((uint8_t) joystick.y * 2));
            }

            // Move south.
            else if ((0 == joystick.x) && (joystick.y < 0) && (0 == joystick.z))
            {
                rover_move_south(255 - ((uint8_t) abs(joystick.y) * 2));
            }

            // Move west.
            else if ((joystick.x < 0) && (0 == joystick.y) && (0 == joystick.z))
            {
                rover_move_west(255 - ((uint8_t) abs(joystick.x) * 2));
            }

            // Move east.
            else if ((joystick.x > 0) && (0 == joystick.y) && (0 == joystick.z))
            {
                rover_move_east(255 - ((uint8_t) joystick.x * 2));
            }

            // Move north west.
            else if ((joystick.x < 0) && (joystick.y > 0) && (0 == joystick.z))
            {
                double x = (double) abs(joystick.x);
                double y = (double) joystick.y;
                uint8_t target_speed = (uint8_t) ((double) 255 - hypot(x, y));

                rover_move_north_west(target_speed);
            }

            // Move north east.
            else if ((joystick.x > 0) && (joystick.y > 0) && (0 == joystick.z))
            {
                double x = (double) joystick.x;
                double y = (double) joystick.y;
                uint8_t target_speed = (uint8_t) ((double) 255 - hypot(x, y));

                rover_move_north_east(target_speed);
            }

            // Move south west.
            else if ((joystick.x < 0) && (joystick.y < 0) && (0 == joystick.z))
            {
                double x = (double) abs(joystick.x);
                double y = (double) abs(joystick.y);
                uint8_t target_speed = (uint8_t) ((double) 255 - hypot(x, y));

                rover_move_south_west(target_speed);
            }

            // Move south east.
            else if ((joystick.x > 0) && (joystick.y < 0) && (0 == joystick.z))
            {
                double x = (double) joystick.x;
                double y = (double) abs(joystick.y);
                uint8_t target_speed = (uint8_t) ((double) 255 - hypot(x, y));

                rover_move_south_east(target_speed);
            }

            // Rotate clockwise.
            else if ((0 == joystick.x) && (0 == joystick.y) && (joystick.z > 30))
            {
                rover_rotate_cw(255 - ((uint8_t) joystick.z * 2));
            }

            // Rotate counterclockwise.
            else if ((0 == joystick.x) && (0 == joystick.y) && (joystick.z < -20))
            {
                rover_rotate_ccw(255 - ((uint8_t) abs(joystick.z) * 3));
            }

            // Move forward and turn right.
            else if ((0 == joystick.x) && (joystick.y > 0) && (joystick.z > 30))
            {
                uint8_t fast_speed = 255 - ((uint8_t) joystick.y * 2);
                uint8_t slow_speed = 255 - ((uint8_t) joystick.z * 2);

                rover_move_north_turn_cw(fast_speed, slow_speed);
            }

            // Move forward and turn left.


            // Move backward and turn right.


            // Move backward and turn left.


            // Stand still.
            else
            {
                rover_stop();
            }
        }
    }

    return 0;
}

