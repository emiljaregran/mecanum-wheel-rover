#ifndef TIMER_H
#define TIMER_H

extern volatile uint8_t timer_update_movement;
extern volatile uint8_t timer_stop_movement;

void timers_init(void);

#endif // TIMER_H
