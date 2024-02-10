// 31626
#include <stdio.h>
#include <math.h>
#include <time.h>

int d(int n)
{
    int sum = 0;
    int limit = sqrt(n);

    for (int i = 1; i < limit; i++) {
        if (n % i == 0) {
            sum += i + n/i; // TODO: why?
        }
    }

    return sum - n;
}

int are_amicable(int a, int b)
{
    return (d(a) == b && d(b) == a);
}

int main()
{
    int limit = 10000;
    int sum = 0;

    for (int i = 1; i < limit; i++) {
        for (int j = 1; j < limit; j++) {
            if (i != j && are_amicable(i, j)) {
                sum += (i + j);
            }
        }
    }

    sum /= 2; // subtract second pair added
    printf("%d\n", sum);

    return 0;
}
