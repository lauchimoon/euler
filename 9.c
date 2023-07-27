// 31875000
#include <stdio.h>

int main()
{
    int a, b, c;
    for (int a0 = 1; a0 < 1000; a0++) {
        for (int b0 = 1; b0 < 1000; b0++) {
            int c0 = 1000 - a0 - b0;
            if (a0*a0 + b0*b0 == c0*c0) {
                a = a0; b = b0; c = c0;
                break;
            }
        }
    }

    printf("%d\n", a*b*c);

    return 0;
}
