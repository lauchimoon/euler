// 837799
#include <stdio.h>

int collatz_count(long int n)
{
    int i = 1;
    long int n0 = n;

    while (n0 != 1) {
        if (n0 % 2 == 0) {
            n0 /= 2;
        } else {
            n0 *= 3;
            n0++;
        }

        i++;
    }

    return i;
}

int main()
{
    const int one_million = 1000000;
    int max = 1;
    int starting = 0;

    for (int i = 1; i < one_million; i++) {
        if (collatz_count(i) > max) {
            starting = i;
            max = collatz_count(i);
        }
    }

    printf("%d\n", starting);

    return 0;
}
