#include <stdlib.h>

#include "queen_attack.h"

int is_valid_position(position_t pos) {
    return pos.row < 8 && pos.column < 8;
}

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    if (!is_valid_position(queen_1) || !is_valid_position(queen_2)) {
        return INVALID_POSITION;
    }

    if (queen_1.row == queen_2.row && queen_1.column == queen_2.column) {
        return INVALID_POSITION;
    }

    // row and column attack check
    if (queen_1.row == queen_2.row || queen_1.column == queen_2.column) {
        return CAN_ATTACK;
    }

    // diagonal attack check
    uint8_t row_dist = abs(queen_1.row - queen_2.row);
    uint8_t col_dist = abs(queen_1.column - queen_2.column);

    if (row_dist == col_dist) {
        return CAN_ATTACK;
    }

    return CAN_NOT_ATTACK;
}