#include "hamming.h"

#include <stdexcept>

namespace hamming {

    int compute(string dna1, string dna2) {
        if (dna1.length() != dna2.length()) {
            throw domain_error("DNAs have different lengths");
        }

        int diff = 0;
        for (unsigned int i = 0; i < dna1.length(); ++i) {
            if (dna1.at(i) != dna2.at(i)) {
                diff++;
            }
        }

        return diff;
    }

}  // namespace hamming
