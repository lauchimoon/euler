// 171
#include <stdio.h>
#include <time.h>

int main()
{
    int sundays = 0;
    for (int year = 1901; year <= 2000; year++) {
        for (int month = 1; month <= 12; month++) {
            struct tm date;
            date.tm_year = year - 1900;
            date.tm_mon = month - 1;
            date.tm_mday = 1;

            mktime(&date);
            sundays += (!date.tm_wday);
        }
    }

    printf("%d\n", sundays);
    return 0;
}
