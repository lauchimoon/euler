// 3807504276997394
#include <stdio.h>

#define EULER_COMMON_IMPLEMENTATION
#include "common.h"

#define TOP 50000000
#define TARGET 50

Bool *primes;
typedef unsigned long long int ull;

ull reverse(ull n)
{
  ull rev = 0;
  while (n > 0) {
    rev = rev*10 + n%10;
    n /= 10;
  }

  return rev;
}

int is_palindrome(ull n, ull reversen)
{
  if (n < 10)
    return 0;

  return reversen*reversen == n*n;
}

Bool are_reversible_square_primes(ull x, ull xr)
{
  if (is_palindrome(x, xr))
    return 0;

  double root = sqrt(x); double rootr = sqrt(xr);
  double floatpart = root - (int)root;
  double floatpartr = rootr - (int)rootr;
  if (floatpart != 0.0 || floatpartr != 0.0)
    return 0;

  return primes[(int)root] && primes[(int)rootr];
}

int main()
{
  primes = eratosthenes(TOP);

  int count = 0;
  ull sum = 0;

  for (ull i = 10; count != TARGET; ++i) {
    ull t = i*i;
    ull tr = reverse(t);
    if (are_reversible_square_primes(t, tr)) {
      sum += t;
      ++count;
    }
  }

  printf("%llu\n", sum);

  free(primes);
  return 0;
}
