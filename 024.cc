// 2783915460
#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::string nums = "0123456789";
    int i = 1; // Include 0123456789

    while (std::next_permutation(nums.begin(), nums.end())) {
        if (i == 999999) break;
        ++i;
    }

    std::cout << nums << '\n';

    return 0;
}
