#include <stdio.h>
#include "pangram.h"

bool is_pangram(const char *sentence) {
    if (sentence == NULL) {
        return false;
    }

    bool chars[26] = { false };

    int i = 0;
    while (sentence[i] != '\0') {
        char c = sentence[i];
        char is_lowercase = c >= 'a' && c <= 'z';
        char is_uppercase = c >= 'A' && c <= 'Z';

        if (is_lowercase) {
            chars[c - 'a'] = true;
        } else if (is_uppercase) {
            chars[c - 'A'] = true;
        }

        i++;
    }

    for (unsigned int i = 0; i < 26; i++) {
        if (!chars[i]) {
            return false;
        }
    }

    return true;
}
