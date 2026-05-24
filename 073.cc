#include <iostream>
#include <numeric>

using namespace std;

int main()
{
#define TOP 12000
    int count = 0;
    for (int n = 1; n <= TOP; ++n)
        for (int d = TOP; d > n; --d) {
            double r = double(n)/double(d);
            count += (gcd(n, d) == 1 && r > 1.0/3 && r < 1.0/2);
        }
    cout << count << '\n';
    return 0;
}
