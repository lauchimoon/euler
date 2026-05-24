// 8319823
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

#define TOP 1e7
#define all(x) (x).begin(), (x).end()

ll phi(ll n)
{
    if (n == 1)
        return 1;

    ll ans = n;
    for (ll i = 2; i*i <= n; ++i)
        if (n % i == 0) {
            ans -= ans/i;
            while (n%i == 0)
                n /= i;
        }

    if (n > 1)
        ans -= ans/n;

    return ans;
}

// Check if a is permutation of b
bool is_permutation(ll a, ll b)
{
    string a_str = to_string(a);
    string b_str = to_string(b);
    sort(all(a_str));
    sort(all(b_str));

    return a_str == b_str;
}

int main()
{
    ll ans = 0;
    double min_ratio = INT_MAX;
    for (ll n = 2; n < TOP; ++n) {
        ll p = phi(n);
        if (is_permutation(p, n)) {
            double r = double(n)/double(p);
            if (min_ratio > r) {
                ans = n;
                min_ratio = r;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
