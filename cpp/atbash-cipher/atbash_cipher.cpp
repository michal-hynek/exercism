#include "atbash_cipher.h"

using namespace std;

namespace atbash_cipher {

bool is_char(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

char encode_char(char c) {
    return 'z' - tolower(c) + 'a';
}

char decode_char(char c) {
    return ((c - 'z') * -1) + 'a';
}

string encode(string input) {
    const int block_length = 5;
    string encoded = "";
    int encoded_chars = 0;

    for (unsigned int i = 0; i < input.length(); ++i) {
        char encoded_char; 

        if (is_char(input.at(i))) {
            encoded_char = encode_char(input.at(i));
        } else if (is_digit(input.at(i))) {
            encoded_char = input.at(i);
        } else {
            continue;
        }

        if (encoded_chars > 0 && encoded_chars % block_length == 0) {
            encoded.push_back(' ');
        }

        encoded_chars++;
        encoded.push_back(encoded_char);
    }

    return encoded;
}

string decode(string encoded) {
    string decoded = "";

    for (unsigned int i = 0; i < encoded.length(); ++i) {
        if (encoded.at(i) == ' ') {
            continue;
        }

        char decoded_char = is_char(encoded.at(i)) ? decode_char(encoded.at(i)) : encoded.at(i);

        decoded.push_back(decoded_char);
    }

    return decoded;
}

}  // namespace atbash_cipher
