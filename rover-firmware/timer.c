#include <avr/interrupt.h>
#include <avr/io.h>

#include "stepper.h"
#include "timer.h"

ISR(TIMER0_COMPA_vect)
{
    if (stepper_x_move)
    {
        PIND |= (1 << PIND5);
    }
}

void timer0_init(void)
{
    // Timer0 CTC mode.
    TCCR0A |= (1 << WGM01);

    // Set OCR0A.
    OCR0A = (uint8_t) 250;

    TIMSK0 |= (1 << OCIE0A);

    // Start Timer0 with F_CPU / 8 as clock source.
    TCCR0B |= (1 << CS01);
}
