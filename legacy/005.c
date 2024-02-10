// 232792560
#include <stdio.h>

int main()
{
    for (int i = 1;; i++) {
        if (!(i % 11) && !(i % 12) && !(i % 13) && !(i % 14) && !(i % 15) &&
            !(i % 16) && !(i % 17) && !(i % 18) && !(i % 19) && !(i % 20)) {
            printf("%d\n", i);
            break;
        }

    }
    return 0;
}
