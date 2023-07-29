// 443839
#include <stdio.h>
#include <math.h>

int sum(int n)
{
    int s = 0;
    while (n != 0) {
        s += pow(n%10, 5);
        n /= 10;
    }

    return s;
}

int main()
{
    int limit = 1000000;
    int total = 0;
    for (int i = 10; i <= limit; i++) {
        int sum_digits = sum(i);
        if (sum_digits == i) {
            total += i;
        }
    }
    printf("%d\n", total);

    return 0;
}
