#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "show_bytes.h"

/* gcc exercise_2_7.c show_bytes.c -o exercise_2_7 */
int main(void) {
	const char *s = "abcdef";
	show_bytes((byte_pointer) s, strlen(s) + 1);

	return 0;
}
