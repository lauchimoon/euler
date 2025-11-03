#include <stdio.h>
#include <math.h>

double check(int ndig);

int main()
{
    double sum = 0;
    for (int ndig = 1; ndig <= 21; ++ndig)
        sum += check(ndig);

    printf("%g\n", sum);
    return 0;
}

double check(int ndig)
{
    double low = pow(10, ndig - 1);
    double top = pow(10, ndig) - 1;
    double total = 0;

    for (int base = 1; base <= 9; ++base) {
        double power = pow(base, ndig);
        total += (power >= low && power <= top);
    }

    return total;
}
