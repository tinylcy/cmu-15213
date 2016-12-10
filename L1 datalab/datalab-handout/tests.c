/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

//1
int test_bitOr(int x, int y)
{
  return x|y;
}
int test_specialBits(void) {
    return 0xffca3fff;
}
//2
int test_isZero(int x) {
  return x == 0;
}
int test_anyEvenBit(int x) {
  int i;
  for (i = 0; i < 32; i+=2)
      if (x & (1<<i))
   return 1;
  return 0;
}







int test_negate(int x) {
  return -x;
}
int test_leastBitPos(int x) {
  int mask = 1;
  if (x == 0)
    return 0;
  while (!(mask & x)) {
    mask = mask << 1;
  }
  return mask;
}
//3
int test_rotateLeft(int x, int n) {
  unsigned u = (unsigned) x;
  int i;
  for (i = 0; i < n; i++) {
      unsigned msb = u >> 31;
      unsigned rest = u << 1;
      u = rest | msb;
  }
  return (int) u;
}
int test_divpwr2(int x, int n)
{
    int p2n = 1<<n;
    return x/p2n;
}
int test_isLess(int x, int y)
{
  return x < y;
}
//4

int test_isPower2(int x) {
  int i;
  for (i = 0; i < 31; i++) {
    if (x == 1<<i)
      return 1;
  }
  return 0;
}
int test_bitReverse(int x) {
    int result = 0;
    int i;
    for (i = 0; i < 32; i++) {
 int bit = (x >> i) & 0x1;
 int pos = 31-i;
 result |= bit << pos;
    }
    return result;
}
//float
unsigned test_float_abs(unsigned uf) {
  float f = u2f(uf);
  unsigned unf = f2u(-f);
  if (isnan(f))
    return uf;
  /* An unfortunate hack to get around a limitation of the BDD Checker */
  if ((int) uf < 0)
      return unf;
  else
      return uf;
}
unsigned test_float_i2f(int x) {
  float f = (float) x;
  return f2u(f);
}
unsigned test_float_times64(unsigned uf) {
  float f = u2f(uf);
  float tenf = 64*f;
  if (isnan(f))
    return uf;
  else
    return f2u(tenf);
}
