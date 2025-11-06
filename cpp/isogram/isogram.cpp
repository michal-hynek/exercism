#include "isogram.h"

#include <unordered_set>

namespace isogram {

    bool is_isogram(string word) {
        unordered_set<char> letters{};

        for (auto &letter : word) {
            if (!isalpha(letter)) {
                continue;
            }

            if (letters.find(tolower(letter)) != letters.end()) {
                return false;
            }

            letters.emplace(tolower(letter));
        }

        return true;

    }

}  // namespace isogram
