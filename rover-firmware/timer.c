#include <avr/interrupt.h>
#include <avr/io.h>

#include "stepper.h"
#include "timer.h"

volatile uint8_t timer_run_main = 0;

ISR(TIMER0_COMPA_vect)
{
    if (stepper_speed.stepper_1_fast)
    {
        PORTD ^= (1 << STEPPER_1_STEP);
    }

    if (stepper_speed.stepper_2_fast)
    {
        PORTD ^= (1 << STEPPER_2_STEP);
    }

    if (stepper_speed.stepper_3_fast)
    {
        PORTB ^= (1 << STEPPER_3_STEP);
    }

    if (stepper_speed.stepper_4_fast)
    {
        PORTD ^= (1 << STEPPER_4_STEP);
    }
}

ISR(TIMER1_COMPA_vect)
{
    timer_run_main = 1;
}

ISR(TIMER2_COMPA_vect)
{
    if (stepper_speed.stepper_1_slow)
    {
        PORTD ^= (1 << STEPPER_1_STEP);
    }

    if (stepper_speed.stepper_2_slow)
    {
        PORTD ^= (1 << STEPPER_2_STEP);
    }

    if (stepper_speed.stepper_3_slow)
    {
        PORTB ^= (1 << STEPPER_3_STEP);
    }

    if (stepper_speed.stepper_4_slow)
    {
        PORTD ^= (1 << STEPPER_4_STEP);
    }
}

void timer0_init(void)
{
    // Timer0 CTC mode.
    TCCR0A |= (1 << WGM01);

    // Set Timer0 TOP.
    OCR0A = (uint8_t) 255;

    // Compare Match A interrupt enable.
    TIMSK0 |= (1 << OCIE0A);

    // Start Timer0 with F_CPU / 64 as clock source.
    TCCR0B |= ((1 << CS01) | (1 << CS00));
}

void timer1_init(void)
{
    // Timer1 CTC mode.
    TCCR1B |= (1 << WGM12);

    // Set timer1 TOP to generate 100 Hz interrupts.
    OCR1A = 625;

    // Compare Match A interrupt enable.
    TIMSK1 |= (1 << OCIE1A);

    // Start Timer1 with F_CPU / 256 as clock source.
    TCCR1B |= (1 << CS12);
}

void timer2_init(void)
{
    // Timer2 CTC mode.
    TCCR2A |= (1 << WGM21);

    // Set Timer2 TOP.
    OCR2A = (uint8_t) 255;

    // Compare match A interrupt enable.
    TIMSK2 |= (1 << OCIE2A);

    // Start Timer2 with F_CPU / 64 as clock source.
    TCCR2B |= (1 << CS22);
}

