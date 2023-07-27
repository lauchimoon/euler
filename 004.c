// 906609
#include <stdio.h>

int is_palindrome(int n)
{
    int reverse = 0;
    int n0 = n;
    while (n0 != 0) {
        reverse = (reverse*10) + (n0%10);
        n0 /= 10;
    }

    return reverse == n;
}

int main()
{
    int largest = 999;
    int smallest = 100;
    int max = largest;

    for (int i = largest; i >= smallest; i--) {
        for (int j = i; j >= smallest; j--) {
            int mul = i*j;
            if (is_palindrome(mul) && mul > max) {
                max = mul;
            }
        }
    }

    printf("%d\n", max);

    return 0;
}
