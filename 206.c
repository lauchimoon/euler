// 1389019170
#include <stdio.h>
#include <math.h>

int has_form(long int x)
{
    int pows[10] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18 };
    int digits[10] = {};
    for (int i = 0; i < 10; ++i) {
        digits[i] = x/(long long int)pow(10, pows[i]) % 10;
    }

    return digits[0] == 0 && digits[1] == 9 && digits[2] == 8
        && digits[3] == 7 && digits[4] == 6 && digits[5] == 5
        && digits[6] == 4 && digits[7] == 3 && digits[8] == 2
        && digits[9] == 1;
}

int main()
{
    long int lowest = 1020304050607080900;
    long int highest = 1929394959697989999;
    long int bottom = sqrt(lowest);
    long int top = sqrt(highest);

    long int x = bottom;
    while (x <= top && !has_form(x*x)) {
        x += 10;
    }

    printf("%ld\n", x);

    return 0;
}
