#include <avr/io.h>

#include "timer.h"

void timer0_init(void)
{
    // Timer0 CTC mode.
    TCCR0A |= (1 << WGM01);

    // Timer0 TOP for ~10 msec between interrupts.
    OCR0A = (uint8_t) 157;

    // Enable interrupt for Timer0 Output Compare Match A.
    TIMSK0 |= (1 << OCIE0A);

    // Start Timer0 with F_CPU / 1024 as clock source.
    TCCR0B |= ((1 << CS02) | (1 << CS00));
}

void timer1_init(void)
{
    // Timer1 CTC mode.
    TCCR1B |= (1 << WGM12);

    // Timer1 TOP for 10 msec between interrupts.
    OCR1A = 6250;

    // Enable interrupt for Timer1 Output Compare Match A.
    TIMSK1 |= (1 << OCIE1A);

    // Start Timer1 with F_CPU / 256 as clock source.
    TCCR1B |= (1 << CS12);
}

