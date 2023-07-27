// 142913828922
#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    for (int i = 2; i < sqrt(n) + 1; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    long long int sum = 2;
    int limit = 2000000;

    for (int i = 2; ; i++) {
        if (is_prime(i)) {
            if (i > limit) {
                break;
            }

            sum += i;
        }
    }

    printf("%ld\n", sum);
    return 0;
}
