// 100
#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0) {
        return gcd(b, a%b);
    }

    return a;
}

int main()
{
    int den = 1, num = 1;
    for (int a = 1; a < 10; ++a) {
        for (int b = 1; b < 10; ++b) {
            for (int c = 1; c < 10; ++c) {
                if ((float)(a*10 + b)/(b*10 + c) == (float)a/c) {
                    num *= a;
                    den *= c;
                }
            }
        }
    }

    printf("%d\n", den/gcd(den, num));
    return 0;
}
