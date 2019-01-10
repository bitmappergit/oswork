#ifndef TIMER_H
#define TIMER_H

#include "io.h"
#include "isr.h"

uint32_t get_timer_value();
void init_timer(uint32_t frequency);

#endif
