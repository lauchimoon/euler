// 228
#include <stdio.h>
#include <math.h>
#include <string.h>

double area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return fabs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))/2.0);
}

int contains_origin(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int x = 0, y = 0;
    double A = area(x1, y1, x2, y2, x3, y3);
    double A1 = area(x, y, x2, y2, x3, y3);
    double A2 = area(x1, y1, x, y, x3, y3);
    double A3 = area(x1, y1, x2, y2, x, y);
    return A == A1 + A2 + A3;
}

int main()
{
    FILE *f = fopen("./resources/0102_triangles.txt", "r");
    char line[1024] = { 0 };
    int answer = 0;
    while (fgets(line, 1024, f) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        int x1, y1, x2, y2, x3, y3;
        sscanf(line, "%d,%d,%d,%d,%d,%d", &x1, &y1, &x2, &y2, &x3, &y3);
        answer += contains_origin(x1, y1, x2, y2, x3, y3);
    }
    printf("%d\n", answer);
    fclose(f);
    return 0;
}
