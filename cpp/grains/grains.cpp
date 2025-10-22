#include "grains.h"

namespace grains {

    unsigned long long square(int n) {
        return 1ULL << (n-1);
    }

    unsigned long long total() {
        auto grains = 0ULL;

        for (unsigned int i = 0; i < 64; ++i) {
            grains += square(i);
        }

        return grains;
    }

}  // namespace grains
