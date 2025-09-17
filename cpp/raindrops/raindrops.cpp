#include <string>
#include "raindrops.h"

namespace raindrops {

    std::string convert(int x) {
        std::string result{""};

        if (x % 3 == 0) {
            result += "Pling";
        }

        if (x % 5 == 0) {
            result += "Plang";
        }

        if (x % 7 == 0) {
            result += "Plong";
        }

        if (x % 3 != 0 && x % 5 != 0 && x % 7 != 0) {
            result = std::to_string(x);
        }

        return result;
    }

}  // namespace raindrops
