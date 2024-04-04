// 9183
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#define N_NUMS 10000 // upper bound determined by 100*100

int cmp(const void *a, const void *b)
{
    return mpz_cmp(*(const mpz_t *)a, *(const mpz_t *)b);
}

int main()
{
    int lower = 2;
    int upper = 100;
    int nterms = 0;
    int ndups = 0;
    mpz_t powers[N_NUMS] = { 0 };

    for (int a = lower; a <= upper; a++) {
        for (int b = lower; b <= upper; b++) {
            mpz_ui_pow_ui(powers[nterms], a, b);
            nterms++;
        }
    }

    qsort(powers, nterms, sizeof(mpz_t), cmp);

    // check duplicates
    for (int i = 0; i < nterms - 1; i++) {
        if (mpz_cmp(powers[i], powers[i + 1]) == 0) {
            ndups++;
        }
    }

    printf("%d\n", nterms - ndups);

    return 0;
}
