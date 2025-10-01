#include "rotational_cipher.h"

namespace rotational_cipher {

bool is_char(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

char encode_char(char c, int rot) {
    if (is_char(c)) {
        if (is_lowercase(c)) {
            return ((c + rot - 'a') % 26) + 'a';
        } else {
            return ((c + rot - 'A') % 26) + 'A';
        }
    } else {
        return c;
    }
}

string rotate(string input, int rot) {
    string encoded = "";

    for (unsigned int i = 0; i < input.length(); ++i) {
        encoded.push_back(encode_char(input.at(i), rot));
    }

    return encoded;
}

}  // namespace rotational_cipher
