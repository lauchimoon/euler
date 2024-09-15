// 296962999629
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define EULER_COMMON_IMPL
#include "common.hh"

struct Tuple {
    int a, b, c;
};

Tuple make_tuple(int a, int b, int c) { return Tuple{a, b, c}; }

std::vector<int> prime_permutations(int n, std::vector<bool> primes)
{
    std::vector<int> permutations = {};
    std::string s = std::to_string(n);

    do {
        int x = std::stoi(s);
        if (primes[x]) permutations.emplace_back(x);
    } while (std::next_permutation(s.begin(), s.end()));

    return permutations;
}

std::vector<Tuple> get_tuples(std::vector<int> permutations)
{
    std::vector<Tuple> sub_vector = {};
    int perm_size = permutations.size();
    for (int i = 0; i < perm_size; ++i) {
        int reference = permutations[i];
        for (int j = 0; j < perm_size; ++j) {
            int k = permutations[j];
            if (k != reference && k - reference > 0) sub_vector.emplace_back(make_tuple(reference, k, k - reference));
        }
    }

    return sub_vector;
}

int main()
{
    std::vector<bool> primes = eratosthenes(10000);
    int top = 2700; // Digits will be repeating in permutations if we go any higher

    for (int k = 1000; k <= 2700; ++k) {
        if (!primes[k])
            continue;

        std::vector<int> permutations = prime_permutations(k, primes);
        std::vector<Tuple> sub_vector = get_tuples(permutations);
        int sub_vector_sz = sub_vector.size();

        // Check if it's an arithmetic sequence
        for (int i = 0; i < sub_vector_sz; ++i) {
            for (int j = 0; j < sub_vector_sz; ++j) {
                Tuple t1 = sub_vector[i];
                Tuple t2 = sub_vector[j];
                if (t2.b - t2.a == t1.b - t1.a && t1.b == t2.a && t1.a != 1487) // Skip 1487
                    std::cout << t1.a << t2.a << t2.b<< "\n";
            }
        }
    }

    return 0;
}
