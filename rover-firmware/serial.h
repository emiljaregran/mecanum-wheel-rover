#ifndef SERIAL_H_
#define SERIAL_H_

#define BUFFER_SIZE     100
#define BAUDRATE        38400
#define UBRR            (F_CPU / 16 / BAUDRATE - 1)

typedef struct
{
    int8_t joystick_x;
    int8_t joystick_y;
    int8_t joystick_z;
} data_packet_t;

void uart_init(data_packet_t * const data_packet);
void uart_read_bytes(uint8_t * p_data_packet, size_t length);

int uart_putchar(char chr, FILE * stream);

#endif // SERIAL_H

