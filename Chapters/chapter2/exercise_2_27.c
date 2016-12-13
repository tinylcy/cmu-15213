#include <stdio.h>
#include <stdlib.h>

int uadd_ok(unsigned x, unsigned y) {
	unsigned s = x + y;
	return s < x || s < y;
}

int main(void) {
	unsigned x = 0xFFFFFFFF;
	unsigned y = 0xEEEEEEEE;

	printf("add ok: %d\n", uadd_ok(x, y));
	printf("x + y = %x\n", x + y);
	return 0;
}
