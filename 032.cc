// 45228
#include <iostream>
#include <array>
#include <string>
#include <set>

bool all_one(std::array<int, 9>& a)
{
    int a_sz = a.size();
    int i = 0;
    while (i < a_sz && a[i] == 1) {
        ++i;
    }

    return i == a_sz;
}

bool is_pandigital(int a, int b, int c)
{
    long int n = std::stol(std::to_string(a) + std::to_string(b) + std::to_string(c));
    std::array<int, 9> digits = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int dig = n%10;

    while (n != 0 && dig != 0) {
        ++digits[dig - 1];
        n /= 10;
        dig = n%10;
    }

    return all_one(digits);
}

int main()
{
    std::set<int> products = {};

    for (int a = 1; a <= 99; ++a) {
        for (int b = 100; b <= 2000; ++b) {
            int c = a*b;
            if (is_pandigital(a, b, c))
                products.insert(c);
        }
    }

    int sum = 0;
    for (auto x : products)
        sum += x;

    std::cout << sum << "\n";
    return 0;
}
