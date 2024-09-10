// 932718654
#include <iostream>
#include <vector>
#include <array>

bool all_one(std::array<int, 9>& a)
{
    int i = 0;
    while (i < 9 && a[i] == 1)
        ++i;

    return i == 9;
}

std::vector<int> ntuple(int n)
{
    std::vector<int> v = {};
    for (int i = 0; i < n; ++i) {
        v.emplace_back(i + 1);
    }

    return v;
}

bool is_pandigital(int x)
{
    std::array<int, 9> digits = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int dig = x%10;

    while (x != 0 && dig != 0) {
        ++digits[dig - 1];
        x /= 10;
        dig = x%10;
    }

    return all_one(digits);
}

int main()
{
    long long int max = 0;
    for (int k = 9; k <= 10000; ++k) {
        std::string s = "";
        for (int n = 2; n <= 9; ++n) {
            std::vector<int> tuple = ntuple(n);
            for (int m : tuple) {
                s += std::to_string(k*m);
            }

            if (s.size() <= 9) {
                long long int x = std::stoll(s);
                if (is_pandigital(x) && x > max) {
                    max = x;
                }
            }
        }
    }

    std::cout << max << "\n";
    return 0;
}
