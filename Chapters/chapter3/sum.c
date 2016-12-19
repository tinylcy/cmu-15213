long plus(long x, long y);

void sumstore(long x, long y, long *dest) {
	long t = plus(x, y);
	*dest = t;
}
