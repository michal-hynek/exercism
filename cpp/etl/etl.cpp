#include "etl.h"

#include <iostream>

namespace etl {

    map<char, int> transform(map<int, vector<char>> old_map) {
        map<char, int> new_map{};

        for (auto &old_entry : old_map) {
            int points = old_entry.first;

            for (auto letter : old_entry.second) {
                new_map.emplace(tolower(letter), points);
            }
        }

        return new_map;
    }

}  // namespace etl
