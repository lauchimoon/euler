// 1533776805
#include <stdio.h>
#include <math.h>

int is_pentagonal(long int x)
{
    // x is pentagonal if n is natural
    long double n = (sqrt(24*x + 1) + 1)/6;

    long int int_part = (long int)n;
    long double float_part = n - int_part;
    return float_part == 0;
}

int main()
{
    int m = 144;
    int hexa = 2*m*m - m;
    while (!is_pentagonal(hexa)) {
        ++m;
        hexa = 2*m*m - m;
    }

    printf("%d\n", hexa);
    return 0;
}
