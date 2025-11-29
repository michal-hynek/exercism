#include "collatz_conjecture.h"

int steps(int num) {
    if (num < 1) {
        return ERROR_VALUE;
    }

    int steps = 0;

    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = num*3 + 1;
        }

        steps++;
    }

    return steps;
}
