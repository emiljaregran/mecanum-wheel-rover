#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#include "gpio.h"
#include "rover.h"
#include "stepper.h"
#include "timer.h"
#include "uart.h"

int main(void)
{
    joystick_t joystick;

    gpio_init();
    steppers_init();
    timers_init();
    uart_init(&joystick);
    sei();

    for (;;)
    {
        uart_read_struct((uint8_t *) &joystick, sizeof(joystick_t));

        if (timer_update_movement)
        {
            timer_stop_movement--;
            timer_update_movement = 0;

            if (0 == timer_stop_movement)
            {
                timer_stop_movement = 1;
                rover_stop();
            }
            else
            {
                rover_movement(&joystick);
            }
        }
    }

    return 0;
}

