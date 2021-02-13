#include <timer.h>
#include <io.h>

uint64_t timer_get(void) {
	uint32_t tmp1, tmp2, tmp3;

	do {
		tmp1 = readl(TIMER_BASE + TIMER_HI);
		tmp2 = readl(TIMER_BASE + TIMER_LO);
		tmp3 = readl(TIMER_BASE + TIMER_HI);
	} while (tmp1 != tmp3);

	return ((uint64_t)tmp1 << 32) | tmp2;
}
