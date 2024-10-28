// 4075
#include <stdio.h>
#include <gmp.h>

int main()
{
    mpz_t v;
    int millions = 0;
    for (int n = 1; n <= 100; ++n) {
        for (int r = 1; r <= n; ++r) {
            mpz_init(v);
            mpz_bin_uiui(v, n, r);
            if (mpz_cmp_ui(v, 1000000) >= 0)
                ++millions;
        }
    }

    printf("%d\n", millions);
    return 0;
}
