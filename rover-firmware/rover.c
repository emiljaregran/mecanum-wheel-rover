#include <avr/io.h>
#include <math.h>
#include <stdlib.h>

#include "rover.h"
#include "stepper.h"

static PREV_DIR_t prev_dir = PREV_DIR_STOP;

static void rover_move_north(const int8_t joystick_y);
static void rover_move_south(const int8_t joystick_y);
static void rover_move_west(const int8_t joystick_x);
static void rover_move_east(const int8_t joystick_x);

static void rover_move_north_west(const int8_t joystick_x, const int8_t joystick_y);
static void rover_move_north_east(const int8_t joystick_x, const int8_t joystick_y);
static void rover_move_south_west(const int8_t joystick_x, const int8_t joystick_y);
static void rover_move_south_east(const int8_t joystick_x, const int8_t joystick_y);

static void rover_rotate_cw(const int8_t joystick_z);
static void rover_rotate_ccw(const int8_t joystick_z);

static void rover_move_north_turn_cw(const int8_t joystick_y, const int8_t joystick_z);
static void rover_move_north_turn_ccw(const int8_t joystick_y, const int8_t joystick_z);
static void rover_move_south_turn_cw(const int8_t joystick_y, const int8_t joystick_z);
static void rover_move_south_turn_ccw(const int8_t joystick_y, const int8_t joystick_z);

void rover_movement(const joystick_t * const joystick)
{
    if ((0 == joystick->x) && (joystick->y > 0) && (0 == joystick->z))
    {
        rover_move_north(joystick->y);
    }
    else if ((0 == joystick->x) && (joystick->y < 0) && (0 == joystick->z))
    {
        rover_move_south(joystick->y);
    }
    else if ((joystick->x < 0) && (0 == joystick->y) && (0 == joystick->z))
    {
        rover_move_west(joystick->x);
    }
    else if ((joystick->x > 0) && (0 == joystick->y) && (0 == joystick->z))
    {
        rover_move_east(joystick->x);
    }
    else if ((joystick->x < 0) && (joystick->y > 0) && (0 == joystick->z))
    {
        rover_move_north_west(joystick->x, joystick->y);
    }
    else if ((joystick->x > 0) && (joystick->y > 0) && (0 == joystick->z))
    {
        rover_move_north_east(joystick->x, joystick->y);
    }
    else if ((joystick->x < 0) && (joystick->y < 0) && (0 == joystick->z))
    {
        rover_move_south_west(joystick->x, joystick->y);
    }
    else if ((joystick->x > 0) && (joystick->y < 0) && (0 == joystick->z))
    {
        rover_move_south_east(joystick->x, joystick->y);
    }
    else if ((0 == joystick->x) && (0 == joystick->y) && (joystick->z > 30))
    {
        rover_rotate_cw(joystick->z);
    }
    else if ((0 == joystick->x) && (0 == joystick->y) && (joystick->z < -20))
    {
        rover_rotate_ccw(joystick->z);
    }
    else if ((0 == joystick->x) && (joystick->y > 0) && (joystick->z > 30))
    {
        rover_move_north_turn_cw(joystick->y, joystick->z);
    }
    else if ((0 == joystick->x) && (joystick->y > 0) && (joystick->z < -20))
    {
        rover_move_north_turn_ccw(joystick->y, joystick->z);
    }
    else if ((0 == joystick->x) && (joystick->y < 0) && (joystick->z > 30))
    {
        rover_move_south_turn_cw(joystick->y, joystick->z);
    }
    else if ((0 == joystick->x) && (joystick->y < 0) && (joystick->z < -20))
    {
        rover_move_south_turn_ccw(joystick->y, joystick->z);
    }
    else
    {
        rover_stop();
    }
}

static void rover_move_north(const int8_t joystick_y)
{
    uint8_t current_speed = OCR0A;
    uint8_t target_speed = UINT8_MAX - ((uint8_t) joystick_y * 2);

    if (prev_dir != PREV_DIR_NORTH)
    {
        prev_dir = PREV_DIR_NORTH;

        stepper_stop_all();
        stepper_set_direction(STEPPER_1_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_2_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_3_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_4_DIR, STEPPER_FORWARD);

        stepper_speed.stepper_1_fast = STEPPER_MOVE;
        stepper_speed.stepper_2_fast = STEPPER_MOVE;
        stepper_speed.stepper_3_fast = STEPPER_MOVE;
        stepper_speed.stepper_4_fast = STEPPER_MOVE;
    }

    if ((target_speed < current_speed) && (current_speed > ROVER_SPEED_LIMIT))
    {
        current_speed--;
    }
    else if (target_speed > current_speed)
    {
        current_speed++;
    }

    OCR0A = current_speed;
}

static void rover_move_south(const int8_t joystick_y)
{
    uint8_t current_speed = OCR0A;
    uint8_t target_speed = UINT8_MAX - ((uint8_t) abs(joystick_y) * 2);

    if (prev_dir != PREV_DIR_NORTH)
    {
        prev_dir = PREV_DIR_NORTH;

        stepper_stop_all();
        stepper_set_direction(STEPPER_1_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_2_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_3_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_4_DIR, STEPPER_BACKWARD);

        stepper_speed.stepper_1_fast = STEPPER_MOVE;
        stepper_speed.stepper_2_fast = STEPPER_MOVE;
        stepper_speed.stepper_3_fast = STEPPER_MOVE;
        stepper_speed.stepper_4_fast = STEPPER_MOVE;
    }

    if ((target_speed < current_speed) && (current_speed > ROVER_SPEED_LIMIT))
    {
        current_speed--;
    }
    else if (target_speed > current_speed)
    {
        current_speed++;
    }

    OCR0A = current_speed;
}

static void rover_move_west(const int8_t joystick_x)
{
    uint8_t current_speed = OCR0A;
    uint8_t target_speed = UINT8_MAX - ((uint8_t) abs(joystick_x) * 2);

    if (prev_dir != PREV_DIR_WEST)
    {
        prev_dir = PREV_DIR_WEST;

        stepper_stop_all();
        stepper_set_direction(STEPPER_1_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_2_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_3_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_4_DIR, STEPPER_BACKWARD);

        stepper_speed.stepper_1_fast = STEPPER_MOVE;
        stepper_speed.stepper_2_fast = STEPPER_MOVE;
        stepper_speed.stepper_3_fast = STEPPER_MOVE;
        stepper_speed.stepper_4_fast = STEPPER_MOVE;
    }

    if ((target_speed < current_speed) && (current_speed > ROVER_SPEED_LIMIT))
    {
        current_speed--;
    }
    else if (target_speed > current_speed)
    {
        current_speed++;
    }

    OCR0A = current_speed;
}

static void rover_move_east(const int8_t joystick_x)
{
    uint8_t current_speed = OCR0A;
    uint8_t target_speed = UINT8_MAX - ((uint8_t) joystick_x * 2);

    if (prev_dir != PREV_DIR_EAST)
    {
        prev_dir = PREV_DIR_EAST;

        stepper_stop_all();
        stepper_set_direction(STEPPER_1_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_2_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_3_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_4_DIR, STEPPER_FORWARD);

        stepper_speed.stepper_1_fast = STEPPER_MOVE;
        stepper_speed.stepper_2_fast = STEPPER_MOVE;
        stepper_speed.stepper_3_fast = STEPPER_MOVE;
        stepper_speed.stepper_4_fast = STEPPER_MOVE;
    }

    if ((target_speed < current_speed) && (current_speed > ROVER_SPEED_LIMIT))
    {
        current_speed--;
    }
    else if (target_speed > current_speed)
    {
        current_speed++;
    }

    OCR0A = current_speed;
}

static void rover_move_north_west(const int8_t joystick_x, const int8_t joystick_y)
{
    uint8_t current_speed = OCR0A;
    double x = (double) abs(joystick_x);
    double y = (double) joystick_y;
    uint8_t target_speed = (uint8_t) ((double) UINT8_MAX - hypot(x, y));

    if (prev_dir != PREV_DIR_NORTH_WEST)
    {
        prev_dir = PREV_DIR_NORTH_WEST;

        stepper_stop_all();
        stepper_set_direction(STEPPER_2_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_3_DIR, STEPPER_FORWARD);

        stepper_speed.stepper_2_fast = STEPPER_MOVE;
        stepper_speed.stepper_3_fast = STEPPER_MOVE;
    }

    if ((target_speed < current_speed) && (current_speed > ROVER_SPEED_LIMIT))
    {
        current_speed--;
    }
    else if (target_speed > current_speed)
    {
        current_speed++;
    }

    OCR0A = current_speed;
}

static void rover_move_north_east(const int8_t joystick_x, const int8_t joystick_y)
{
    uint8_t current_speed = OCR0A;
    double x = (double) joystick_x;
    double y = (double) joystick_y;
    uint8_t target_speed = (uint8_t) ((double) UINT8_MAX - hypot(x, y));

    if (prev_dir != PREV_DIR_NORTH_EAST)
    {
        prev_dir = PREV_DIR_NORTH_EAST;

        stepper_stop_all();
        stepper_set_direction(STEPPER_1_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_4_DIR, STEPPER_FORWARD);

        stepper_speed.stepper_1_fast = STEPPER_MOVE;
        stepper_speed.stepper_4_fast = STEPPER_MOVE;
    }

    if ((target_speed < current_speed) && (current_speed > ROVER_SPEED_LIMIT))
    {
        current_speed--;
    }
    else if (target_speed > current_speed)
    {
        current_speed++;
    }

    OCR0A = current_speed;
}

static void rover_move_south_west(const int8_t joystick_x, const int8_t joystick_y)
{
    uint8_t current_speed = OCR0A;
    double x = (double) abs(joystick_x);
    double y = (double) abs(joystick_y);
    uint8_t target_speed = (uint8_t) ((double) UINT8_MAX - hypot(x, y));

    if (prev_dir != PREV_DIR_SOUTH_WEST)
    {
        prev_dir = PREV_DIR_SOUTH_WEST;

        stepper_stop_all();
        stepper_set_direction(STEPPER_1_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_4_DIR, STEPPER_BACKWARD);

        stepper_speed.stepper_1_fast = STEPPER_MOVE;
        stepper_speed.stepper_4_fast = STEPPER_MOVE;
    }

    if ((target_speed < current_speed) && (current_speed > ROVER_SPEED_LIMIT))
    {
        current_speed--;
    }
    else if (target_speed > current_speed)
    {
        current_speed++;
    }

    OCR0A = current_speed;
}

static void rover_move_south_east(const int8_t joystick_x, const int8_t joystick_y)
{
    uint8_t current_speed = OCR0A;
    double x = (double) joystick_x;
    double y = (double) abs(joystick_y);
    uint8_t target_speed = (uint8_t) ((double) UINT8_MAX - hypot(x, y));

    if (prev_dir != PREV_DIR_SOUTH_EAST)
    {
        prev_dir = PREV_DIR_SOUTH_EAST;

        stepper_stop_all();
        stepper_set_direction(STEPPER_2_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_3_DIR, STEPPER_BACKWARD);

        stepper_speed.stepper_2_fast = STEPPER_MOVE;
        stepper_speed.stepper_3_fast = STEPPER_MOVE;
    }

    if ((target_speed < current_speed) && (current_speed > ROVER_SPEED_LIMIT))
    {
        current_speed--;
    }
    else if (target_speed > current_speed)
    {
        current_speed++;
    }

    OCR0A = current_speed;
}

static void rover_rotate_cw(const int8_t joystick_z)
{
    uint8_t current_speed = OCR0A;
    uint8_t target_speed = UINT8_MAX - (uint8_t) joystick_z;

    if (prev_dir != PREV_DIR_ROTATE_CW)
    {
        prev_dir = PREV_DIR_ROTATE_CW;

        stepper_stop_all();
        stepper_set_direction(STEPPER_1_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_2_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_3_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_4_DIR, STEPPER_BACKWARD);

        stepper_speed.stepper_1_fast = STEPPER_MOVE;
        stepper_speed.stepper_2_fast = STEPPER_MOVE;
        stepper_speed.stepper_3_fast = STEPPER_MOVE;
        stepper_speed.stepper_4_fast = STEPPER_MOVE;
    }

    if ((target_speed < current_speed) && (current_speed > ROVER_SPEED_LIMIT))
    {
        current_speed--;
    }
    else if (target_speed > current_speed)
    {
        current_speed++;
    }

    OCR0A = current_speed;
}

static void rover_rotate_ccw(const int8_t joystick_z)
{
    uint8_t current_speed = OCR0A;
    uint8_t target_speed = UINT8_MAX - ((uint8_t) abs(joystick_z) * 3);

    if (prev_dir != PREV_DIR_ROTATE_CCW)
    {
        prev_dir = PREV_DIR_ROTATE_CCW;

        stepper_stop_all();
        stepper_set_direction(STEPPER_1_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_2_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_3_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_4_DIR, STEPPER_FORWARD);

        stepper_speed.stepper_1_fast = STEPPER_MOVE;
        stepper_speed.stepper_2_fast = STEPPER_MOVE;
        stepper_speed.stepper_3_fast = STEPPER_MOVE;
        stepper_speed.stepper_4_fast = STEPPER_MOVE;
    }

    if ((target_speed < current_speed) && (current_speed > ROVER_SPEED_LIMIT))
    {
        current_speed--;
    }
    else if (target_speed > current_speed)
    {
        current_speed++;
    }

    OCR0A = current_speed;
}

static void rover_move_north_turn_cw(const int8_t joystick_y, const int8_t joystick_z)
{
    uint8_t current_fast_speed = OCR0A;
    uint8_t current_slow_speed = OCR2A;
    uint8_t fast_speed = UINT8_MAX - ((uint8_t) joystick_z * 3);
    uint8_t slow_speed = UINT8_MAX - ((uint8_t) joystick_y * 2);

    if (prev_dir != PREV_DIR_NORTH_TURN_CW)
    {
        prev_dir = PREV_DIR_NORTH_TURN_CW;

        stepper_stop_all();
        stepper_set_direction(STEPPER_1_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_2_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_3_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_4_DIR, STEPPER_FORWARD);

        stepper_speed.stepper_1_fast = STEPPER_MOVE;
        stepper_speed.stepper_2_slow = STEPPER_MOVE;
        stepper_speed.stepper_3_fast = STEPPER_MOVE;
        stepper_speed.stepper_4_slow = STEPPER_MOVE;
    }

    if ((fast_speed < current_fast_speed) && (current_fast_speed > ROVER_SPEED_LIMIT))
    {
        current_fast_speed--;
    }
    else if (fast_speed > current_fast_speed)
    {
        current_fast_speed++;
    }

    if ((slow_speed < current_slow_speed) && (current_slow_speed > ROVER_SPEED_LIMIT))
    {
        current_slow_speed--;
    }
    else if (slow_speed > current_slow_speed)
    {
        current_slow_speed++;
    }

    OCR0A = current_fast_speed;
    OCR2A = current_slow_speed;
}

static void rover_move_north_turn_ccw(const int8_t joystick_y, const int8_t joystick_z)
{
    uint8_t current_fast_speed = OCR0A;
    uint8_t current_slow_speed = OCR2A;
    uint8_t fast_speed = UINT8_MAX - ((uint8_t) abs(joystick_z) * 4);
    uint8_t slow_speed = UINT8_MAX - ((uint8_t) joystick_y * 2);

    if (prev_dir != PREV_DIR_NORTH_TURN_CCW)
    {
        prev_dir = PREV_DIR_NORTH_TURN_CCW;

        stepper_stop_all();
        stepper_set_direction(STEPPER_1_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_2_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_3_DIR, STEPPER_FORWARD);
        stepper_set_direction(STEPPER_4_DIR, STEPPER_FORWARD);

        stepper_speed.stepper_1_slow = STEPPER_MOVE;
        stepper_speed.stepper_2_fast = STEPPER_MOVE;
        stepper_speed.stepper_3_slow = STEPPER_MOVE;
        stepper_speed.stepper_4_fast = STEPPER_MOVE;
    }

    if ((fast_speed < current_fast_speed) && (current_fast_speed > ROVER_SPEED_LIMIT))
    {
        current_fast_speed--;
    }
    else if (fast_speed > current_fast_speed)
    {
        current_fast_speed++;
    }

    if ((slow_speed < current_slow_speed) && (current_slow_speed > ROVER_SPEED_LIMIT))
    {
        current_slow_speed--;
    }
    else if (slow_speed > current_slow_speed)
    {
        current_slow_speed++;
    }

    OCR0A = current_fast_speed;
    OCR2A = current_slow_speed;
}

static void rover_move_south_turn_cw(const int8_t joystick_y, const int8_t joystick_z)
{
    uint8_t current_fast_speed = OCR0A;
    uint8_t current_slow_speed = OCR2A;
    uint8_t fast_speed = UINT8_MAX - ((uint8_t) joystick_z * 3);
    uint8_t slow_speed = UINT8_MAX - ((uint8_t) abs(joystick_y) * 2);

    if (prev_dir != PREV_DIR_SOUTH_TURN_CW)
    {
        prev_dir = PREV_DIR_SOUTH_TURN_CW;

        stepper_stop_all();
        stepper_set_direction(STEPPER_1_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_2_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_3_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_4_DIR, STEPPER_BACKWARD);

        stepper_speed.stepper_1_fast = STEPPER_MOVE;
        stepper_speed.stepper_2_slow = STEPPER_MOVE;
        stepper_speed.stepper_3_fast = STEPPER_MOVE;
        stepper_speed.stepper_4_slow = STEPPER_MOVE;
    }

    if ((fast_speed < current_fast_speed) && (current_fast_speed > ROVER_SPEED_LIMIT))
    {
        current_fast_speed--;
    }
    else if (fast_speed > current_fast_speed)
    {
        current_fast_speed++;
    }

    if ((slow_speed < current_slow_speed) && (current_slow_speed > ROVER_SPEED_LIMIT))
    {
        current_slow_speed--;
    }
    else if (slow_speed > current_slow_speed)
    {
        current_slow_speed++;
    }

    OCR0A = current_fast_speed;
    OCR2A = current_slow_speed;
}

static void rover_move_south_turn_ccw(const int8_t joystick_y, const int8_t joystick_z)
{
    uint8_t current_fast_speed = OCR0A;
    uint8_t current_slow_speed = OCR2A;
    uint8_t fast_speed = UINT8_MAX - ((uint8_t) abs(joystick_z) * 5);
    uint8_t slow_speed = UINT8_MAX - ((uint8_t) abs(joystick_y) * 2);

    if (prev_dir != PREV_DIR_SOUTH_TURN_CCW)
    {
        prev_dir = PREV_DIR_SOUTH_TURN_CCW;

        stepper_stop_all();
        stepper_set_direction(STEPPER_1_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_2_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_3_DIR, STEPPER_BACKWARD);
        stepper_set_direction(STEPPER_4_DIR, STEPPER_BACKWARD);

        stepper_speed.stepper_1_slow = STEPPER_MOVE;
        stepper_speed.stepper_2_fast = STEPPER_MOVE;
        stepper_speed.stepper_3_slow = STEPPER_MOVE;
        stepper_speed.stepper_4_fast = STEPPER_MOVE;
    }

    if ((fast_speed < current_fast_speed) && (current_fast_speed > ROVER_SPEED_LIMIT))
    {
        current_fast_speed--;
    }
    else if (fast_speed > current_fast_speed)
    {
        current_fast_speed++;
    }

    if ((slow_speed < current_slow_speed) && (current_slow_speed > ROVER_SPEED_LIMIT))
    {
        current_slow_speed--;
    }
    else if (slow_speed > current_slow_speed)
    {
        current_slow_speed++;
    }

    OCR0A = current_fast_speed;
    OCR2A = current_slow_speed;
}

void rover_stop(void)
{
    prev_dir = PREV_DIR_STOP;

    // De-acceleration for smooth stops.
    if (OCR0A < 254)
    {
        OCR0A += 2;
    }
    if (OCR2A < 254)
    {
        OCR2A += 2;
    }

    if ((OCR0A >= 254) && (OCR2A >= 254))
    {
        stepper_stop_all();
    }
}

