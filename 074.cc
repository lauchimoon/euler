// 402
#include <iostream>
#include <unordered_map>

#define MILL 1000000
#define TARGET 59
typedef unsigned long long int ull;

int fac[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int chains(int x)
{
  ull s = 0;
  std::unordered_map<ull, bool> seen = {};

  while (x) {
    int d = x%10;
    s += fac[d];
    x /= 10;

    if (x == 0) {
      if (seen.find(s) != seen.end())
        break;

      seen[s] = true;
      x = s;
      s = 0;
    }
  }

  return seen.size();
}

int main()
{
  int count = 0;
  for (int i = 69; i < MILL; ++i)
    if (chains(i) == TARGET)
      ++count;

  std::cout << count << '\n';

  return 0;
}
