#include <stdint.h>
#include <stdlib.h>

#include "adc.h"
#include "joystick.h"

static uint8_t joystick_center[JOYSTICK_AXIS_COUNT];
static int8_t joystick_get_position(const uint8_t axis);

void joystick_set_center(void)
{
    for (uint8_t axis = 0; axis < JOYSTICK_AXIS_COUNT; axis++)
    {
        joystick_center[axis] = g_adc_reading[axis];
    }
}

joystick_data_t joystick_get_data(void)
{
    joystick_data_t joystick_data;

    joystick_data.x_position = joystick_get_position(JOYSTICK_AXIS_X);
    joystick_data.y_position = joystick_get_position(JOYSTICK_AXIS_Y);
    joystick_data.z_position = joystick_get_position(JOYSTICK_AXIS_Z);

    return joystick_data;
}

static int8_t joystick_get_position(const uint8_t axis)
{
    int8_t position = 0;
    int16_t movement = (int16_t) g_adc_reading[axis] - (int16_t) joystick_center[axis];

    if (abs(movement) > JOYSTICK_DEADBAND)
    {
        // Special fix for wierd scaling on the Z-axis.
        if ((JOYSTICK_AXIS_Z == axis) && (movement < 0))
        {
            movement *= 8;
        }

        if (movement > INT8_MAX)
        {
            position = INT8_MAX;
        }
        else if (movement < INT8_MIN)
        {
            position = INT8_MIN;
        }
        else
        {
            position = movement;
        }
    }

    return position;
}

