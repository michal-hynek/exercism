#include "binary.h"

int convert(const char *input) {
    int offset = 0;
    int binary_num = 0;

    while (input[offset] != '\0') {
        if (input[offset] != '0' && input[offset] != '1') {
            return INVALID;
        }

        int digit = input[offset] - '0';

        binary_num *= 2;
        binary_num += digit;

        offset++;
    }

    return binary_num;
}
