#include <stdio.h>
#include <stdlib.h>

int tadd_ok(int x, int y) {
	int s;
	if(x > 0 && y > 0) {
		s = x + y;
		return s <= 0;
	}
	if(x < 0 && y < 0) {
		return s >= 0;
	}
	return 0;
}

int main(void) {
	int x = 0x7FFFFFFF;
	int y = 0x00000001;

	printf("tadd ok: %d\n", tadd_ok(x, y));
	printf("x + y = %x\n", x + y);

	return 0;
}
