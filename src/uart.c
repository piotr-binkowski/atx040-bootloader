#include <uart.h>
#include <io.h>

void uart_putc(uint8_t c) {
	while(readb(UART_BASE + UART_STATUS) & TX_FULL);
	writeb(UART_BASE + UART_DATA, c);
}

void uart_print(const char* s) {
	for(s; *s; s++)
		uart_putc(*s);
}

uint8_t uart_getc(void) {
	while(readb(UART_BASE + UART_STATUS) & RX_EMPTY);
	return readb(UART_BASE + UART_DATA);
}
