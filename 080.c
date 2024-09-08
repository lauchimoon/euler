// 40886
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int digit_sum(mpf_t x)
{
    int sum = 0;

    long int exp = 1;
    char *x_string = mpf_get_str(NULL, &exp, 10, 102, x);

    for (int i = 0; i < 100; ++i) {
        sum += x_string[i] - '0';
    }

    free(x_string);
    return sum;
}

int main()
{
    mpf_t sq;
    mpf_set_default_prec(10000);
    int sum = 0;

    for (int i = 2; i < 100; ++i) {
        mpf_init(sq);
        int is_perfect_square =
            i == 4 || i == 9 || i == 16 ||
            i == 25 || i == 36 || i == 49 ||
            i == 64 || i == 81 || i == 100;

        if (!is_perfect_square) {
            mpf_sqrt_ui(sq, i);
            sum += digit_sum(sq);
        }

        mpf_clear(sq);
    }

    printf("%d\n", sum);
    return 0;
}
