#include <avr/interrupt.h>
#include <avr/io.h>

#include <stdio.h>

#include "serial.h"

static volatile uint8_t buffer[BUFFER_SIZE];
static volatile uint8_t buffer_index = 0;
static FILE uart_stdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

ISR(USART_RX_vect)
{
    if (buffer_index > (BUFFER_SIZE - 1))
    {
        buffer_index = 0;
    }

    buffer[buffer_index++] = UDR0;
}

void uart_init(joystick_data_t * const joystick_data)
{
    joystick_data->x_position = 0;
    joystick_data->y_position = 0;
    joystick_data->z_position = 0;

    UBRR0H = (unsigned char) (UBRR >> 8);
    UBRR0L = (unsigned char) (UBRR);
    UCSR0A = 0;
    UCSR0B = ((1 << TXEN0) | (1 << RXEN0) | (1 << RXCIE0));
    UCSR0C = ((1 << UCSZ01) | (1 << UCSZ00));

    stdout = &uart_stdout;
}

void uart_read_bytes(uint8_t * p_joystick_data, size_t data_length)
{
    if (buffer_index >= data_length)
    {
        for (uint8_t byte = 0; byte < data_length; byte++)
        {
           *(p_joystick_data++) = buffer[byte];
        }

        buffer_index = 0;
    }
}

int uart_putchar(char chr, FILE * stream)
{
    if ('\n' == chr)
    {
        uart_putchar('\r', stream);
    }
    while (!(UCSR0A & (1 << UDRE0)))
    {
    }

    UDR0 = chr;
    return 0;
}

