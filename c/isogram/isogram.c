#include <stdlib.h>
#include "isogram.h"

bool is_isogram(const char phrase[]) {
    if (phrase == NULL) {
        return false;
    }

    bool chars[27] = { false };

    int i = 0;
    while (phrase[i] != '\0') {
        bool is_lowercase = phrase[i] >= 'a' && phrase[i] <= 'z';
        bool is_uppercase = phrase[i] >= 'A' && phrase[i] <= 'Z';
        int char_ord = 26;

        if (is_lowercase) {
            char_ord = phrase[i] - 'a';
        } else if (is_uppercase) {
            char_ord = phrase[i] - 'A';
        }

        if (chars[char_ord]) {
            return false;
        } else if (char_ord < 26) {
            chars[char_ord] = true;
        }

        i++;
    }

    return true;
}
