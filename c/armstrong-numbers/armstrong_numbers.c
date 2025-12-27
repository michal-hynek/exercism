#include <math.h>
#include "armstrong_numbers.h"

int num_of_digits(int candidate) {
    int digits = 0;

    while (candidate > 0) {
        digits++;
        candidate /= 10;
    }

    return digits;
}

bool is_armstrong_number(int candidate) {
    int digits = num_of_digits(candidate);
    int sum = 0;

    int x = candidate;
    for (int i = 0; i < digits; i++) {
        int digit = x % 10;
        sum += pow(digit, digits);
        x /= 10;
    }

    return sum == candidate;
}
