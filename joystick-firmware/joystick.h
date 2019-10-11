#ifndef JOYSTICK_H
#define JOYSTICK_H

#define JOYSTICK_AXIS_X         0
#define JOYSTICK_AXIS_Y         1
#define JOYSTICK_AXIS_Z         2
#define JOYSTICK_AXIS_COUNT     3
#define JOYSTICK_DEADBAND       10

typedef struct
{
    int8_t x_position;
    int8_t y_position;
    int8_t z_position;
} joystick_data_t;

void joystick_set_center(void);

joystick_data_t joystick_get_data(void);

#endif // JOYSTICK_H

