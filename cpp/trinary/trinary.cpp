#include "trinary.h"

namespace trinary {

bool is_valid_digit(char digit) {
    return digit >= '0' && digit <= '2';
}

int to_decimal(std::string trinary_num) {
    int decimal = 0;
    int pow = 1;

    for (int i = trinary_num.length()-1; i >= 0; --i) {
        if (!is_valid_digit(trinary_num.at(i))) {
            return 0;
        }

        decimal += (trinary_num.at(i) - '0') * pow;
        pow *= 3;
    }

    return decimal;
}

}  // namespace trinary
