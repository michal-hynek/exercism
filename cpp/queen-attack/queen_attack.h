#pragma once

#include <utility>

using namespace std;

namespace queen_attack {

    class chess_board {
        public:
            chess_board(pair<int, int> white, pair<int, int> black);
            pair<int, int> black() const;
            pair<int, int> white() const;
            bool can_attack() const;
        
        private:
            pair<int, int> m_white{};
            pair<int, int> m_black{};
    };

}  // namespace queen_attack
