#include <avr/io.h>
#include <util/delay.h>

#include "stepper.h"

uint8_t stepper_x_move = 0;

void stepper_init(void)
{
    DDRC |= (1 << DDC0);
    DDRD |= ((1 << DDD2) | (1 << DDD5) | (1 << DDD6));

    PORTC &= ~(1 << STEPPER_1_DIR);
    PORTD &= ~((1 << STEPPER_1_EN) | (1 << STEPPER_1_STEP));

    PORTD |= (1 << STEPPER_1_EN);
}

void stepper_step(void)
{
    //_delay_ms(2);
#if 0
    for (int i = 0; i < 200; i++)
    {
        PORTD |= (1 << STEPPER_1_STEP);
        _delay_us(50);
        PORTD &= ~(1 << STEPPER_1_STEP);
        _delay_us(50);
    }
#endif
}

