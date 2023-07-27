// 648
#include <stdio.h>

long long int factorial(long long int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n*factorial(n - 1);
}

int main()
{
    long long int n = factorial(21);
    printf("%lld\n", n);
    return 0;
}
