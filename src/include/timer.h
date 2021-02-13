#ifndef _TIMER_H
#define _TIMER_H

#include <stdint.h>

#define TIMER_BASE	0xC8000000

#define TIMER_LO	0x0
#define TIMER_HI	0x4

uint64_t timer_get(void);

#endif
