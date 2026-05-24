#include <algorithm>
#include <iostream>
#include <string>

#define all(x) (x).begin(), (x).end()

using namespace std;

bool is_bouncy(int n)
{
    if (n < 100)
        return false;

    string s = to_string(n);

    string incr = to_string(n);
    sort(all(incr));

    string decr = to_string(n);
    sort(all(decr));
    reverse(all(decr));

    if (s == incr) return false;
    else if (s == decr) return false;
    return true;
}

int main()
{
    int n_bouncy = 0;
    int x = 1;
    while (double(n_bouncy)/double(x) != 0.99) {
        ++x;
        n_bouncy += is_bouncy(x);
    }
    cout << x << '\n';
    return 0;
}
