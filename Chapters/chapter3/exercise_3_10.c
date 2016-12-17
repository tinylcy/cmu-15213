long arith2(long x, long y, long z) {
	long t1 = x | y;
	long t2 = t1 >> 3;
	long t3 = ~t2;
	long t4 = z - t3;
	return t4;
}
