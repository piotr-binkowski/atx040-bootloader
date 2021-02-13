#ifndef _IO_H
#define _IO_H

#include <stdint.h>

#define readb(addr) *(volatile uint8_t*)(addr)
#define writeb(addr, val) *(volatile uint8_t*)(addr) = (val)

#define readw(addr) *(volatile uint16_t*)(addr)
#define writew(addr, val) *(volatile uint16_t*)(addr) = (val)

#define readl(addr) *(volatile uint32_t*)(addr)
#define writel(addr, val) *(volatile uint32_t*)(addr) = (val)

#endif
