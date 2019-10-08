#include <avr/io.h>

#include "timer.h"

void timer0_init(void)
{
    // Timer0 CTC mode.
    TCCR0A |= (1 << WGM01);

    // Timer0 TOP for ~10 msec between interrupts.
    OCR0A = (uint8_t) 157;

    // Enable interrupt for Timer0 Output Compare Match A.
    TIMSK0 |= ((1 << OCIE0A) | (1 << TOIE0));

    // Start Timer0 with F_CPU / 1024 as clock source.
    TCCR0B |= ((1 << CS02) | (1 << CS00));
}

