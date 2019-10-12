#include <avr/io.h>

#include "stepper.h"

stepper_speed_t stepper_speed = {
    .stepper_1_fast = STEPPER_STOP,
    .stepper_1_slow = STEPPER_STOP,
    .stepper_2_fast = STEPPER_STOP,
    .stepper_2_slow = STEPPER_STOP,
    .stepper_3_fast = STEPPER_STOP,
    .stepper_3_slow = STEPPER_STOP,
    .stepper_4_fast = STEPPER_STOP,
    .stepper_4_slow = STEPPER_STOP
};

void steppers_init(void)
{
    DDRB |= ((1 << DDB3) | (1 << DDB0));
    DDRC |= ((1 << DDC3) | (1 << DDC2) | (1 << DDC1) | (1 << DDC0));
    DDRD |= ((1 << DDD7) | (1 << DDD6) | (1 << DDD5) | (1 << DDD4) | (1 << DDD3) | (1 << DDD2));

    PORTB |= (1 << STEPPER_4_EN);
    PORTD |= ((1 << STEPPER_1_EN) | (1 << STEPPER_2_EN) | (1 << STEPPER_3_EN));
}

void stepper_set_direction(const uint8_t stepper, const uint8_t direction)
{
    if (STEPPER_FORWARD == direction)
    {
        PORTC &= ~(1 << stepper);
    }
    else
    {
        PORTC |= (1 << stepper);
    }
}

void stepper_stop_all(void)
{
    stepper_speed.stepper_1_fast = STEPPER_STOP;
    stepper_speed.stepper_1_slow = STEPPER_STOP;
    stepper_speed.stepper_2_fast = STEPPER_STOP;
    stepper_speed.stepper_2_slow = STEPPER_STOP;
    stepper_speed.stepper_3_fast = STEPPER_STOP;
    stepper_speed.stepper_3_slow = STEPPER_STOP;
    stepper_speed.stepper_4_fast = STEPPER_STOP;
    stepper_speed.stepper_4_slow = STEPPER_STOP;
}

