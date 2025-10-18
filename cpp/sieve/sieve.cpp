#include "sieve.h"

#include <unordered_set>

namespace sieve {

    vector<int> primes(int n) {
        vector<int> primes{};
        unordered_set<int> marked_nums{};

        for (int i = 2; i <= n; ++i) {
            bool is_marked = marked_nums.find(i) != marked_nums.end();

            if (is_marked) {
                continue;
            }

            primes.push_back(i);
            for (int j = 2*i; j <= n; j += i) {
                marked_nums.emplace(j);
            }
        }

        return primes;
    }

}  // namespace sieve
