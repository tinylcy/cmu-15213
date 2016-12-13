#include <stdio.h>
#include <stdlib.h>

float sum_element(float a[], unsigned length) {
	int i;
	float result = 0;
	for(i = 0; i <= (int)(length - 1); i++) {
		result += a[i];
	}

	return result;
}

int main(void) {
	float a[] = {1.0, 2.0};
	int alen = 2;
	printf("%f\n", sum_element(a, alen));
	
	float b[] = {};
	int blen = 0;
	printf("%f\n", sum_element(b, blen));

	return 0;
}
