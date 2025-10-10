#pragma once

#include <string>
#include <unordered_set>

using namespace std;

namespace allergies {

    class allergy_test {
        public:
            allergy_test(int allergen_value);

            bool is_allergic_to(string food);
            unordered_set<string> get_allergies();
        
        private:
            int allergen_value;
    };

}  // namespace allergies
