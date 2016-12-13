#include <stdio.h>
#include <stdlib.h>

int func1(unsigned word) {
	return (int) ((word << 24) >> 24);
}

int func2(unsigned word) {
	return ((int) word << 24) >> 24;
}

int main(void) {
	unsigned w = 0x00000076;
	printf("func1: %x, func2: %x\n", func1(w), func2(w));
	w = 0x87654321;
	printf("func1: %x, func2: %x\n", func1(w), func2(w));
	w = 0x000000C9;
	printf("func1: %x, func2: %x\n", func1(w), func2(w));
	w = 0xEDCBA987;
	printf("func1: %x, func2: %x\n", func1(w), func2(w));

	return 0;
}
