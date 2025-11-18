#pragma once

namespace dnd_character {

    class Character {
        public:
            Character();

            int strength;
            int dexterity;
            int constitution;
            int intelligence;
            int wisdom;
            int charisma;
            int hitpoints;
    };

    int modifier(int x);
    int ability();

}  // namespace dnd_character
