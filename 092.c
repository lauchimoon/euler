// 8581146
#include <stdio.h>

int sum_digits_sqr(int x)
{
    int sum = 0;
    while (x != 0) {
        int dig = x%10;
        sum += dig*dig;
        x /= 10;
    }

    return sum;
}

int main()
{
    int n_chains = 0;
    int starting = 1;
    int top = 10000000;
    int n = sum_digits_sqr(starting);
    while (starting <= top) {
        n = sum_digits_sqr(n);
        if (n == 1) {
            n = ++starting;
        }
        if (n == 89) {
            ++n_chains;
            n = ++starting;
        }
    }

    printf("%d\n", n_chains);
    return 0;
}
