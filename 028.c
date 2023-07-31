// 669171001
#include <stdio.h>

#define square(x) (x)*(x)

int main()
{
    int sum = 0;

    for (int i = 1; i <= 500; i++) {
        sum += 4*square(2*i + 1) - 12*i;
    }

    sum++;
    printf("%d\n", sum);

    return 0;
}
