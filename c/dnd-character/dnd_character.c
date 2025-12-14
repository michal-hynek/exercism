#include "dnd_character.h"

#include <stdlib.h>

int ability(void) {
    const int ROLLS = 4;

    int min_roll = 1;
    int sum = 0;

    for (int i = 0; i < ROLLS; i++) {
        int roll = rand() % 6 + 1;

        if (roll < min_roll) {
            min_roll = roll;
        }

        sum += roll;
    }

    return sum - min_roll;
}

int modifier(int score) {
    if (score >= 10 || score % 2 == 0) {
        return (score - 10) / 2;
    } else {
        return (score - 10) / 2 - 1;
    }
}

dnd_character_t make_dnd_character(void) {
    dnd_character_t character;
    character.strength = ability();
    character.dexterity = ability();
    character.constitution = ability();
    character.intelligence = ability();
    character.wisdom = ability();
    character.charisma = ability();
    character.hitpoints = 10 + modifier(character.constitution);

   return character;
}
