#include <iostream>
#include <vector>

std::vector<unsigned int> range(int a, int b)
{
    std::vector<unsigned int> numbers = {};
    for (int i = a; i <= b; ++i) {
        numbers.emplace_back(i);
    }

    return numbers;
}

// https://algorithmist.com/wiki/Coin_change
// https://en.wikipedia.org/wiki/Integer_partition
int count_partitions(int n, std::vector<unsigned int> integers)
{
    if (n == 0) {
        return 1;
    } else if (n < 0 || (n >= 1 && integers.size() <= 0)) {
        return 0;
    } else {
        int integers_last = integers.at(integers.size() - 1);
        std::vector<unsigned int> but_last = {};
        for (int i = 0; i < integers.size() - 1; ++i) but_last.emplace_back(integers[i]);

        return count_partitions(n, but_last) +
            count_partitions(n - integers_last, integers);
    }
}

int main()
{
    std::cout << count_partitions(100,
            range(1, 99)) << '\n';
    return 0;
}
