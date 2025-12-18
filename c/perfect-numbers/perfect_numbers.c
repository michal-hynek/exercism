#include "perfect_numbers.h"

kind classify_number(int num) {
    if (num <= 0) {
        return ERROR;
    }

    int factor_sum = 0;

    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            factor_sum += i;
        }
    }

    if (factor_sum == num) {
        return PERFECT_NUMBER;
    } else if (factor_sum > num) {
        return ABUNDANT_NUMBER;
    } else {
        return DEFICIENT_NUMBER;
    }
}