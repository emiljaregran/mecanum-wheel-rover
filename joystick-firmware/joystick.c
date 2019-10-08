#include <stdint.h>
#include <stdlib.h>

#include "adc.h"
#include "joystick.h"

static uint8_t joystick_center[3];

void joystick_set_center(void)
{
    // Wait until a valid reading is available.
    while ((0 == g_adc_reading[0]) && (0 == g_adc_reading[1]) && (0 == g_adc_reading[2]))
    {
    }

    for (uint8_t axis = 0; axis < 3; axis++)
    {
        joystick_center[axis] = g_adc_reading[axis];
    }
}

int8_t joystick_get_x(void)
{
    int8_t x_position = 0;
    int16_t x_movement = (int16_t) g_adc_reading[0] - (int16_t) joystick_center[0];

    if (abs(x_movement) > JOYSTICK_DEADBAND_X)
    {
        if (x_movement > INT8_MAX)
        {
            x_position = INT8_MAX;
        }
        else if (x_movement < INT8_MIN)
        {
            x_position = INT8_MIN;
        }
        else
        {
            x_position = x_movement;
        }
    }

    return x_position;
}

int8_t joystick_get_y(void)
{
    int8_t y_position = 0;
    int16_t y_movement = (int16_t) g_adc_reading[1] - (int16_t) joystick_center[1];

    if (abs(y_movement) > JOYSTICK_DEADBAND_Y)
    {
        if (y_movement > INT8_MAX)
        {
            y_position = INT8_MAX;
        }
        else if (y_movement < INT8_MIN)
        {
            y_position = INT8_MIN;
        }
        else
        {
            y_position = y_movement;
        }
    }

    return y_position;
}

int8_t joystick_get_z(void)

{
    int z_position = 0;
    int16_t z_movement = (int16_t) g_adc_reading[2] - (int16_t) joystick_center[2];

    if (z_movement < -4 || z_movement > 15)
    {
        if (z_movement < 0)
        {
            z_movement *= 8;
        }

        if (z_movement > INT8_MAX)
        {
            z_position = INT8_MAX;
        }
        else if (z_movement < INT8_MIN)
        {
            z_position = INT8_MIN;
        }
        else
        {
            z_position = z_movement;
        }
    }

    return z_position;
}

