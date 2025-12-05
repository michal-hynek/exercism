#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    int distance = 0;
    int offset = 0;

    while (*(lhs + offset) != '\0' || *(rhs + offset) != '\0') {
        char left_char = *(lhs + offset);
        char right_char = *(rhs + offset);

        if (left_char == '\0' || right_char == '\0') {
            return -1;
        }

        if (left_char != right_char) {
            distance++;
        }

        offset += sizeof(char);
    }

    return distance;
}
