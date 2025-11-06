// 510510
#include <stdio.h>
#include <stdlib.h>
#define EULER_COMMON_IMPLEMENTATION
#include "common.h"

#define TOP 1000000

int main()
{
    int result = 1;
    Bool *primes = eratosthenes(TOP);

    for (int i = 1; ; i++)
        if (primes[i]) {
            if (result*i > TOP)
                break;
            result *= i;
        }

    free(primes);
    printf("%d\n", result);
    return 0;
}
