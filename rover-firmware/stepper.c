#include <avr/io.h>
#include <util/delay.h>

#include "stepper.h"

uint8_t stepper_1_motion = STEPPER_STOP;
uint8_t stepper_2_motion = STEPPER_STOP;
uint8_t stepper_3_motion = STEPPER_STOP;
uint8_t stepper_4_motion = STEPPER_STOP;

void stepper_init(void)
{
    DDRB |= ((1 << DDB3) | (1 << DDB0));
    DDRC |= ((1 << DDC3) | (1 << DDC2) | (1 << DDC1) | (1 << DDC0));
    DDRD |= ((1 << DDD7) | (1 << DDD6) | (1 << DDD5) | (1 << DDD4) | (1 << DDD3) | (1 << DDD2));

    PORTD |= ((1 << STEPPER_1_EN) | (1 << STEPPER_2_EN) | (1 << STEPPER_3_EN) | (1 << STEPPER_4_EN));
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

void step_sideway_east(const uint8_t speed)
{
    stepper_set_direction(STEPPER_1_DIR, STEPPER_FORWARD);
    stepper_set_direction(STEPPER_2_DIR, STEPPER_BACKWARD);
    stepper_set_direction(STEPPER_3_DIR, STEPPER_BACKWARD);
    stepper_set_direction(STEPPER_4_DIR, STEPPER_FORWARD);

    if (speed > 60)
    {
        OCR0A = speed;
    }
    else
    {
        OCR0A = 60;
    }

    stepper_1_motion = STEPPER_MOVE;
    stepper_2_motion = STEPPER_MOVE;
    stepper_3_motion = STEPPER_MOVE;
    stepper_4_motion = STEPPER_MOVE;
}

void step_sideway_west(const uint8_t speed)
{
    stepper_set_direction(STEPPER_1_DIR, STEPPER_BACKWARD);
    stepper_set_direction(STEPPER_2_DIR, STEPPER_FORWARD);
    stepper_set_direction(STEPPER_3_DIR, STEPPER_FORWARD);
    stepper_set_direction(STEPPER_4_DIR, STEPPER_BACKWARD);

    if (speed > 60)
    {
        OCR0A = speed;
    }
    else
    {
        OCR0A = 60;
    }

    stepper_1_motion = STEPPER_MOVE;
    stepper_2_motion = STEPPER_MOVE;
    stepper_3_motion = STEPPER_MOVE;
    stepper_4_motion = STEPPER_MOVE;
}

void step_stop(void)
{
    stepper_1_motion = STEPPER_STOP;
    stepper_2_motion = STEPPER_STOP;
    stepper_3_motion = STEPPER_STOP;
    stepper_4_motion = STEPPER_STOP;
}

