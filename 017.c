// 21124
#include <stdio.h>

#define AND 3
#define ONETHOUSAND 11

int one_digit(int);
int two_digit(int);
int three_digit(int);
int compute_sum(void);

int main()
{
    printf("%d\n", compute_sum());
    return 0;
}

int one_digit(int n)
{
    int lens[9] = {
        3, 3, 5, 4, 4, 3, 5, 5, 4
    };
    return lens[n - 1];
}

int two_digit(int n)
{
    /* multiples of ten */
    int tens[9] = {
        3, 6, 6, 5, 5, 5, 7, 6, 6
    };

    /* eleven to nineteen */
    int unique[9] = {
        6, 6, 8, 8, 7, 7, 9, 8, 8
    };
    if (n % 10 == 0)
        return tens[n/10 - 1];
    else if (n >= 11 && n <= 19)
        return unique[n - 11];
    else {
        int d1 = n/10;
        int d2 = n%10;
        /* consider 01, 02... */
        if (d1 == 0)
            return one_digit(d2);

        return tens[d1 - 1] + one_digit(d2);
    }
}

int three_digit(int n)
{
    /* multiples of 100 */
    int hundreds[9] = {
        10, 10, 12, 11, 11, 10, 12, 12, 11
    };
    if (n % 100 == 0)
        return hundreds[n/100 - 1];
    else {
        int mul = n/100;
        int n2 = n%100;
        return hundreds[mul - 1] + AND + two_digit(n2);
    }
}

int compute_sum(void)
{
    int sum, i;

    for (sum = 0, i = 1; i < 1000; ++i) {
        if (i >= 1 && i <= 9)
            sum += one_digit(i);
        else if (i >= 10 && i <= 99)
            sum += two_digit(i);
        else if (i >= 100 && i <= 999)
            sum += three_digit(i);
    }
    sum += ONETHOUSAND;
    return sum;
}
