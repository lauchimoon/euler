// 40730
#include <stdio.h>

long int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n*factorial(n-1);
}

int factorial_digits_sum(int n)
{
    int sum = 0;
    int n0 = n;
    while (n0 != 0) {
        sum += factorial(n0%10);
        n0 /= 10;
    }

    return sum;
}

int main()
{
    int sum = 0;
    int limit = factorial(9)*7;
    for (int i = 3; i < limit; i++) {
        int n = factorial_digits_sum(i);
        if (n == i) {
            sum += n;
        }
    }

    printf("%d\n", sum);
    return 0;
}
