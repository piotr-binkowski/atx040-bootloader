#include <stdint.h>

#include <timer.h>
#include <uart.h>
#include <spi.h>

#define BOOT_OFFSET	0x80000
#define BOOT_SIZE	(256*1024)
#define BOOT_ADDR	0x1F00000
#define FLASH_CMD_READ	0x03


static void flash_copy(uint32_t addr, uint32_t len, void *buf) {
	uint32_t *dst = (uint32_t*)buf;
	spi_ss(0);

	spi_txrx32((FLASH_CMD_READ << 24) | (addr & 0xffffff));

	for(uint32_t i = 0; i < (len / 4); i++)
		dst[i] = spi_txrx32(0);

	spi_ss(1);
}

void main(void) {
	uart_print("ATX040 Bootloader " __DATE__ " " __TIME__ "\r\n");
	flash_copy(BOOT_OFFSET, BOOT_SIZE, (void*)(BOOT_ADDR));
	void *ptr = (void*)(BOOT_ADDR + 0x400);
	uart_print("Booting...\r\n");
	goto *ptr;
}
