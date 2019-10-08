#include <avr/io.h>

#include "gpio.h"

void gpio_init(void)
{
    DDRB |= (1 << DDB1);
}

void led_blink(void)
{
    PINB |= (1 << PINB1);
}

