// 249
#include <stdio.h>

#define MAX_ITERATIONS 50
#define N 10000

long int reverse(long int);
int palindrome(long int);

int main()
{
    long int i, it;
    int n_lychrel = 0;

    for (i = 1; i < N; ++i) {
        long int n = i + reverse(i);
        it = 1;
        while (!palindrome(n) && it <= MAX_ITERATIONS) {
            ++it;
            n = n + reverse(n);
        }
        if (it > MAX_ITERATIONS)
            ++n_lychrel;
    }
    printf("%d\n", n_lychrel);
    return 0;
}

long int reverse(long int n)
{
    long int rev;
    rev = 0;

    while (n > 0) {
        rev = rev*10 + n%10;
        n /= 10;
    }

    return rev;
}

int palindrome(long int n)
{
    return n == reverse(n);
}
