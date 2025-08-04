// 709
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EULER_COMMON_IMPLEMENTATION
#include "common.h"

#define BUFFER_SIZE 1024
#define N_COMPARISONS 1000

int main()
{
    FILE *f = fopen("resources/0099_base_exp.txt", "r");
    char buffer[BUFFER_SIZE] = {};
    int cmp_idx = 0;
    double x = 0.0;
    double powers[N_COMPARISONS] = {};

    while (fgets(buffer, BUFFER_SIZE, f) != NULL) {
        // trim newlines
        buffer[strcspn(buffer, "\n")] = 0;

        char **exp_base = split(buffer, ",", NULL);
        int base = atoi(exp_base[0]);
        int exp = atoi(exp_base[1]);

        x = exp*log10(base);
        powers[cmp_idx++] = x;
        free(exp_base);
    }

    int max_line = 0;
    double max = 0;
    for (int i = 0; i < N_COMPARISONS; ++i) {
        if (powers[i] > max) {
            max = powers[i];
            max_line = i + 1; // lines are counted from 1 to n
        }
    }

    printf("%d\n", max_line);
    fclose(f);
    return 0;
}
