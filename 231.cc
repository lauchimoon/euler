// 7526965179680
#include <iostream>
#include <vector>
#include <cmath>

#define EULER_COMMON_IMPL
#include "common.hh"

int legendre(int x, int p)
{
    int sum = 0;
    int L = std::floor(std::log(x)/std::log(p));
    for (int i = 1; i <= L; ++i) {
        sum += std::floor(x/(int)std::pow(p, i));
    }

    return sum;
}

int main()
{
    int n = 20000000;
    int r = 15000000;
    std::vector<bool> primes = eratosthenes(n);

    long long int sum = 0;
    for (int p = 2; p < n; ++p) {
        if (primes[p]) {
            long long int exponent = legendre(n, p) - legendre(r, p) - legendre(n - r, p);
            sum += exponent*p;
        }
    }

    std::cout << sum << "\n";
    return 0;
}
