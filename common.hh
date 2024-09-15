#ifndef COMMON_HH
#define COMMON_HH

std::vector<bool> eratosthenes(int n);

#ifdef EULER_COMMON_IMPL
#include <vector>
#include <cmath>
std::vector<bool> eratosthenes(int n)
{
    std::vector<bool> primes(n, true);

    int top = sqrt(n);
    for (int i = 2; i <= top; ++i) {
        if (primes[i]) {
            for (int j = i*i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }

    return primes;   
}
#endif

#endif
