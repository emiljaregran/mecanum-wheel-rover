#ifndef ROVER_H
#define ROVER_H

#define ROVER_SPEED_LIMIT   8

typedef enum
{
    PREV_DIR_NORTH,
    PREV_DIR_SOUTH,
    PREV_DIR_ROTATE_CW,
    PREV_DIR_ROTATE_CCW,
    PREV_DIR_STOP
} PREV_DIR_t;

void rover_move_north(const uint8_t target_speed);
void rover_move_south(const uint8_t target_speed);
void rover_move_east(const uint8_t speed);
void rover_move_west(const uint8_t speed);

void rover_move_north_west(const uint8_t speed);
void rover_move_north_east(const uint8_t speed);
void rover_move_south_west(const uint8_t speed);
void rover_move_south_east(const uint8_t speed);

void rover_rotate_cw(const uint8_t target_speed);
void rover_rotate_ccw(const uint8_t target_speed);

void rover_stop(void);

#endif // ROVER_H

