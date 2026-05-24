#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EULER_COMMON_IMPLEMENTATION
#include "common.h"

#define N 5

int min(int a, int b)
{
    return (a < b)? a : b;
}

int min_sum(int **m, int n)
{
    for (int i = 1; i < n; ++i)
        m[0][i] += m[0][i-1];

    for (int i = 1; i < n; ++i)
        m[i][0] += m[i-1][0];

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            m[i][j] += min(m[i-1][j], m[i][j-1]);

    return m[n-1][n-1];
}

void load_matrix(int **m, FILE *f)
{
#define BUFFSIZE 2048
    char line[BUFFSIZE] = { 0 };
    int i = 0;
    while (fgets(line, BUFFSIZE, f) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        int len = 0;
        char **nums = split(line, ",", &len);
        for (int j = 0; j < len; ++j)
            m[i][j] = atoi(nums[j]);
        ++i;
    }
}

int main()
{
    FILE *f = fopen("./resources/0081_matrix.txt", "r");
    int n = n_lines(f);
    rewind(f);
    int **m = malloc(sizeof(int *)*n);
    for (int i = 0; i < n; ++i)
        m[i] = malloc(sizeof(int)*n);
    load_matrix(m, f);
    printf("%d\n", min_sum(m, n));
    fclose(f);
    return 0;
}
