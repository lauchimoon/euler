// 840
#include <stdio.h>

int triangle_solutions(int perimeter)
{
    int count = 0;

    for (int a = 1; a <= perimeter/2; ++a) {
        for (int b = a; b <= perimeter; ++b) {
            int c = perimeter - a - b;
            if (a + b + c == perimeter && a*a + b*b == c*c) {
                ++count;
            }
        }
    }

    return count;
}

int main()
{
    int max_p = 0;
    int max_count = 0;
    for (int p = 10; p <= 1000; ++p) {
        int count = triangle_solutions(p);
        if (count > max_count) {
            max_count = count;
            max_p = p;
        }
    }

    printf("%d\n", max_p);
    return 0;
}
