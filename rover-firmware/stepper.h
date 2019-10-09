#ifndef STEPPER_H
#define STEPPER_H

#define STEPPER_1_DIR   PORTC0
#define STEPPER_1_EN    PORTD2
#define STEPPER_1_STEP  PORTD6

extern uint8_t stepper_x_move;

void stepper_init(void);
void stepper_step(void);

#endif // STEPPER_H

