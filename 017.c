// 21124
#include <stdio.h>
#include <string.h>

enum {
    ZERO = 0,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    ELEVEN,
    TWELVE,
    THIRTEEN,
    FOURTEEN,
    FIFTEEN,
    SIXTEEN,
    SEVENTEEN,
    EIGHTEEN,
    NINETEEN,
    TWENTY,
    THIRTY,
    FOURTY,
    FIFTY,
    SIXTY,
    SEVENTY,
    EIGHTY,
    NINETY,
    HUNDRED,
};

enum {
    AND = 0,
};

char *separators[] = {
    "and",
};

char *words[] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
    "hundred",
};

int ndigits(int n)
{
    if (n == 0) {
        return 1;
    }

    int dig = 0;
    while (n != 0) {
        n /= 10;
        dig++;
    }

    return dig;
}

void one_digit(int n, char *buf, size_t sz)
{
    strncpy(buf, words[n], sz);
}

void two_digits(int n, char *buf, size_t sz)
{
    int first = n/10;
    int second = n%10;

    if (n < 10) {
        one_digit(n, buf, sz);
        return;
    }

    if (first == 1) {
        strncpy(buf, words[n], sz);
    } else if (first == 2) {
        if (second == 0) {
            // twenty
            strncpy(buf, words[TWENTY], sz);
        } else {
            // twenty...
            char tbuf[256] = { 0 };
            one_digit(second, tbuf, sizeof(tbuf));
            strncpy(buf, words[TWENTY], sz);
            strncat(buf, tbuf, sz);
        }
    } else {
        int offset = THIRTY + first - 3;
        if (second == 0) {
            strncpy(buf, words[offset], sz);
        } else {
            char tbuf[256] = { 0 };
            strncpy(buf, words[offset], sz);
            one_digit(second, tbuf, sizeof(tbuf));
            strncat(buf, tbuf, sz);
        }
    }
}

void three_digits(int n, char *buf, size_t sz)
{
    if (n < 100) {
        two_digits(n, buf, sz);
        return;
    }

    int first = n/100;
    int last_two = n - first*100;

    one_digit(first, buf, sz);
    strncat(buf, words[HUNDRED], sz);

    // n != 100, 200, 300, ...?
    if (n % 100 != 0) {
        char tbuf[256] = { 0 };

        strncat(buf, separators[AND], sz);
        two_digits(last_two, tbuf, sizeof(tbuf));
        strncat(buf, tbuf, sz);
    }
}

void four_digits(int n, char *buf, size_t sz)
{
/*
    const char *thousands[] = {
        "", "mil", "dos mil", "tres mil", "cuatro mil", "cinco mil",
        "seis mil", "siete mil", "ocho mil", "nueve mil",
    };

    int first = n/1000;
    int last_three = n - first*1000;

    // n = 1000, 2000, 3000, ...?
    if (n % 1000 == 0) {
        strncpy(buf, thousands[first], sz);
    } else { // other four-digit numbers
        char tbuf[256] = { 0 };
        strncpy(buf, thousands[first], sz);
        strncat(buf, separators[ESPACIO], sz);
        three_digits(last_three, tbuf, sizeof(tbuf));
        strncat(buf, tbuf, sz);
    }
}
*/
    strncpy(buf, "onethousand", sz);
}

void num_to_word(int n, char *buf, size_t sz)
{
    int digits = ndigits(n);
    if (digits == 1) {
        one_digit(n, buf, sz);
    }
    if (digits == 2) {
        two_digits(n, buf, sz);
    }
    if (digits == 3) {
        three_digits(n, buf, sz);
    }
    if (digits == 4) {
        four_digits(n, buf, sz);
    }
}

void test(int n)
{
    char buf[256] = { 0 };
    num_to_word(n, buf, sizeof(buf));
    printf("%s %d\n", buf, strlen(buf));
}

int number_letter_counts(int a, int b)
{
    int sum = 0;
    char buf[512] = { 0 };

    for (int i = a; i <= b; i++) {
        num_to_word(i, buf, sizeof(buf));
        test(i);
        sum += strlen(buf);
    }

    return sum;
}

int main()
{
    int sum = number_letter_counts(1, 1000);
    printf("%d\n", sum);

    return 0;
}
