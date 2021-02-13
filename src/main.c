#include <uart.h>

void main(void) {
	uart_print("ATX040 Bootloader " __DATE__ " " __TIME__ "\r\n");
	for (;;) {
		uart_putc(uart_getc());
	}
}
