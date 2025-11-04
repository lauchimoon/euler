// 153
#include <stdio.h>
#include <gmp.h>

#define N_STEPS 1000

mpz_t den[N_STEPS];
mpz_t num[N_STEPS];

void init_den(void);
void init_num(void);
int ndigits(mpz_t x);
void deinit(void);

int main()
{
    init_den(); init_num();

    int total = 0;
    for (int step = 8; step < N_STEPS - 1; ++step) {
        mpz_t n; mpz_t d;
        mpz_init_set(n, num[step + 1]);
        mpz_init_set(d, den[step + 1]);

        int num_digits = ndigits(n);
        int den_digits = ndigits(d);

        total += (num_digits > den_digits);
        mpz_clear(n); mpz_clear(d);
    }

    printf("%d\n", total);
    deinit();
    return 0;
}

void init_den(void)
{
    for (int i = 0; i < N_STEPS; ++i)
        mpz_init_set_ui(den[i], 0);

    // https://oeis.org/A000129
    mpz_set_ui(den[0], 0);
    mpz_set_ui(den[1], 1);
    for (int i = 2; i < N_STEPS; ++i) {
        mpz_addmul_ui(den[i], den[i - 1], 2);
        mpz_add(den[i], den[i], den[i - 2]);
    }
}

void init_num(void)
{
    // https://oeis.org/A001333
    mpz_init_set_ui(num[0], 1);
    for (int i = 1; i < N_STEPS; ++i) {
        mpz_init_set_ui(num[i], 0);
        mpz_add(num[i], den[i], den[i - 1]);
    }
}

int ndigits(mpz_t x)
{
    int n = 0;
    while (mpz_sgn(x) != 0) {
        ++n;
        mpz_div_ui(x, x, 10);
    }

    return n;
}

void deinit(void)
{
    for (int i = 0; i < N_STEPS; ++i) {
        mpz_clear(num[i]);
        mpz_clear(den[i]);
    }
}
