#include <avr/io.h>
#include <math.h>
#include <stdlib.h>

#include "rover.h"
#include "stepper.h"

static PREV_DIR_t prev_dir = PREV_DIR_STOP;

static void rover_move_north(const uint8_t target_speed);
static void rover_move_south(const uint8_t target_speed);
static void rover_move_west(const uint8_t target_speed);
static void rover_move_east(const uint8_t target_speed);

static void rover_move_north_west(const uint8_t target_speed);
static void rover_move_north_east(const uint8_t target_speed);
static void rover_move_south_west(const uint8_t target_speed);
static void rover_move_south_east(const uint8_t target_speed);

static void rover_rotate_cw(const uint8_t target_speed);
static void rover_rotate_ccw(const uint8_t target_speed);

static void rover_move_north_turn_cw(const uint8_t fast_speed, const uint8_t slow_speed);
static void rover_move_north_turn_ccw(const uint8_t fast_speed, const uint8_t slow_speed);
static void rover_move_south_turn_cw(const uint8_t fast_speed, const uint8_t slow_speed);
static void rover_move_south_turn_ccw(const uint8_t fast_speed, const uint8_t slow_speed);

static void rover_stop(void);

void rover_movement(const joystick_t * const joystick)
{
    // Move north.
    if ((0 == joystick->x) && (joystick->y > 0) && (0 == joystick->z))
    {
        rover_move_north(255 - ((uint8_t) joystick->y * 2));
    }

    // Move south.
    else if ((0 == joystick->x) && (joystick->y < 0) && (0 == joystick->z))
    {
        rover_move_south(255 - ((uint8_t) abs(joystick->y) * 2));
    }

    // Move west.
    else if ((joystick->x < 0) && (0 == joystick->y) && (0 == joystick->z))
    {
        rover_move_west(255 - ((uint8_t) abs(joystick->x) * 2));
    }

    // Move east.
    else if ((joystick->x > 0) && (0 == joystick->y) && (0 == joystick->z))
    {
        rover_move_east(255 - ((uint8_t) joystick->x * 2));
    }

    // Move north west.
    else if ((joystick->x < 0) && (joystick->y > 0) && (0 == joystick->z))
    {
        double x = (double) abs(joystick->x);
        double y = (double) joystick->y;
        uint8_t target_speed = (uint8_t) ((double) 255 - hypot(x, y));

        rover_move_north_west(target_speed);
    }

    // Move north east.
    else if ((joystick->x > 0) && (joystick->y > 0) && (0 == joystick->z))
    {
        double x = (double) joystick->x;
        double y = (double) joystick->y;
        uint8_t target_speed = (uint8_t) ((double) 255 - hypot(x, y));

        rover_move_north_east(target_speed);
    }

    // Move south west.
    else if ((joystick->x < 0) && (joystick->y < 0) && (0 == joystick->z))
    {
        double x = (double) abs(joystick->x);
        double y = (double) abs(joystick->y);
        uint8_t target_speed = (uint8_t) ((double) 255 - hypot(x, y));

        rover_move_south_west(target_speed);
    }

    // Move south east.
    else if ((joystick->x > 0) && (joystick->y < 0) && (0 == joystick->z))
    {
        double x = (double) joystick->x;
        double y = (double) abs(joystick->y);
        uint8_t target_speed = (uint8_t) ((double) 255 - hypot(x, y));

        rover_move_south_east(target_speed);
    }

    // Rotate clockwise.
    else if ((0 == joystick->x) && (0 == joystick->y) && (joystick->z > 30))
    {
        rover_rotate_cw(255 - ((uint8_t) joystick->z * 2));
    }

    // Rotate counterclockwise.
    else if ((0 == joystick->x) && (0 == joystick->y) && (joystick->z < -20))
    {
        rover_rotate_ccw(255 - ((uint8_t) abs(joystick->z) * 3));
    }

    // Move forward and turn clockwise.
    else if ((0 == joystick->x) && (joystick->y > 0) && (joystick->z > 30))
    {
        uint8_t fast_speed = 255 - ((uint8_t) joystick->z * 3);
        uint8_t slow_speed = 255 - ((uint8_t) joystick->y * 2);

        rover_move_north_turn_cw(fast_speed, slow_speed);
    }

    // Move forward and turn counterclockwise.
    else if ((0 == joystick->x) && (joystick->y > 0) && (joystick->z < -20))
    {
        uint8_t fast_speed = 255 - ((uint8_t) abs(joystick->z) * 4);
        uint8_t slow_speed = 255 - ((uint8_t) joystick->y * 2);

        rover_move_north_turn_ccw(fast_speed, slow_speed);
    }

    // Move backward and turn right.
    else if ((0 == joystick->x) && (joystick->y < 0) && (joystick->z > 30))
    {
        uint8_t fast_speed = 255 - ((uint8_t) joystick->z * 3);
        uint8_t slow_speed = 255 - ((uint8_t) abs(joystick->y) * 2);

        rover_move_south_turn_cw(fast_speed, slow_speed);
    }

    // Move backward and turn left.
    else if ((0 == joystick->x) && (joystick->y < 0) && (joystick->z < -20))
    {
        uint8_t fast_speed = 255 - ((uint8_t) abs(joystick->z) * 5);
        uint8_t slow_speed = 255 - ((uint8_t) abs(joystick->y) * 2);

        rover_move_south_turn_ccw(fast_speed, slow_speed);
    }

    // Stand still.
    else
    {
        rover_stop();
    }
}

static void rover_move_north(const uint8_t target_speed)
{
    uint8_t current_speed = OCR0A;

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

static void rover_move_south(const uint8_t target_speed)
{
    uint8_t current_speed = OCR0A;

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

static void rover_move_west(const uint8_t target_speed)
{
    uint8_t current_speed = OCR0A;

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

static void rover_move_east(const uint8_t target_speed)
{
    uint8_t current_speed = OCR0A;

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

static void rover_move_north_west(const uint8_t target_speed)
{
    uint8_t current_speed = OCR0A;

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

static void rover_move_north_east(const uint8_t target_speed)
{
    uint8_t current_speed = OCR0A;

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

static void rover_move_south_west(const uint8_t target_speed)
{
    uint8_t current_speed = OCR0A;

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

static void rover_move_south_east(const uint8_t target_speed)
{
    uint8_t current_speed = OCR0A;

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

static void rover_rotate_cw(const uint8_t target_speed)
{
    uint8_t current_speed = OCR0A;

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

static void rover_rotate_ccw(const uint8_t target_speed)
{
    uint8_t current_speed = OCR0A;

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

static void rover_move_north_turn_cw(const uint8_t fast_speed, const uint8_t slow_speed)
{
    uint8_t current_fast_speed = OCR0A;
    uint8_t current_slow_speed = OCR2A;

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

static void rover_move_north_turn_ccw(const uint8_t fast_speed, const uint8_t slow_speed)
{
    uint8_t current_fast_speed = OCR0A;
    uint8_t current_slow_speed = OCR2A;

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

static void rover_move_south_turn_cw(const uint8_t fast_speed, const uint8_t slow_speed)
{
    uint8_t current_fast_speed = OCR0A;
    uint8_t current_slow_speed = OCR2A;

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

static void rover_move_south_turn_ccw(const uint8_t fast_speed, const uint8_t slow_speed)
{
    uint8_t current_fast_speed = OCR0A;
    uint8_t current_slow_speed = OCR2A;

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

static void rover_stop(void)
{
    prev_dir = PREV_DIR_STOP;

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

