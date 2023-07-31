// 669171001
#include <stdio.h>

#define square(x) (x)*(x)

int main()
{
    // From pen and paper deduce this summation
    // This can be done without a for loop... too bad!
    int sum = 0;
    for (int i = 1; i <= 500; i++) {
        sum += 4*square(2*i + 1) - 12*i;
    }

    sum++; // Add the 1 in the center
    printf("%d\n", sum);

    return 0;
}
