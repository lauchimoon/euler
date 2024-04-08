// 5482660
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nth_pentagonal(int n)
{
    return n*(3*n - 1)/2;
}

int is_pentagonal(int n)
{
    double k = sqrt(24*n + 1) + 1;
    if ((int)k - k == 0)
        return (int)k % 6 == 0;

    return 0;
}

int main()
{
    int min = 0;
    int bound = 1363; // TODO: why up to here?!
    for (int j = 1; j < bound; ++j) {
        for (int k = 1; k < bound; ++k) {
            int sum_pent = nth_pentagonal(k) + nth_pentagonal(j);
            int dif_pent = nth_pentagonal(k) + nth_pentagonal(j);
            if (is_pentagonal(sum_pent) && is_pentagonal(dif_pent)) {
                int D = abs(dif_pent);
                if (D > min) {
                    min = D;
                }
            }
        }
    }

    printf("%d\n", min);

    return 0;
}
