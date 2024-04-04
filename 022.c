// 871198282
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_NAMES 5163
#define LINE_SZ 46448 // file is 46447 bytes long

int cmp(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

void sort(const char *arr[], size_t n)
{
    qsort(arr, n, sizeof(const char *), cmp);
}

int get_score(const char *name, int pos)
{
    int sum = 0;
    size_t name_len = strlen(name);

    for (int i = 1; i < name_len - 1; i++) { // ignore quotes
        sum += name[i] - 64;
    }
    return (pos + 1)*sum;
}

int main()
{
    char line[LINE_SZ] = { 0 };
    const char *names[N_NAMES] = {};
    char *tok = NULL;
    FILE *f = fopen("resources/0022_names.txt", "r");
    int total_score = 0;
    const char *delim = ",";

    fgets(line, LINE_SZ, f);
    tok = strtok(line, delim);

    // store names
    for (int i = 0; tok != NULL; i++) {
        names[i] = tok;
        tok = strtok(NULL, delim);
    }

    // sort names
    sort(names, N_NAMES);

    // calculate score
    for (int i = 0; i < N_NAMES; i++) {
        total_score += get_score(names[i], i);
    }
    printf("%d\n", total_score);

    fclose(f);

    return 0;
}
