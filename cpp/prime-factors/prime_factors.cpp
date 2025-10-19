#include "prime_factors.h"

namespace prime_factors {

    vector<long long> of(long long num) {
        vector<long long> factors{};

        for (long long candidate = 2; num > 1; ++candidate) {
            while (num % candidate == 0) {
                factors.push_back(candidate);
                num /= candidate;
            }
        }

        return factors;
    }

}  // namespace prime_factors
