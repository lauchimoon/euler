// 2772
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;
using ll = long long;

ll count(ll m, ll n)
{
    return (m*(m+1)/2)*(n*(n+1)/2);
}

int main()
{
    ll m = 1, n = 1;
    ll mindiff = INT_MAX;
    int width, height;
    for (ll m = 1; m < 2000; ++m) {
        for (ll n = 1; n < 2000; ++n) {
            ll c = count(m, n);
            ll diff = abs(2000000 - c);
            if (diff < mindiff) {
                mindiff = diff;
                width = m;
                height = n;
            }
        }
    }

    cout << width*height << '\n';
    return 0;
}
