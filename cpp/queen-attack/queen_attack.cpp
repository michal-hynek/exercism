#include "queen_attack.h"

#include <cmath>
#include <stdexcept>

namespace queen_attack {

    bool is_valid_position(pair<int, int> pos) {
        return pos.first >= 0 && pos.first < 8 && pos.second >= 0 && pos.second < 8;
    }

    chess_board::chess_board(pair<int, int> white, pair<int, int> black) {
        if (!is_valid_position(white)) {
            throw domain_error("White queen position is invalid");
        }

        if (!is_valid_position(black)) {
            throw domain_error("Black queen position is invalid");
        }

        if (white == black) {
            throw domain_error("Queen positions must be distinct");
        }

        this->m_white = white;
        this->m_black = black;
    }

    pair<int, int> chess_board::white() const {
        return this->m_white;
    }

    pair<int, int> chess_board::black() const {
        return this->m_black;
    }

    bool chess_board::can_attack() const {
        bool row_attack = this->white().first == this->black().first;
        bool col_attack = this->white().second == this->black().second;

        int row_dist = abs(this->white().first - this->black().first);
        int col_dist = abs(this->white().second - this->black().second);
        bool diagonal_attack = row_dist == col_dist;

        return row_attack || col_attack || diagonal_attack;
    }

}  // namespace queen_attack
