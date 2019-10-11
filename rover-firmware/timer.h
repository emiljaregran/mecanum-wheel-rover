#ifndef TIMER_H
#define TIMER_H

extern volatile uint8_t timer_run_main;

void timer0_init(void);
void timer1_init(void);
void timer2_init(void);

#endif // TIMER_H
