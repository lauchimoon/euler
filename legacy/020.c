// 648
#include <stdio.h>
#include <gmp.h>

int main()
{
    int sum = 0;
    mpz_t hundred, dummy;
    mpz_init(dummy);
    mpz_init_set_str(hundred, "1", 10);

    // compute 100!
    for (int i = 1; i <= 100; i++) {
        mpz_mul_ui(hundred, hundred, i);
    }

    // sum digits
    while (mpz_sgn(hundred)) {
        sum += mpz_mod_ui(dummy, hundred, 10);
        mpz_fdiv_q_ui(hundred, hundred, 10);
    }

    printf("%d\n", sum);

    mpz_clear(hundred);
    mpz_clear(dummy);
    return 0;
}
