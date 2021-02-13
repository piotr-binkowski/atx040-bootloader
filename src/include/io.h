#ifndef _IO_H
#define _IO_H

#include <stdint.h>

#define readb(addr) *(volatile uint8_t*)(addr)
#define writeb(addr, val) *(volatile uint8_t*)(addr) = (val)

#endif
