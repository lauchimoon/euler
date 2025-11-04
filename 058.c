// 26241
#include <stdio.h>
#include <math.h>

#define TOP 100000

int topleft(int n);
int topright(int n);
int bottomleft(int n);
int is_prime(int n);

int main()
{
    int total_prime = 0;
    int ndiag = 1;
    int sidelen = 1;

    for (int n = 1; n < TOP; ++n) {
        sidelen += 2;
        int tl = topleft(n);
        int tr = topright(n + 1);
        int bl = bottomleft(n + 1);

        total_prime += is_prime(tl);
        total_prime += is_prime(tr);
        total_prime += is_prime(bl);

        ndiag += 4;
        double ratio = (total_prime*10)/(double)ndiag;
        if (ratio < 1)
            break;
    }

    printf("%d\n", sidelen);

    return 0;
}

int topleft(int n)
{
    return 4*n*n + 1;
}

int topright(int n)
{
    return 4*n*n - 10*n + 7;
}

int bottomleft(int n)
{
    return 4*n*n - 6*n + 3;
}

int is_prime(int n)
{
    int top = sqrt(n);
    for (int i = 2; i < top; ++i)
        if (n % i == 0)
            return 0;

    return 1;
}
