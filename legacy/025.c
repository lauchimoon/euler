// 4782
#include <stdio.h>
#include <gmp.h>

int ndigits(mpz_t n)
{
    int dig = 0;
    mpz_t n0;
    mpz_init(n0);
    mpz_set(n0, n);

    while (mpz_sgn(n0)) {
        dig++;
        mpz_fdiv_q_ui(n0, n0, 10);
    }

    mpz_clear(n0);
    return dig;
}

int main()
{
    mpz_t first, second, next;
    mpz_init_set_str(first, "1", 10);
    mpz_init_set_str(second, "1", 10);
    mpz_init(next);

    int limit = 1000;
    int i = 2;
    int dig = 1;

    while (dig < limit) {
        i++;
        mpz_add(next, first, second);
        mpz_set(first, second);
        mpz_set(second, next);
        dig = ndigits(next);
    }

    printf("%d\n", i);

    mpz_clear(next);
    mpz_clear(second);
    mpz_clear(first);
    return 0;
}
