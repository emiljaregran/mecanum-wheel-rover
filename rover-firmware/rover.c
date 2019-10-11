#include <avr/io.h>

#include "rover.h"
#include "stepper.h"

static PREV_DIR_t prev_dir = PREV_DIR_STOP;

void rover_move_north(const uint8_t target_speed)
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

void rover_move_south(const uint8_t target_speed)
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

void rover_move_west(const uint8_t target_speed)
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

void rover_move_east(const uint8_t target_speed)
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

void rover_move_north_west(const uint8_t target_speed)
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

void rover_move_north_east(const uint8_t target_speed)
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

void rover_move_south_west(const uint8_t target_speed)
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

void rover_move_south_east(const uint8_t target_speed)
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

void rover_rotate_cw(const uint8_t target_speed)
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

void rover_rotate_ccw(const uint8_t target_speed)
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

void rover_move_north_turn_cw(const uint8_t fast_speed, const uint8_t slow_speed)
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

