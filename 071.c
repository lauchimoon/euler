// 428570
#include <stdio.h>

#define TOP 1000000

int main()
{
    int d;
    for (d = TOP; d >= 1; --d)
        if ((3*d%7) == 1)
            break;

    int n = (3*d - 1)/7;
    printf("%d\n", n);
    return 0;
}
