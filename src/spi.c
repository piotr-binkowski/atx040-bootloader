#include <spi.h>
#include <io.h>

void spi_ss(uint8_t val) {
	uint8_t reg = readb(SPI_BASE + SPI_STATUS);

	if(val)
		reg |= SPI_SS;
	else
		reg &= ~SPI_SS;

	writeb(SPI_BASE + SPI_STATUS, reg);
}

uint8_t spi_txrx(uint8_t val) {
	writeb(SPI_BASE + SPI_DATA, val);
	while(readb(SPI_BASE + SPI_STATUS) & SPI_BUSY);
	return readb(SPI_BASE + SPI_DATA);
}
