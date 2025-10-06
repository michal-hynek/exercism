#include "hexadecimal.h"

namespace hexadecimal {

bool is_valid_hex_digit(char digit) {
    return (digit >= '0' && digit <= '9') || (digit >= 'a' && digit <= 'f');
}

int to_dec(char hex_digit) {
    if (hex_digit >= '0' && hex_digit <= '9') {
        return hex_digit - '0';
    } else {
        return hex_digit - 'a' + 10;
    }
}

int convert(string hex) {
    int dec = 0;
    int pow = 1;

    for (int i = hex.length()-1; i >= 0; --i) {
        if (!is_valid_hex_digit(hex.at(i))) {
            return 0;
        }

        dec += to_dec(hex.at(i)) * pow;
        pow *= 16;
    }

    return dec;
}

}  // namespace hexadecimal
