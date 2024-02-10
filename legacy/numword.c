#include <stdio.h>
#include <string.h>

enum {
    CERO = 0,
    UNO,
    DOS,
    TRES,
    CUATRO,
    CINCO,
    SEIS,
    SIETE,
    OCHO,
    NUEVE,
    DIEZ,
    ONCE,
    DOCE,
    TRECE,
    CATORCE,
    QUINCE,
    DIECISEIS,
    DIECISIETE,
    DIECIOCHO,
    DIECINUEVE,
    VEINTE,
    VEINTI,
    TREINTA,
    CUARENTA,
    CINCUENTA,
    SESENTA,
    SETENTA,
    OCHENTA,
    NOVENTA,
    CIENTO,
    CIEN,
    DOSCIENTOS,
    TRESCIENTOS,
    CUATROCIENTOS,
    QUINIENTOS,
    SEISCIENTOS,
    SETECIENTOS,
    OCHOCIENTOS,
    NOVECIENTOS,
};

enum {
    ESPACIO = 0,
    Y,
};

char *separators[] = {
    " ",
    " y ",
};

char *words[] = {
    "cero",
    "uno",
    "dos",
    "tres",
    "cuatro",
    "cinco",
    "seis",
    "siete",
    "ocho",
    "nueve",
    "diez",
    "once",
    "doce",
    "trece",
    "catorce",
    "quince",
    "dieciseis",
    "diecisiete",
    "dieciocho",
    "diecinueve",
    "veinte",
    "veinti",
    "treinta",
    "cuarenta",
    "cincuenta",
    "sesenta",
    "setenta",
    "ochenta",
    "noventa",
    "ciento",
    "cien",
    "doscientos",
    "trescientos",
    "cuatrocientos",
    "quinientos",
    "seiscientos",
    "setecientos",
    "ochocientos",
    "novecientos",
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
            // veinte
            strncpy(buf, words[VEINTE], sz);
        } else {
            // veinti...
            char tbuf[256] = { 0 };
            one_digit(second, tbuf, sizeof(tbuf));
            strncpy(buf, words[VEINTI], sz);
            strncat(buf, tbuf, sz);
        }
    } else {
        int offset = TREINTA + first - 3;
        if (second == 0) {
            strncpy(buf, words[offset], sz);
        } else {
            char tbuf[256] = { 0 };
            strncpy(buf, words[offset], sz);
            strncat(buf, separators[Y], sz);
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

    const char *hundreds[] = {
        "ciento", "cien", "doscientos", "trescientos", "cuatrocientos",
        "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos",
    };

    int first = n/100;
    int last_two = n - first*100;

    // n = 100, 200, 300, ...?
    if (n % 100 == 0) {
        strncpy(buf, words[first], sz);
    } else {
        char tbuf[256] = { 0 };
        int idx = first - 1*(first == 1); // if first digit is 1, write 'ciento', else 'xcientos'

        strncpy(buf, hundreds[idx], sz);
        strncat(buf, separators[ESPACIO], sz);
        two_digits(last_two, tbuf, sizeof(tbuf));
        strncat(buf, tbuf, sz);
    }
}

void four_digits(int n, char *buf, size_t sz)
{
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
    printf("%s\n", buf);
}

int main()
{
    test(122);
    /*
    for (int i = 100; i < 1000; i++) {
        test(i);
    }
    */

    return 0;
}
