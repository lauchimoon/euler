// 1074
#include <stdio.h>

#define EULER_COMMON_IMPLEMENTATION
#include "common.h"

int max(int a, int b)
{
    return (a > b)? a : b;
}

int triangle_at(int *triangle, int x, int y, int width, int height)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
        return triangle[y*width + x];

    return -1;
}

int main()
{
    int width, height;
    int *triangle = load_triangle("./resources/0018_triangle.txt", &width, &height);

    int y = height - 2;
    int x = 0;
    while (y > 0) {
        for (int x = 0; x <= y; ++x) {
            triangle[y*width + x] = max(triangle_at(triangle, x, y, width, height) + triangle_at(triangle, x, y + 1, width, height),
                                        triangle_at(triangle, x, y, width, height) + triangle_at(triangle, x + 1, y + 1, width, height));
        }

        --y;
    }
    triangle[0] = max(triangle_at(triangle, 0, 0, width, height) + triangle_at(triangle, 0, 1, width, height),
                      triangle_at(triangle, 0, 0, width, height) + triangle_at(triangle, 1, 1, width, height));
    printf("%d\n", triangle[0]);

    return 0;
}
