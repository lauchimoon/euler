#include <stdio.h>
#include <gmp.h>

#define TOP 1000

void f(mpz_t result, long a, long n);

int main()
{
    mpz_t sum, r_max, r;
    for (long a = 3; a <= TOP; ++a) {
        mpz_init_set_si(r_max, -1);
        for (long n = 1; n <= 2*a; ++n) {
            mpz_init_set_ui(r, 0);
            f(r, a, n);
            if (mpz_cmp(r, r_max) > 0)
                mpz_set(r_max, r);

            mpz_clear(r);
        }
        mpz_add(sum, sum, r_max);
        mpz_clear(r_max);
    }

    gmp_printf("%Zd\n", sum);
    return 0;
}

void f(mpz_t result, long a, long n)
{
    mpz_t lop, rop;
    mpz_init_set_ui(lop, a-1); mpz_pow_ui(lop, lop, n);
    mpz_init_set_ui(rop, a+1); mpz_pow_ui(rop, rop, n);
    mpz_add(result, lop, rop);
    mpz_mod_ui(result, result, a*a);
}
