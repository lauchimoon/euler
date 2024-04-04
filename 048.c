// 9110846700
#include <stdio.h>
#include <gmp.h>

int main()
{
    mpz_t total, dummy;
    mpz_init(total);
    mpz_init(dummy);

    for (int i = 1; i <= 1000; i++) {
        mpz_ui_pow_ui(dummy, i, i);
        mpz_add(total, total, dummy);
    }

    char n[10] = { 0 };
    for (int i = 9; i >= 0; i--) {
        n[i] = mpz_mod_ui(dummy, total, 10) + '0';
        mpz_fdiv_q_ui(total, total, 10);
    }

    printf("%s\n", n);

    mpz_clear(dummy);
    mpz_clear(total);
    return 0;
}
