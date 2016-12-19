int procprob(int a, short b, long *u, char *v) {
	*u += a;
	*v += b;
	return sizeof(a) + sizeof(b);
}
