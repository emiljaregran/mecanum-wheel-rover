#ifndef JOYSTICK_H
#define JOYSTICK_H

#define JOYSTICK_DEADBAND_X     5
#define JOYSTICK_DEADBAND_Y     5
#define JOYSTICK_DEADBAND_Z     2

void joystick_set_center(void);

int8_t joystick_get_x(void);
int8_t joystick_get_y(void);
int8_t joystick_get_z(void);

#endif // JOYSTICK_H

