#ifndef SERIAL_H
#define SERIAL_H

#define BUFFER_SIZE     100
#define BAUDRATE        38400
#define UBRR            (F_CPU / 16 / BAUDRATE - 1)

void uart_init(joystick_t * const joystick);
void uart_read_struct(uint8_t * p_joystick, size_t data_length);

int uart_putchar(char chr, FILE * stream);

#endif // SERIAL_H

