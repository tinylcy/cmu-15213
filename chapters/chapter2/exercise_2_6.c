#include <stdio.h>
#include <stdlib.h>
#include "show_bytes.h"

int main(void) {
	int ival = 3510593;
	float fval = 3510593.0;
	show_bytes((byte_pointer) &ival, sizeof(int));
	show_bytes((byte_pointer) &fval, sizeof(float));

	return 0;
}
