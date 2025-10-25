#include "nucleotide_count.h"

#include <stdexcept>

namespace nucleotide_count {

    bool is_valid(char c) {
        return c == 'A' || c == 'C' || c == 'G' || c == 'T';
    }

    map<char, int> count(string dna) {
        map<char, int> counts{
            {'A', 0},
            {'C', 0},
            {'G', 0},
            {'T', 0}
        };

        for (auto c : dna) {
            if (!is_valid(c)) {
                throw invalid_argument("invalid input");
            }

            counts.at(c)++;
        }

        return counts;
    }

}  // namespace nucleotide_count
