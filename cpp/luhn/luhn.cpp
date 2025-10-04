#include "luhn.h"

namespace luhn {

bool is_digit(char digit) {
    return digit >= '0' && digit <= '9';
}

bool valid(string input) {
    int digit_sum = 0;
    int digits = 0;

    for (int i = input.length()-1; i >= 0; --i) {
        if (input.at(i) == ' ') {
            continue;
        }

        if (!is_digit(input.at(i))) {
            return false;
        }

        int digit = input.at(i) - '0';

        if (digits % 2 == 1 && digit >= 5) {
            digit_sum += 2*digit - 9;
        } else if (digits % 2 == 1) {
            digit_sum += 2*digit;
        } else {
            digit_sum += digit;
        }

        digits++;
    }

    if (digits <= 1) {
        return false;
    }

    return digit_sum % 10 == 0;
}

}  // namespace luhn
