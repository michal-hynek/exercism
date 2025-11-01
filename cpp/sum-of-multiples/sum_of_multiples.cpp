#include "sum_of_multiples.h"

#include <unordered_set>

namespace sum_of_multiples {

    int to(vector<int> nums, int max) {
        unordered_set<int> multiples{};

        for (auto num : nums) {
            int multiple = num;

            while (multiple < max) {
                multiples.emplace(multiple);
                multiple += num;
            }
        }

        int sum = 0;
        for (auto num : multiples) {
            sum += num;
        }

        return sum;
    }

}  // namespace sum_of_multiples
