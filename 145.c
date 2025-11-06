// 608720
#include <stdio.h>
#include <math.h>

int count_reversible(int n);

int main()
{
    printf("%d\n", count_reversible(9));
    return 0;
}

int count_reversible(int n)
{
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        switch (i % 4) {
            case 0: case 2:
                total += 20*pow(30, (i/2 - 1));
                break;
            case 3:
                total += 100*pow(500, i/4);
                break;
            case 1:
                break;
        }
    }

    return total;
}
