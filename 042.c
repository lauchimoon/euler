// 162
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N_WORDS 1786
#define LINE_SZ 16346

int get_word_value(const char *word)
{
    int value = 0;
    size_t word_len = strlen(word);

    for (int i = 1; i < word_len - 1; i++) { // ignore quotes
        value += word[i] - 64;
    }

    return value;
}

int is_triangular(int n)
{
    double n0 = 2.0*n;
    int int_part = sqrt(n0);
    int_part *= (int_part + 1);

    return int_part/2 == n;
}

int main()
{
    char line[LINE_SZ] = { 0 };
    const char *words[N_WORDS] = {};
    char *tok = NULL;
    FILE *f = fopen("resources/0042_words.txt", "r");
    int n = 0;
    const char *delim = ",";

    fgets(line, LINE_SZ, f);
    tok = strtok(line, delim);

    // store words
    for (int i = 0; tok != NULL; i++) {
        words[i] = tok;
        tok = strtok(NULL, delim);
    }

    // count how many words are triangle words
    for (int i = 0; i < N_WORDS; i++) {
        int value = get_word_value(words[i]);
        n += is_triangular(value);
    }

    printf("%d\n", n);

    fclose(f);
    return 0;
}
