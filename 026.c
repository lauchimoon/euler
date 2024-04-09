// 983
#include <stdio.h>
#include <math.h>
#include <gmp.h>

void generate_cyclic(mpz_t num, int prime)
{
    int base = 10;
    if (base % prime == 0) {
        mpz_set_ui(num, -1);
        return;
    }

    int remainder = 1;
    int x = remainder * base;
    int digit = x/prime;

    remainder = x % prime;
    mpz_mul_ui(num, num, base);
    mpz_add_ui(num, num, digit);

    while (remainder != 1) {
        x = remainder * base;
        digit = x/prime;
        remainder = x % prime;
        mpz_mul_ui(num, num, base);
        mpz_add_ui(num, num, digit);
    }
}

int main()
{
    int primes[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
        101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
        197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307,
        311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421,
        431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547,
        557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
        661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
        809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929,
        937, 941, 947, 953, 967, 971, 977, 983, 991, 997,
    };
    int primes_size = sizeof(primes)/sizeof(primes[0]);
    int max_denom = 0;
    mpz_t num;
    mpz_t max_cycle;
    mpz_init(max_cycle);

    for (int i = 0; i < primes_size; ++i) {
        int prime = primes[i];
        mpz_init(num);
        generate_cyclic(num, prime);
        if (mpz_cmp(num, max_cycle) > 0) {
            max_denom = prime;
            mpz_set(max_cycle, num);
        }

        mpz_clear(num);
    }

    mpz_clear(max_cycle);
    return 0;
}
