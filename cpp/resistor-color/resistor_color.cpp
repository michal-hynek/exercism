#include "resistor_color.h"

#include <unordered_map>

namespace resistor_color {

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

    int color_code(string color) {
        return color_values.at(color);
    }

    vector<string> colors() {
        return vector<string>{"black",  "brown", "red",  "orange",
            "yellow", "green", "blue", "violet",
            "grey",   "white"};
    }

}  // namespace resistor_color
