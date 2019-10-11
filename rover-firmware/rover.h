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
    PREV_DIR_STOP
} PREV_DIR_t;

void rover_move_north(const uint8_t target_speed);
void rover_move_south(const uint8_t target_speed);
void rover_move_west(const uint8_t target_speed);
void rover_move_east(const uint8_t target_speed);

void rover_move_north_west(const uint8_t target_speed);
void rover_move_north_east(const uint8_t target_speed);
void rover_move_south_west(const uint8_t target_speed);
void rover_move_south_east(const uint8_t target_speed);

void rover_rotate_cw(const uint8_t target_speed);
void rover_rotate_ccw(const uint8_t target_speed);

void rover_move_north_turn_cw(const uint8_t fast_speed, const uint8_t slow_speed);

void rover_stop(void);

#endif // ROVER_H

