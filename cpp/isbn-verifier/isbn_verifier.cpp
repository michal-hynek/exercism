#include "isbn_verifier.h"

namespace isbn_verifier {

    int count_digits(string isbn) {
        int digits = 0;

        for (auto c : isbn) {
            if (isdigit(c) || tolower(c) == 'x') {
                digits++;
            }
        }

        return digits;
    }

    bool is_valid(string isbn) {
        int sum = 0;
        int digits = count_digits(isbn);

        if (digits < 9 || digits > 10) {
            return false;
        }

        int weight = digits;
        for (auto digit : isbn) {
            char c = tolower(digit);

            if (isdigit(c)) {
                sum += (c - '0') * weight;
            } else if (c == 'x' && weight == 1) {
                sum += 10 * weight;
            } else if (c == '-' || isspace(c)) {
                continue;
            } else {
                return false;
            }

            weight--;
        }

        return sum % 11 == 0;
    }

}  // namespace isbn_verifier
