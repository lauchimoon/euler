// 55374
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#define MILL 1000000

typedef unsigned long long int ull;

int p(ull n)
{
    mpz_t *part = malloc(sizeof(mpz_t)*(n + 1));
    for (int i = 0; i <= n; ++i)
        mpz_init(part[i]);

    mpz_init_set_ui(part[0], 1);

    int i;
    for (i = 1; i <= n; ++i) {
        for (int k = 1; ; ++k) {
            int p1 = k*(3*k - 1)/2;
            int p2 = k*(3*k + 1)/2;
            int sign = (k%2 == 0)? -1 : 1;

            if (p1 > i) break;
            if (sign > 0) mpz_add(part[i], part[i], part[i - p1]);
            else mpz_sub(part[i], part[i], part[i - p1]);

            if (p2 > i) continue;
            if (sign > 0) mpz_add(part[i], part[i], part[i - p2]);
            else mpz_sub(part[i], part[i], part[i - p2]);
        }

        mpz_mod_ui(part[i], part[i], MILL);
        if (mpz_cmp_ui(part[i], 0) == 0)
            break;
    }

    for (int j = 0; j <= n; ++j)
        mpz_clear(part[j]);
    free(part);

    return i;
}

int main()
{
#define TOP 60000
    int n = p(TOP);
    printf("%llu\n", n);
    return 0;
}
