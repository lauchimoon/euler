// 272
#include <stdio.h>

int main()
{
    // https://oeis.org/A007676/b007676.txt
    char *convergent = "6963524437876961749120273824619538346438023188214475670667";
    int digitsum = 0;
    for (int i = 0; convergent[i]; ++i)
        digitsum += (convergent[i] - '0');

    printf("%d\n", digitsum);
    return 0;
}
