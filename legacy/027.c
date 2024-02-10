// -59231
#include <stdio.h>

#define LIMIT 1000

int is_prime(int n)
{
    if (n < 0) {
        n *= -1;
    }

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }

    return 1;
}

int main()
{
    int j = 0;
    int consecutive = 0;
    int prod = 0;

    for (int a = -LIMIT + 1; a < LIMIT; a++) {
        for (int b = -LIMIT; b <= LIMIT; b++) {
            int n = 0;
            while (is_prime(n*n + a*n + b)) {
                n++;
            }

            if (consecutive < n) {
                consecutive = n;
                prod = a*b;
            }
        }
    }

    printf("%d\n", prod);

    return 0;
}
