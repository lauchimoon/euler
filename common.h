#ifndef EULER_COMMON_H
#define EULER_COMMON_H

#include <stdio.h>
typedef char Bool; // Very dumb

char **split(const char *text, char *delimiter, int *len);
size_t n_lines(FILE *f);
int *load_triangle(const char *pathname, int *width, int *height);
Bool *eratosthenes(unsigned int n);

#ifdef EULER_COMMON_IMPLEMENTATION

#ifndef __cplusplus
#include <math.h>
#include <stdlib.h>
#include <string.h>

char **split(const char *text, char *delimiter, int *len)
{
    unsigned int result_size = 1;
    unsigned int result_used = 0;
    char **result = malloc(result_size*sizeof(char *));
    char *text_cloned = strdup(text);
    char *token = 0;

    // TODO: strsep is not standard.
    while ((token = strsep(&text_cloned, delimiter)) != NULL) {
        if (result_used == result_size) {
            result_size *= 2;
            result = realloc(result, result_size*sizeof(char *));
        }
        result[result_used++] = token;
    }
    free(text_cloned);

    if (len)
        *len = result_used;

    return result;
}

size_t n_lines(FILE *f)
{
    size_t l = 0;
    char c;

    while ((c = fgetc(f)) != EOF)
        if (c == '\n')
            ++l;

    return l;
}

int *load_triangle(const char *pathname, int *width, int *height)
{
    FILE *f = fopen(pathname, "r");
    size_t rows = n_lines(f);
    size_t cols = rows;
    fseek(f, 0L, SEEK_SET);
    int *triangle = malloc(rows*cols*sizeof(int));
    int y = 0;

#define BUFFER_SIZE 1024
    char line[BUFFER_SIZE] = { 0 };
    int idx = 0;
    while (fgets(line, BUFFER_SIZE, f) != NULL) {
        line[strcspn(line, "\n")] = 0;
        char **nums = split(line, " ", NULL);
        char *n = nums[idx];
        n[strcspn(n, "\n")] = 0;

        for (int x = 0; x < cols; ++x) {
            triangle[y*rows + x] = (x <= y)? atoi(n) : 0;
            ++idx;
            n = nums[idx]? nums[idx] : "0";
        }

        idx = 0;
        free(nums);
        ++y;
    }

    *width = cols;
    *height = rows;

    fclose(f);
    return triangle;
}

Bool *eratosthenes(unsigned int n)
{
    Bool *primes = calloc(n, sizeof(Bool));
    memset(primes, 1, n);
    primes[0] = 0;
    primes[1] = 0;
    int top = sqrt(n);
    for (int i = 2; i <= top; ++i) {
        if (primes[i]) {
            for (int j = i*i; j <= n; j += i) {
                primes[j] = 0;
            }
        }
    }

    return primes;
}

#endif
#endif // EULER_COMMON_IMPLEMENTATION

#endif // EULER_COMMON_H
