#include "binary.h"

namespace binary {

    bool is_valid_digit(char digit) {
        return digit == '0' || digit == '1';
    }

    int convert(string binary_num) {
        int decimal_num = 0;
        int pow = 1;

        for (int i = binary_num.length()-1; i >= 0; --i) {
            char digit = binary_num.at(i);

            if (!is_valid_digit(digit)) {
                return 0;
            }

            if (digit == '1') {
                decimal_num += pow;
            }

            pow *= 2;
        }

        return decimal_num;
    }

}  // namespace binary
