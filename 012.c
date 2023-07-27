// 76576500
#include <stdio.h>
#include <math.h>

int ndivisors(int n)
{
    if (n == 1) {
        return 1;
    }

    int ndiv = 0;
    int limit = sqrt(n);
    for (int i = 1; i <= limit; i++) {
        if (n % i == 0) {
            ndiv++;
            if (i != n/i) {
                ndiv++;
            }
        }
    }

    return ndiv;
}

int main()
{
    for (int i = 1; ; i++) {
        int tri = i*(i + 1)/2;
        int ndiv = ndivisors(tri);
        if (ndiv > 500) {
            printf("%d\n", tri);
            break;
        }
    }

    return 0;
}
