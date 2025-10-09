#include "reverse_string.h"

namespace reverse_string {

    string reverse_string(string input) {
        string reversed(input.length(), ' ');
        int left = 0;
        int right = input.length() - 1;

        while (left <= right) {
            char temp = input[left];
            reversed[left] = input[right];
            reversed[right] = temp;

            left++;
            right--;
        }

        return reversed;
    }

}  // namespace reverse_string
