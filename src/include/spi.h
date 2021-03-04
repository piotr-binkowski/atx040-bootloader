#ifndef _SPI_H
#define _SPI_H

#include <stdint.h>

#define SPI_BASE	0xC4000000

#define SPI_DATA_WR	0x0
#define SPI_DATA_RD_L	0x0
#define SPI_DATA_RD_B	0x3
#define SPI_STATUS	0x4

#define SPI_SS		0x1
#define SPI_RX_EMPTY	0x2

void spi_ss(uint8_t);
uint8_t spi_txrx8(uint8_t);
uint32_t spi_txrx32(uint32_t);

#endif
