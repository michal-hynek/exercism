#pragma once

#include <string>
#include <array>

using namespace std;

namespace kindergarten_garden {
    enum class Plants{
        grass = 'G',
        clover = 'C',
        radishes = 'R',
        violets = 'V',
    };

    array<Plants, 4> plants(string plants, string student);

}  // namespace kindergarten_garden
