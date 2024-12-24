// 972
#include <gmp.h>
#include <stdio.h>

int digital_sum(mpz_t);

int main()
{
    int sum = 0, max = 0;
    for (int a = 1; a <= 100; ++a) {
        for (int b = 1; b <= 100; ++b) {
            mpz_t num;
            mpz_ui_pow_ui(num, a, b);
            sum = digital_sum(num);
            if (max < sum)
                max = sum;
        }
    }

    printf("%d\n", max);
    return 0;
}

int digital_sum(mpz_t src)
{
    int digit = 0;
    mpz_t dummy;
    mpz_init(dummy);
    while (mpz_sgn(src)) {
        digit += mpz_mod_ui(dummy, src, 10);
        mpz_div_ui(src, src, 10);
    }

    return digit;
}
