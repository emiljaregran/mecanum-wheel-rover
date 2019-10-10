#ifndef STEPPER_H
#define STEPPER_H

#define STEPPER_1_DIR       PORTC0
#define STEPPER_1_EN        PORTD2
#define STEPPER_1_STEP      PORTD6

#define STEPPER_2_DIR       PORTC1
#define STEPPER_2_EN        PORTD4
#define STEPPER_2_STEP      PORTD5

#define STEPPER_3_DIR       PORTC2
#define STEPPER_3_EN        PORTD7
#define STEPPER_3_STEP      PORTB3

#define STEPPER_4_DIR       PORTC3
#define STEPPER_4_EN        PORTB0
#define STEPPER_4_STEP      PORTD3

#define STEPPER_STOP        0
#define STEPPER_MOVE        1
#define STEPPER_FORWARD     0
#define STEPPER_BACKWARD    1

extern uint8_t stepper_1_motion;
extern uint8_t stepper_2_motion;
extern uint8_t stepper_3_motion;
extern uint8_t stepper_4_motion;

void stepper_init(void);
void stepper_set_direction(const uint8_t stepper, const uint8_t direction);

void step_move_north(const uint8_t speed);
void step_move_south(const uint8_t speed);
void step_move_east(const uint8_t speed);
void step_move_west(const uint8_t speed);
void step_move_north_west(const uint8_t speed);
void step_move_north_east(const uint8_t speed);
void step_move_south_west(const uint8_t speed);
void step_move_south_east(const uint8_t speed);
void step_stop(void);

#endif // STEPPER_H

