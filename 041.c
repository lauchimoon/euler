// 7652413
#include <stdio.h>

int is_prime(int n)
{
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int is_pandigital(long int n)
{
    int digits[10] = { 0 };
    int ndig = 0;

    do {
        digits[n%10]++;
        ndig++;
        n /= 10;
    } while (n != 0);

    for (int i = ndig - 1; i > 0; i--) {
        if (digits[i] != 1) return 0;
    }

    return 1;
}

int main()
{
    int max = 0;
    long int limit = 192384576;

    for (int i = 2; i <= limit; i++) {
        if (is_pandigital(i) && is_prime(i)) {
            if (max < i) max = i;
        }
    }

    printf("%d\n", max);

    return 0;
}
