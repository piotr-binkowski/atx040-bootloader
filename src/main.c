#include <stdint.h>

#include <timer.h>
#include <uart.h>
#include <spi.h>

static char htoa(uint8_t h) {
	h = h & 0xF;
	if (h < 10)
		return '0' + h;
	else
		return 'A' + (h - 10);

}

static void ctoa(uint8_t val, char *str) {
	str[0] = htoa(val >> 4);
	str[1] = htoa(val);
	str[2] = '\0';
}

#define FLASH_CMD_READ	0x03

static void flash_dump(uint32_t addr, uint32_t len) {
	char buf[3];

	spi_ss(0);

	spi_txrx(FLASH_CMD_READ);

	spi_txrx((addr >> 16) & 0xFF);
	spi_txrx((addr >> 8) & 0xFF);
	spi_txrx(addr & 0xFF);

	uart_print("\r\nFlash dump\r\n");

	for(uint32_t i = 0; i < len; i++) {
		if ((i % 16) == 0) {
			uart_print("\r\n");
		}
		ctoa(spi_txrx(0), buf);
		uart_print(buf);
		uart_print(" ");
	}

	uart_print("\r\nFlash dump end\r\n");

	spi_ss(1);
}

static void flash_copy(uint32_t addr, uint32_t len, void *buf) {
	uint8_t *dst = (uint8_t*)buf;
	spi_ss(0);

	spi_txrx(FLASH_CMD_READ);

	spi_txrx((addr >> 16) & 0xFF);
	spi_txrx((addr >> 8) & 0xFF);
	spi_txrx(addr & 0xFF);

	for(uint32_t i = 0; i < len; i++)
		dst[i] = spi_txrx(0);

	spi_ss(1);
}

void main(void) {
	uart_print("ATX040 Bootloader " __DATE__ " " __TIME__ "\r\n");
	flash_copy(0x80000, 256*1024, (void*)(31*1024*1024));
	void *ptr = (void*)(31*1024*1024 + 0x400);
	uart_print("Booting...\r\n");
	goto *ptr;
}
