#include "init.h"

int main(void) {
	rcc_init();
	gpio_init();
	while(1);
	return 0;
}
