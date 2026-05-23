// 1097343
#include <iostream>
#include <set>
#include <vector>

#define EULER_COMMON_IMPL
#include "common.hh"

using namespace std;
using ll = long long;

int count(int top, vector<bool> &primes2, vector<bool> &primes3, vector<bool> &primes4)
{
    set<ll> nums;
    for (int i = 0; i < primes2.size(); ++i)
        for (int j = 0; j < primes3.size(); ++j)
            for (int k = 0; k < primes4.size(); ++k)
                if (primes2[i] && primes3[j] && primes4[k]) {
                    ll n = i*i + j*j*j + k*k*k*k;
                    if (n < top)
                        nums.insert(n);
                }

    return nums.size();
}

int main()
{
    vector<bool> primes2 = eratosthenes(7071);
    vector<bool> primes3 = eratosthenes(368);
    vector<bool> primes4 = eratosthenes(84);
    cout << count(50000000, primes2, primes3, primes4) << '\n';
    return 0;
}
