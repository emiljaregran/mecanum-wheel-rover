#ifndef SERIAL_H_
#define SERIAL_H_

#define BAUDRATE    38400
#define UBRR        (F_CPU / 16 / BAUDRATE - 1)

void uart_init(void);
void uart_putstruct(const uint8_t * p_start, uint8_t length);

int uart_putchar(char chr, FILE * stream);

char uart_getchar(void);

#endif // SERIAL_H

