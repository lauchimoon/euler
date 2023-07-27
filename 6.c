// 25164150
#include <stdio.h>

#define square(x) (x)*(x)

int main()
{
    const int n = 100;
    int square_sum = square(n*(n + 1)/2);
    int sum_square = n*(n + 1)*(2*n + 1)/6;
    printf("%d\n", square_sum - sum_square);
    return 0;
}
