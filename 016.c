// 1366
#include <stdio.h>
#include <gmp.h>

int main()
{
    mpz_t n, dummy;
    mpz_init(n);
    mpz_init(dummy);
    unsigned int sum = 0;

    mpz_ui_pow_ui(n, 2, 1000);
    while (mpz_sgn(n)) { // n != 0
        sum += mpz_mod_ui(dummy, n, 10);
        mpz_fdiv_q_ui(n, n, 10);
    }

    printf("%d\n", sum);

    mpz_clear(dummy);
    mpz_clear(n);
    return 0;
}
