#include <unistd.h>
#include <stdlib.h>

int main(void) {
	write(1, "hello, world\n", 13);
	_exit(0);
}
