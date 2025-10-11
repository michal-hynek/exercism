#include "kindergarten_garden.h"

#include <unordered_map>

namespace kindergarten_garden {

    unordered_map<string, unsigned int> student_positions = {
        { "Alice", 0 },
        { "Bob", 1 },
        { "Charlie", 2 },
        { "David", 3 },
        { "Eve", 4 },
        { "Fred", 5 },
        { "Ginny", 6 },
        { "Harriet", 7 },
        { "Ileana", 8 },
        { "Joseph", 9 },
        { "Kincaid", 10 },
        { "Larry", 11 },
    };

    unordered_map<char, Plants> plant_chars = {
        { 'G', Plants::grass },
        { 'C', Plants::clover },
        { 'V', Plants::violets },
        { 'R', Plants::radishes },
    };

    array<Plants, 4> plants(string plants, string student) {
        int plants_in_row = plants.length() / 2;
        int position = student_positions.at(student);

        return array<Plants, 4>{
            plant_chars.at(plants.at(position*2)),
            plant_chars.at(plants.at(position*2+1)),
            plant_chars.at(plants.at(plants_in_row + 1 + position*2)),
            plant_chars.at(plants.at(plants_in_row + 1 + position*2+1)),
        };
    }

}  // namespace kindergarten_garden
