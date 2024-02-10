// 4613732
#include <stdio.h>

int main()
{
    int first = 1;
    int second = 2;
    int total = 2;

    while (total < 4000000) {
        int next = first + second;
        first = second;
        second = next;
        total += next*(next % 2 == 0);
    }

    printf("%d\n", total);
    return 0;
}
