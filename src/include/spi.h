#ifndef _SPI_H
#define _SPI_H

#include <stdint.h>

#define SPI_BASE	0xC4000000

#define SPI_DATA	0x0
#define SPI_STATUS	0x4

#define SPI_SS		0x1
#define SPI_BUSY	0x2

void spi_ss(uint8_t);
uint8_t spi_txrx(uint8_t);

#endif
