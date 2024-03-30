// 4179871
#include <stdio.h>

#define LIMIT 28124

int sum_divisors(int n)
{
    int sum = 0;
    for (int i = 1; i <= n/2; ++i) {
        sum += i*(n % i == 0);
    }

    return sum;
}

int is_abundant(int n)
{
    return sum_divisors(n) > n;
}

int main()
{
    int abundants[LIMIT] = { 0 };
    int abundants_len = 0;
    for (int i = 12; i < LIMIT; ++i) {
        if (is_abundant(i)) {
            abundants[abundants_len++] = i;
        }
    }

    int sums[LIMIT] = { 0 };
    for (int i = 0; i < abundants_len; ++i) {
        for (int j = 0; j < abundants_len; ++j) {
            int a1 = abundants[i];
            int a2 = abundants[j];
            if (a1 + a2 < LIMIT)
                sums[a1 + a2] = 1;
        }
    }

    int total = 0;
    for (int i = 0; i < LIMIT; i++)
        if (!sums[i])
            total += i;

    printf("%d\n", total);
    return 0;
}
