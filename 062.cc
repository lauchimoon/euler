// 127035954683
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>

#define all(x) (x.begin()), (x.end())
using namespace std;
using ull = unsigned long long;
using pull = pair<ull, ull>;

int main()
{
    unordered_map<string, pull> occur;
    ull n = 1;
    int target = 5;
    while (true) {
        ull cubed = n*n*n;
        string digits = to_string(cubed);
        sort(all(digits));

        if (occur.count(digits) <= 0)
            occur[digits].first = cubed;

        occur[digits].second += 1;
        if (occur[digits].second == target) {
            cout << occur[digits].first << '\n';
            return 0;
        }

        ++n;
    }
    return 0;
}
