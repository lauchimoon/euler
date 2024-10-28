// 137846528820
#include <stdio.h>
#include <gmp.h>

int main()
{
    // Note that in a 2x2 grid it takes 2 steps in the x coordinate to get to the right
    // and 2 steps in the y coordinate to get to the bottom, a total of 4 steps. The question is,
    // how many of those 4 steps belong 2 to x and 2 to y? In other words, it's a combinatorics problem.
    // It's finding the number of ways you can choose 2 elements in a set of 4 elements, represented as
    // C(4, 2) = 6.
    //
    // To solve the problem, consider the same question but in a 20x20 grid; 20 steps in x and y, a total of
    // 40 steps. How many of those 40 steps belong 20 to x and 20 to y? It's finding the number of ways you can
    // choose 20 elements in a set of 40 elements, C(40, 20).

    mpz_t routes;
    mpz_init(routes);

    mpz_bin_uiui(routes, 40, 20);
    mpz_out_str(stdout, 10, routes);
    printf("\n");

    mpz_clear(routes);

    return 0;
}
