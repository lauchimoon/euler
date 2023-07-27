// 104743
#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    int limit = sqrt(n) + 1;
    for (int i = 2; i < limit; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int idx = 0;
    int n = 0;
    for (int i = 2; idx < 10001; i++) {
        idx += is_prime(i);
        n = i*is_prime(i);
    }

    printf("%d\n", n);

    return 0;
}
