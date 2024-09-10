// 7526965179680
#include <iostream>
#include <vector>
#include <cmath>

int legendre(int x, int p)
{
    int sum = 0;
    int L = std::floor(std::log(x)/std::log(p));
    for (int i = 1; i <= L; ++i) {
        sum += std::floor(x/(int)std::pow(p, i));
    }

    return sum;
}

std::vector<bool> eratosthenes(int n)
{
    std::vector<bool> primes(n, 1);

    int top = sqrt(n);
    for (int i = 2; i < top; ++i) {
        if (primes[i]) {
            for (int j = i*i; j < n; j += i) {
                primes[j] = false;
            }
        }
    }

    return primes;
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
