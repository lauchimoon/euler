#include <stdio.h>
#include <math.h>

#define TOP 10000

// Recommended reading:
// https://web.math.princeton.edu/mathlab/jr02fall/Periodicity/mariusjp.pdf

int periodlen(int n);
int is_perfect_square(int n);

int main()
{
    int total = 0;
    for (int n = 2; n <= TOP; ++n)
        total += (!is_perfect_square(n) && periodlen(n) % 2 != 0);

    printf("%d\n", total);
    return 0;
}

int periodlen(int n)
{
    int result = 0;
    int a0 = sqrt(n);
    int b1 = a0;
    int c1 = n - a0*a0;

    int a = a0, b = b1, c = c1;
    do {
        a = (a0 + b)/c;
        b = a*c - b;
        c = (n - b*b)/c;
        ++result;
    } while ((b != b1) || (c != c1));

    return result;
}

int is_perfect_square(int n)
{
    double x = sqrt(n);
    double float_part = x - (int)x;
    return float_part == 0.0;
}
