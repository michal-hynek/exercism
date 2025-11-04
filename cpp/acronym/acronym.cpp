#include "acronym.h"

#include <iostream>

namespace acronym {

    bool is_delimeter(char c) {
        return c == '-' || isspace(c);
    }

    string acronym(string phrase) {
        string acronym{};

        unsigned int i = 0;
        while (i < phrase.length()) {
            if (is_delimeter(phrase.at(i)) || !isalpha(phrase.at(i))) {
                ++i;
                continue;
            }

            acronym.push_back(toupper(phrase.at(i)));

            while (i < phrase.length() && !is_delimeter(phrase.at(i))) {
                ++i;
            }
        }

        return acronym;
    }

}  // namespace acronym
