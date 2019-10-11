#include <avr/io.h>

#include "rover.h"
#include "stepper.h"

void rover_move_north(const uint8_t speed)
{
    stepper_stop_all();
    stepper_set_direction(STEPPER_1_DIR, STEPPER_FORWARD);
    stepper_set_direction(STEPPER_2_DIR, STEPPER_FORWARD);
    stepper_set_direction(STEPPER_3_DIR, STEPPER_FORWARD);
    stepper_set_direction(STEPPER_4_DIR, STEPPER_FORWARD);

    if (speed > 60)
    {
        OCR0A = speed;
    }
    else
    {
        OCR0A = 60;
    }

    stepper_speed.stepper_1_fast = STEPPER_MOVE;
    stepper_speed.stepper_2_fast = STEPPER_MOVE;
    stepper_speed.stepper_3_fast = STEPPER_MOVE;
    stepper_speed.stepper_4_fast = STEPPER_MOVE;
}

void rover_move_south(const uint8_t speed)
{
    stepper_stop_all();
    stepper_set_direction(STEPPER_1_DIR, STEPPER_BACKWARD);
    stepper_set_direction(STEPPER_2_DIR, STEPPER_BACKWARD);
    stepper_set_direction(STEPPER_3_DIR, STEPPER_BACKWARD);
    stepper_set_direction(STEPPER_4_DIR, STEPPER_BACKWARD);

    if (speed > 60)
    {
        OCR0A = speed;
    }
    else
    {
        OCR0A = 60;
    }

    stepper_speed.stepper_1_fast = STEPPER_MOVE;
    stepper_speed.stepper_2_fast = STEPPER_MOVE;
    stepper_speed.stepper_3_fast = STEPPER_MOVE;
    stepper_speed.stepper_4_fast = STEPPER_MOVE;
}

void rover_move_east(const uint8_t speed)
{
    stepper_stop_all();
    stepper_set_direction(STEPPER_1_DIR, STEPPER_FORWARD);
    stepper_set_direction(STEPPER_2_DIR, STEPPER_BACKWARD);
    stepper_set_direction(STEPPER_3_DIR, STEPPER_BACKWARD);
    stepper_set_direction(STEPPER_4_DIR, STEPPER_FORWARD);

    if (speed > 60)
    {
        OCR0A = speed;
    }
    else
    {
        OCR0A = 60;
    }

    stepper_speed.stepper_1_fast = STEPPER_MOVE;
    stepper_speed.stepper_2_fast = STEPPER_MOVE;
    stepper_speed.stepper_3_fast = STEPPER_MOVE;
    stepper_speed.stepper_4_fast = STEPPER_MOVE;
}

void rover_move_west(const uint8_t speed)
{
    stepper_stop_all();
    stepper_set_direction(STEPPER_1_DIR, STEPPER_BACKWARD);
    stepper_set_direction(STEPPER_2_DIR, STEPPER_FORWARD);
    stepper_set_direction(STEPPER_3_DIR, STEPPER_FORWARD);
    stepper_set_direction(STEPPER_4_DIR, STEPPER_BACKWARD);

    if (speed > 60)
    {
        OCR0A = speed;
    }
    else
    {
        OCR0A = 60;
    }

    stepper_speed.stepper_1_fast = STEPPER_MOVE;
    stepper_speed.stepper_2_fast = STEPPER_MOVE;
    stepper_speed.stepper_3_fast = STEPPER_MOVE;
    stepper_speed.stepper_4_fast = STEPPER_MOVE;
}

void rover_move_north_west(const uint8_t speed)
{
    stepper_stop_all();
    stepper_set_direction(STEPPER_2_DIR, STEPPER_FORWARD);
    stepper_set_direction(STEPPER_3_DIR, STEPPER_FORWARD);

    if (speed > 60)
    {
        OCR0A = speed;
    }
    else
    {
        OCR0A = 60;
    }

    stepper_speed.stepper_2_fast = STEPPER_MOVE;
    stepper_speed.stepper_3_fast = STEPPER_MOVE;
}

void rover_move_north_east(const uint8_t speed)
{
    stepper_stop_all();
    stepper_set_direction(STEPPER_1_DIR, STEPPER_FORWARD);
    stepper_set_direction(STEPPER_4_DIR, STEPPER_FORWARD);

    if (speed > 60)
    {
        OCR0A = speed;
    }
    else
    {
        OCR0A = 60;
    }

    stepper_speed.stepper_1_fast = STEPPER_MOVE;
    stepper_speed.stepper_4_fast = STEPPER_MOVE;
}

void rover_move_south_west(const uint8_t speed)
{
    stepper_stop_all();
    stepper_set_direction(STEPPER_1_DIR, STEPPER_BACKWARD);
    stepper_set_direction(STEPPER_4_DIR, STEPPER_BACKWARD);

    if (speed > 60)
    {
        OCR0A = speed;
    }
    else
    {
        OCR0A = 60;
    }

    stepper_speed.stepper_1_fast = STEPPER_MOVE;
    stepper_speed.stepper_4_fast = STEPPER_MOVE;
}

void rover_move_south_east(const uint8_t speed)
{
    stepper_stop_all();
    stepper_set_direction(STEPPER_2_DIR, STEPPER_BACKWARD);
    stepper_set_direction(STEPPER_3_DIR, STEPPER_BACKWARD);

    if (speed > 60)
    {
        OCR0A = speed;
    }
    else
    {
        OCR0A = 60;
    }

    stepper_speed.stepper_2_fast = STEPPER_MOVE;
    stepper_speed.stepper_3_fast = STEPPER_MOVE;
}

void rover_rotate_cw(const uint8_t speed)
{
    stepper_stop_all();
    stepper_set_direction(STEPPER_1_DIR, STEPPER_FORWARD);
    stepper_set_direction(STEPPER_2_DIR, STEPPER_BACKWARD);
    stepper_set_direction(STEPPER_3_DIR, STEPPER_FORWARD);
    stepper_set_direction(STEPPER_4_DIR, STEPPER_BACKWARD);

    if (speed > 120)
    {
        OCR0A = speed;
    }
    else
    {
        OCR0A = 120;
    }

    stepper_speed.stepper_1_fast = STEPPER_MOVE;
    stepper_speed.stepper_2_fast = STEPPER_MOVE;
    stepper_speed.stepper_3_fast = STEPPER_MOVE;
    stepper_speed.stepper_4_fast = STEPPER_MOVE;
}

void rover_rotate_ccw(const uint8_t speed)
{
    stepper_stop_all();
    stepper_set_direction(STEPPER_1_DIR, STEPPER_BACKWARD);
    stepper_set_direction(STEPPER_2_DIR, STEPPER_FORWARD);
    stepper_set_direction(STEPPER_3_DIR, STEPPER_BACKWARD);
    stepper_set_direction(STEPPER_4_DIR, STEPPER_FORWARD);

    if (speed > 120)
    {
        OCR0A = speed;
    }
    else
    {
        OCR0A = 120;
    }

    stepper_speed.stepper_1_fast = STEPPER_MOVE;
    stepper_speed.stepper_2_fast = STEPPER_MOVE;
    stepper_speed.stepper_3_fast = STEPPER_MOVE;
    stepper_speed.stepper_4_fast = STEPPER_MOVE;
}

