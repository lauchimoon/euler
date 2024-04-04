// 872187
#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 20

int is_palindrome_n(int n)
{
    int reverse = 0;
    int n0 = n;
    while (n0 != 0) {
        reverse = (reverse*10) + (n0%10);
        n0 /= 10;
    }

    return reverse == n;
}

int is_palindrome_s(char *s)
{
    int slen = strlen(s);
    for (int i = 0; i < slen; ++i)
        if (s[i] != s[slen - i - 1])
            return 0;

    return 1;
}

void binary(int n, char *buffer)
{
    int idx = 0;
    int n0 = n;

    while (n0 != 0) {
        const int quot = n0 / 2;
        const int rem = n0 % 2;
        n0 = quot;
        buffer[idx++] = rem + '0';
    }
}

int main()
{
    char buffer[MAX_STR_SIZE] = { 0 };
    int sum = 0;

    for (int i = 0; i < 1000000; ++i) {
        memset(buffer, 0, MAX_STR_SIZE);
        binary(i, buffer);

        if (is_palindrome_n(i) && is_palindrome_s(buffer))
            sum += i;
    }
    printf("%d\n", sum);

    return 0;
}
