// 997651
#include <stdio.h>

#define EULER_COMMON_IMPLEMENTATION
#include "common.h"

int main()
{
    int top = 1000000;
    long long int sum = 0, nterms = 0;
    int max_terms = 0, max_prime = 0;
    Bool *primes = eratosthenes(top);
    for (int i = 2; i < top; ++i) {
        sum = 0;
        nterms = 0;
        if (primes[i]) {
            for (int j = i; j < top; ++j) {
                if (primes[j]) {
                    sum += j;
                    ++nterms;
                    if (sum > top)
                        break;

                    if (nterms > max_terms && primes[sum]) {
                        max_terms = nterms;
                        max_prime = sum;
                    }
                }
            }
        }
    }

    free(primes);
    printf("%d\n", max_prime);
    return 0;
}
