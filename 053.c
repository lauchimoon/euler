// 4075
#include <stdio.h>
#include <gmp.h>

void factorial(mpz_t r, int n)
{
    if (n == 0) {
        mpz_set_ui(r, 1);
        return;
    }

    for (int i = 1; i <= n; i++) {
        mpz_mul_ui(r, r, i);
    }
}

void C(mpz_t r, int n, int k)
{
    mpz_t nf, kf, nmk, denom;
    mpz_init_set_ui(nf, 1);
    mpz_init_set_ui(kf, 1);
    mpz_init_set_ui(nmk, 1);
    mpz_init_set_ui(denom, 1);

    factorial(nf, n);
    factorial(kf, k);
    factorial(nmk, n - k);

    mpz_mul(denom, kf, nmk);
    mpz_fdiv_q(r, nf, denom);

    mpz_clear(denom);
    mpz_clear(nmk);
    mpz_clear(kf);
    mpz_clear(nf);
}

int main()
{
    mpz_t v;
    int millions = 0;
    for (int n = 1; n <= 100; ++n) {
        for (int r = 1; r <= n; ++r) {
            mpz_init(v);
            C(v, n, r);
            if (mpz_cmp_ui(v, 1000000) >= 0)
                ++millions;
        }
    }

    printf("%d\n", millions);
    return 0;
}
