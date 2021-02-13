#ifndef _UART_H
#define _UART_H

#include <stdint.h>

#define UART_BASE	0xC0000000

#define UART_DATA	0x0
#define UART_STATUS	0x4

#define RX_EMPTY	0x1
#define RX_FULL		0x2
#define TX_EMPTY	0x4
#define TX_FULL		0x8

void uart_putc(uint8_t);
void uart_print(const char* s);

uint8_t uart_getc(void);

#endif
