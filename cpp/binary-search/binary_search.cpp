#include "binary_search.h"

#include <stdexcept>

namespace binary_search {

    size_t find(vector<int> data, int num) {
        int left = 0;
        int right = data.size()-1;

        while (left <= right) {
            int middle = left + (right - left) / 2;

            if (data.at(middle) == num) {
                return middle;
            } else if (data.at(middle) < num) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        throw domain_error("Number not found");
    }

}  // namespace binary_search
