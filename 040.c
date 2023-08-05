// 210
#include <stdio.h>
#include <string.h>

int main()
{
    int n = 1;
    int limit = 200000;
    char s[1100000] = { 0 };

    for (int i = 1; i <= limit; i++) {
        char tmp[7] = { 0 };
        sprintf(tmp, "%d", i);
        strcat(s, tmp);
    }

    for (int i = 1; i < 1000000; i *= 10) {
        n *= s[i - 1] - '0';
    }

    printf("%d\n", n);
    return 0;
}
