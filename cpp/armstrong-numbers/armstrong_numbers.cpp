#include "armstrong_numbers.h"

#include <cmath>

namespace armstrong_numbers {

    int num_of_digits(int num) {
        int digits = 0;

        while (num > 0) {
            digits++;
            num /= 10;
        }
        
        return digits;
    }

    bool is_armstrong_number(int num) {
        int digit_sum = 0;
        int exp = num_of_digits(num);
        int x = num;

        while (x > 0) {
            digit_sum += pow(x % 10, exp);
            x /= 10;
        }

        return digit_sum == num;
    }

}  // namespace armstrong_numbers
