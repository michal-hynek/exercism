#include "pangram.h"

#include <cctype>

namespace pangram {

    bool is_pangram(string sentence) {
        bool used_chars[26] {};

        for (unsigned int i = 0; i < sentence.length(); ++i) {
            char c = sentence.at(i);

            if (isalpha(c)) {
                if (islower(c)) {
                    used_chars[c-'a'] = true;
                } else {
                    used_chars[c-'A'] = true;
                }
            }
        }

        for (unsigned int i = 0; i < 26; ++i) {
            if (!used_chars[i]) {
                return false;
            }
        }

        return true;
    }

}  // namespace pangram
