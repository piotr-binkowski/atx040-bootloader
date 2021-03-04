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

uint8_t spi_txrx8(uint8_t val) {
	writeb(SPI_BASE + SPI_DATA_WR, val);
	while(readb(SPI_BASE + SPI_STATUS) & SPI_RX_EMPTY);
	return readb(SPI_BASE + SPI_DATA_RD_B);
}

uint32_t spi_txrx32(uint32_t val) {
	writel(SPI_BASE + SPI_DATA_WR, val);
	while(readb(SPI_BASE + SPI_STATUS) & SPI_RX_EMPTY);
	return readl(SPI_BASE + SPI_DATA_RD_L);
}
