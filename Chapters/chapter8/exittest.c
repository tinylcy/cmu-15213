#include <stdio.h>
#include <stdlib.h>

int func() {
	printf("This is func function.\n");
//	exit(0);
	return 0;
}

int main(void) {
	func();
	printf("会执行这句话吗？\n");
	return 0;
}
