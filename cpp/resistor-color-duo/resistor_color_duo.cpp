#include "resistor_color_duo.h"

#include <unordered_map>

namespace resistor_color_duo {

    const unordered_map<string, int> color_values {
        { "black", 0 },
        { "brown", 1 },
        { "red", 2 },
        { "orange", 3 },
        { "yellow", 4 },
        { "green", 5 },
        { "blue", 6 },
        { "violet", 7 },
        { "grey", 8 },
        { "white", 9 }
    };

    int value(vector<string> colors) {
        int max_code_len = 2;
        int value = 0;

        for (int i = 0; i < max_code_len; i++) {
            string color = colors.at(i);
            value *= 10;
            value += color_values.at(color);
        }

        return value;
    }


}  // namespace resistor_color_duo
