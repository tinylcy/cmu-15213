long test(long x, long y) {
	long val = 8 * x;
	if(y > 0) {
		if(x >= y) {
			val = y & x;
		} else {
			val = y - x;
		}
	} else if(y <= -2) {
		val = x + y;
	}
	return val;
}
