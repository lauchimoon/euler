// 997651
#include <iostream>
#include <vector>
#include <cmath>

std::vector<char> eratosthenes(int n)
{
    std::vector<char> primes(n, true);

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

int main()
{
    int top = 1000000;
    long long int sum = 0, nterms = 0;
    int max_terms = 0, max_prime = 0;
    std::vector<char> primes = eratosthenes(top);
    for (int i = 2; i < top; ++i) {
        sum = 0;
        nterms = 0;
        if (primes[i]) {
            for (int j = i; j < top; ++j) {
                if (primes[j]) {
                    sum += j;
                    ++nterms;
                    if (sum > top)
                        break;

                    if (nterms > max_terms && primes[sum]) {
                        max_terms = nterms;
                        max_prime = sum;
                    }
                }
            }
        }
    }

    std::cout << max_prime << "\n";
    return 0;
}
