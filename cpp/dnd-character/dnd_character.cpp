#include "dnd_character.h"

#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

namespace dnd_character {

    Character::Character() {
        this->charisma = ability();
        this->constitution = ability();
        this->dexterity = ability();
        this->intelligence = ability();
        this->strength = ability();
        this->wisdom = ability();

        this->hitpoints = 10 + modifier(this->constitution);
    }

    int ability() {
        int dice = 4;
        srand(time(0));

        vector<int> values{};
        for (int i = 0; i < dice; ++i) {
            values.push_back(rand() % 6 + 1);
        }

        sort(values.begin(), values.end());

        int ability = 0;
        for (unsigned int i = 1; i < values.size(); ++i) {
            ability += values.at(i);
        }

        return ability;
    }

    int modifier(int x) {
        if (x % 2 == 0 || x >= 10) {
            return (x - 10) / 2;
        } else {
            return (x - 10) / 2 - 1;
        }
    }

}  // namespace dnd_character
