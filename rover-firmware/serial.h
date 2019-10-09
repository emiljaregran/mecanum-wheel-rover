#ifndef SERIAL_H_
#define SERIAL_H_

#define BUFFER_SIZE     100
#define BAUDRATE        38400
#define UBRR            (F_CPU / 16 / BAUDRATE - 1)

typedef struct
{
    int8_t x;
    int8_t y;
    int8_t z;
} joystick_t;

void uart_init(joystick_t * const joystick);
void uart_read_bytes(uint8_t * p_joystick, size_t data_length);

int uart_putchar(char chr, FILE * stream);

#endif // SERIAL_H

