#ifndef ROVER_H
#define ROVER_H

#define ROVER_SPEED_LIMIT   8

typedef enum
{
    PREV_DIR_NORTH,
    PREV_DIR_SOUTH,
    PREV_DIR_WEST,
    PREV_DIR_EAST,
    PREV_DIR_NORTH_WEST,
    PREV_DIR_NORTH_EAST,
    PREV_DIR_SOUTH_WEST,
    PREV_DIR_SOUTH_EAST,
    PREV_DIR_ROTATE_CW,
    PREV_DIR_ROTATE_CCW,
    PREV_DIR_NORTH_TURN_CW,
    PREV_DIR_NORTH_TURN_CCW,
    PREV_DIR_SOUTH_TURN_CW,
    PREV_DIR_SOUTH_TURN_CCW,
    PREV_DIR_STOP
} PREV_DIR_t;

typedef struct
{
    int8_t x;
    int8_t y;
    int8_t z;
} joystick_t;

extern joystick_t joystick;

void rover_movement(const joystick_t const * joystick);

#endif // ROVER_H

