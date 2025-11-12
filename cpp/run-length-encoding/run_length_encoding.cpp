#include "run_length_encoding.h"

namespace run_length_encoding {

    string encode(string input) {
        string encoded{};

        unsigned int i = 0;
        while (i < input.length()) {
            char c = input.at(i);
            int count = 0;

            while (i < input.length() && c == input.at(i)) {
                count++;
                i++;
            }

            if (count > 1) {
                encoded.append(to_string(count));
                encoded.push_back(c);
            } else {
                encoded.push_back(c);
            }
        }

        return encoded;
    }

    string decode(string input) {
        string decoded{};

        unsigned int i = 0;
        while (i < input.length()) {
            char c = input.at(i);

            if (isdigit(c)) {
                int count = 0;

                while (isdigit(c)) {
                    count *= 10;
                    count += input.at(i) - '0';
                    i++;
                    c = input.at(i);
                }

                c = input.at(i);
                for (int i = 0; i < count; i++) {
                    decoded.push_back(c);
                }
            } else {
                decoded.push_back(c);
            }

            i++;
        }

        return decoded;
    }

}  // namespace run_length_encoding
