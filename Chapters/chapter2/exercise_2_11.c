#include <stdio.h>
#include <stdlib.h>

void inplace_swap(int *x, int *y) {
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
	int first, last;
	for(first = 0, last = cnt - 1; first < last; first++, last--) {
		inplace_swap(&a[first], &a[last]);
	}
}

void print_array(int a[], int cnt) {
	int i;
	for(i = 0; i < cnt; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(void) {
	int a[] = {1, 2, 3, 4, 5};
	int cnt = 5;
	reverse_array(a, cnt);
	print_array(a, cnt);
	return 0;
}
