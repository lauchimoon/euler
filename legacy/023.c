// 4179871
#include <stdio.h>

//#define LIMIT_TEST 100
#define LIMIT 28123

int sum_div(int n)
{
    int sum = 0;
    for (int i = 1; i <= n/2; i++) {
        sum += i*(n % i == 0);
    }
    return sum;
}

int is_abundant(int n)
{
    return sum_div(n) > n;
}

int main()
{
    int nums[LIMIT] = { 0 };
    int total = 0;
    int l = 0;
    for (int i = 1; i < LIMIT; i++) {
        nums[l++] += sum_div(i)*is_abundant(i);
    }

    for (int i = 0; i < l; i++) {
        for (int j = i; j < l; j++) {
            int sum_ab = nums[i] + nums[j];
            if (sum_ab <= 28123) {
                total += sum_ab;
            }
        }
    }

    printf("%d\n", total);
    // n > 28123 => ab1 + ab2
    // max(n) != ab1 + ab2 < 28123
    return 0;
}
