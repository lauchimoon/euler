// 748317
#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    if (n < 2) {
        return 0;
    }

    int top = sqrt(n);
    for (int i = 2; i <= top; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

inline int ndigits(int n)
{
    return log10(n) + 1;
}

int trunc_rl(int n)
{
    while (is_prime(n)) {
        n /= 10;
    }

    return n == 0;
}

int trunc_lr(int n)
{
    int ndig = ndigits(n) + 1;
    while (is_prime(n%(int)pow(10, ndig))) {
        --ndig;
    }

    return ndig == 0;
}

int trunc_both(int n)
{
    return trunc_lr(n) && trunc_rl(n);
}

int main()
{
    int sum = 0;
    for (int i = 23; i <= 1000000; ++i) {
        sum += trunc_both(i)? i : 0;
    }

    printf("%d\n", sum);
    return 0;
}
