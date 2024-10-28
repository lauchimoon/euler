// 134043
#include <map>
#include <iostream>
#include <set>
#include <string>

#define BEGIN_COUNT 1
#define N_FACTORS   4

int min_div(int n)
{
    int min = 2;
    while (n % min != 0)
        ++min;

    return min;
}

std::set<std::string> pfactors(int n)
{
    std::map<int, int> factorization = {};
    std::set<std::string> factors = {};
    int m = n;
    while (m != 1) {
        int base = min_div(m);
        ++factorization[base];
        m /= base;
    }

    for (auto base_exp : factorization)
        factors.emplace(std::to_string(base_exp.first) + "^" + std::to_string(base_exp.second));
    
    return factors;
}

int main()
{
    int it = 0;
    int i = BEGIN_COUNT;
    while (it != N_FACTORS - 1) {
        std::set<std::string> factors_n = pfactors(i + it);
        std::set<std::string> factors_n1 = pfactors(i + 1 + it);
        if ((factors_n != factors_n1) && (factors_n.size() == N_FACTORS) && (factors_n1.size() == N_FACTORS))
            ++it;
        else {
            it = 0;
            ++i;
        }
    }

    std::cout << i << "\n";
    return 0;
}
