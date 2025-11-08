#include "perfect_numbers.h"

#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

namespace perfect_numbers {

    vector<int> factors(int num) {
        vector<int> factors{};

        for (int i = 1; i < num; ++i) {
            if (num % i == 0) {
                factors.push_back(i);
            }
        }

        return factors;
    }

    classification classify(int num) {
        if (num <= 0) {
            throw domain_error("number has to be positive");
        }

        vector<int> num_factors = factors(num);
        int sum = 0;

        for (auto factor : num_factors) {
            sum += factor;
        }

        if (num == sum) {
            return classification::perfect;
        } else if (num > sum) {
            return classification::deficient;
        } else {
            return classification::abundant;
        }
    }

}  // namespace perfect_numbers
