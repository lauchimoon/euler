// 5777
#include <iostream>
#include <vector>
#include <cmath>

#define EULER_COMMON_IMPL
#include "common.hh"

bool is_integer(float n)
{
    int int_part = int(n);
    float float_part = n - int_part;
    return float_part == 0.0f;
}

int main()
{
    int top = 5785;
    int x = 0;
    bool indicator = true;
    std::vector<bool> primes = eratosthenes(top);
    for (int i = 3; i < top; i += 2) {
        indicator = false;
        if (!primes[i]) {
            for (int p = 2; p < i; ++p) {
                if (primes[p]) {
                    float n = sqrt((i - p)/2);
                    if (is_integer(n) && i == p + 2*n*n) {
                        indicator = true;
                        break;
                    }
                }
            }
            if (!indicator) x = i;
        }
    }

    std::cout << x << "\n";
    return 0;
}
