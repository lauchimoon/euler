// 5777
#include <stdio.h>
#include <math.h>

#define EULER_COMMON_IMPLEMENTATION
#include "common.h"

Bool is_integer(float n)
{
    int int_part = (int)n;
    float float_part = n - int_part;
    return float_part == 0.0f;
}

int main()
{
    int top = 5785;
    int x = 0;
    Bool indicator = 1;
    Bool *primes = eratosthenes(top);
    for (int i = 3; i < top; i += 2) {
        indicator = 0;
        if (!primes[i]) {
            for (int p = 2; p < i; ++p) {
                if (primes[p]) {
                    float n = sqrt((i - p)/2);
                    if (is_integer(n) && i == p + 2*n*n) {
                        indicator = 1;
                        break;
                    }
                }
            }
            if (!indicator) x = i;
        }
    }

    free(primes);
    printf("%d\n", x);
    return 0;
}
