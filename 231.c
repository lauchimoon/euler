// 7526965179680
#include <stdio.h>

#define EULER_COMMON_IMPLEMENTATION
#include "common.h"

int legendre(int x, int p)
{
    int sum = 0;
    int L = floor(log(x)/log(p));
    for (int i = 1; i <= L; ++i) {
        sum += floor(x/(int)pow(p, i));
    }

    return sum;
}

int main()
{
    int n = 20000000;
    int r = 15000000;
    Bool *primes = eratosthenes(n);

    long long int sum = 0;
    for (int p = 2; p < n; ++p) {
        if (primes[p]) {
            long long int exponent = legendre(n, p) - legendre(r, p) - legendre(n - r, p);
            sum += exponent*p;
        }
    }

    free(primes);
    printf("%lld\n", sum);
    return 0;
}
