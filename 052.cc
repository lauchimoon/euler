// 142857
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

std::vector<int> digits(int x)
{
    std::vector<int> v;
    while (x != 0) {
        v.push_back(x%10);
        x /= 10;
    }

    return v;
}

void cat_vectors(std::vector<int> &u, std::vector<int> v1, std::vector<int> v2,
                                      std::vector<int> v3, std::vector<int> v4,
                                      std::vector<int> v5, std::vector<int> v6)
{
    u.reserve(v1.size() + v2.size() + v3.size() + v4.size() + v5.size() + v6.size());
    u.insert(u.end(), v2.begin(), v2.end());
    u.insert(u.end(), v3.begin(), v3.end());
    u.insert(u.end(), v4.begin(), v4.end());
    u.insert(u.end(), v5.begin(), v5.end());
    u.insert(u.end(), v6.begin(), v6.end());
}

int main()
{
    int x = 1;
    std::vector<int> v1 = digits(x); std::vector<int> v2 = digits(2*x);
    std::vector<int> v3 = digits(3*x); std::vector<int> v4 = digits(4*x);
    std::vector<int> v5 = digits(5*x); std::vector<int> v6 = digits(6*x);

    std::vector<int> u = v1;
    cat_vectors(u, v1, v2, v3, v4, v5, v6);

    std::set<int> s(v1.begin(), v1.end());
    std::set<int> u_s(u.begin(), u.end());

    while (s != u_s) {
        ++x;
        v1 = digits(x); v2 = digits(2*x);
        v3 = digits(3*x); v4 = digits(4*x);
        v5 = digits(5*x); v6 = digits(6*x);
        u = v1;
        cat_vectors(u, v1, v2, v3, v4, v5, v6);

        s = std::set<int>(v1.begin(), v1.end());
        u_s = std::set<int>(u.begin(), u.end());
    }

    std::cout << x << "\n";
    return 0;
}
