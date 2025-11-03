// 129448
#include <stdio.h>
#include <stdlib.h>

#define EULER_COMMON_IMPLEMENTATION
#include "common.h"

#define FILEPATH "./resources/0059_cipher.txt"
#define N_CODES 1455
#define BUFSIZE 4096

unsigned char *load_codes(void);
int isvalid(unsigned char *bytes);
int digit(unsigned char c);
int alpha(unsigned char c);
int punct(unsigned char c);
int space(unsigned char c);
int calculate_sum(unsigned char *bytes);

int main()
{
    int codes_len = 0;
    unsigned char *codes = load_codes();
    if (!codes)
        return 1;

    for (unsigned char i = 'a'; i <= 'z'; ++i)
        for (unsigned char j = 'a'; j <= 'z'; ++j)
            for (unsigned char k = 'a'; k <= 'z'; ++k) {
                unsigned char key[3] = { i, j, k };

                unsigned char bytes[N_CODES] = { 0 };
                for (int s = 0; s < N_CODES; ++s)
                    bytes[s] = codes[s] ^ key[s % 3];

                if (!isvalid(bytes))
                    continue;

                printf("%d\n", calculate_sum(bytes));
                free(codes);
                return 0;
            }

    return 0;
}

unsigned char *load_codes(void)
{
    char buffer[BUFSIZE] = { 0 };
    FILE *f = fopen(FILEPATH, "r");
    if (!f)
        return NULL;

    fgets(buffer, BUFSIZE, f);

    char **codes_str = split(buffer, ",", NULL);
    if (!codes_str) {
        fclose(f);
        return NULL;
    }

    unsigned char *codes = malloc(sizeof(unsigned char)*N_CODES);
    if (!codes) {
        free(codes_str);
        fclose(f);
        return NULL;
    }

    for (int i = 0; i < N_CODES; ++i)
        codes[i] = atoi(codes_str[i]);

    free(codes_str);
    return codes;
}

int isvalid(unsigned char *bytes)
{
    int valid = 1;
    for (int i = 0; i < N_CODES; ++i) {
        valid = digit(bytes[i]);
        valid |= alpha(bytes[i]);
        valid |= punct(bytes[i]);
        valid |= space(bytes[i]);

        if (!valid)
            return 0;
    }

    return 1;
}

int digit(unsigned char c)
{
    return c >= '0' && c <= '9';
}

int alpha(unsigned char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int punct(unsigned char c)
{
    // .,:;+?!/[]()'"
    return c == '.' || c == ',' || c == ':' || c == ';' ||
           c == '+' || c == '?' || c == '!' || c == '/' ||
           c == '[' || c == ']' || c == '(' || c == ')' || c == '\'' || c == '"';
}

int space(unsigned char c)
{
    return c == ' ';
}

int calculate_sum(unsigned char *bytes)
{
    int s = 0;
    for (int i = 0; i < N_CODES; ++i)
        s += bytes[i];

    return s;
}
