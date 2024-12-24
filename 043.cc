// 16695334890
#include <iostream>
#include <string>
#include <algorithm>

bool divisible(std::string);

int main()
{
    unsigned long long int sum = 0;
    std::string pandig = "1023456789";
    while (std::next_permutation(pandig.begin(), pandig.end())) {
        if (divisible(pandig))
            sum += std::stoull(pandig);
    }

    std::cout << sum << '\n';
    return 0;
}

bool divisible(std::string s)
{
    int i = 1;
    int top = 8;
    int primes[8] = { 0, 2, 3, 5, 7, 11, 13, 17 };

    while (i < top) {
        std::string num = "";
        for (int j = i; j < 3 + i; ++j)
            num += s[j];

        int n = std::stoi(num);
        if (n % primes[i] != 0)
            return false;

        ++i;
    }

    return true;
}
