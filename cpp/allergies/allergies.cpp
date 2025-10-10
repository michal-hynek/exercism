#include "allergies.h"

#include <unordered_map>

namespace allergies {

    const unordered_map<string, int> food_values{
        { "eggs", 1 },
        { "peanuts", 2 },
        { "shellfish", 4 },
        { "strawberries", 8 },
        { "tomatoes", 16 },
        { "chocolate", 32 },
        { "pollen", 64 },
        { "cats", 128 },
    };

    allergy_test::allergy_test(int allergen_value) {
        this->allergen_value = allergen_value;
    }

    bool allergy_test::is_allergic_to(string food) {
        if (food_values.count(food) == 0) {
            return false;
        }

        return (food_values.at(food) & this->allergen_value) != 0;
    }

    unordered_set<string> allergy_test::get_allergies() {
        unordered_set<string> allergies{};

        for (auto const& [food, value] : food_values) {
            if (this->is_allergic_to(food)) {
                allergies.emplace(food);
            }
        }

        return allergies;
    }

}  // namespace allergies
