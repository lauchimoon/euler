// 55
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n)
{
    int m = 2;
    while (n) {
        if (n % m == 0)
            break;

        ++m;
    }

    return m == n;
}

int *digits(int n, int *ndig)
{
    int ndigits = 0;
    int n0 = n;
    while (n0) {
        ++ndigits;
        n0 /= 10;
    }

    int *dig = malloc(ndigits*sizeof(int));
    int idx = ndigits - 1;
    n0 = n;
    while (n0) {
        dig[idx] = n0 % 10;
        --idx;
        n0 /= 10;
    }

    *ndig = ndigits;
    return dig;
}

int number_join(int *n, int ndigits)
{
    int k = 0;
    int dig = ndigits;
    for (int i = 0; i < ndigits; ++i) {
        k += pow(10, dig - 1)*n[i];
        --dig;
    }

    return k;
}

void rotate(int *n, int ndigits)
{
    int save = n[0];
    for (int i = 0; i < ndigits - 1; ++i) {
        n[i] = n[i + 1];
    }

    n[ndigits - 1] = save;
}

int is_circular_prime(int n)
{
    if (!is_prime(n))
        return 0;

    int ndig = 0;
    int *d = digits(n, &ndig);
    int k = number_join(d, ndig);
    rotate(d, ndig);

    while ((k = number_join(d, ndig)) != n) {
        rotate(d, ndig);
        if (!is_prime(k))
            return 0;
    }

    free(d);
    return 1;
}

int main()
{
    int count = 0;
    for (int i = 2; i < 1000000; ++i)
        count += is_circular_prime(i);

    printf("%d\n", count);

    return 0;
}
