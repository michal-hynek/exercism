#include "diamond.h"

namespace diamond {

    vector<string> rows(char c) {
        if (c == 'A') {
            return vector<string>{"A"};
        }

        vector<string> rows{};

        int row_count = c - 'A' + 1;
        int row_width = 2*row_count - 1;

        int left_pos = row_width/2;
        int right_pos = left_pos;
        char curr_char = 'A';
        int char_inc = 1;

        for (int i = 0; i < (2*row_count)-1; ++i) {
            string new_row(row_width, ' ');

            new_row[left_pos] = curr_char;
            new_row[right_pos] = curr_char;

            if (left_pos == 0) {
                char_inc = -1;
            }

            if (char_inc == 1) {
                left_pos--;
                right_pos++;
            } else {
                left_pos++;
                right_pos--;

            }

            curr_char += char_inc;

            rows.push_back(new_row);
        }

        return rows;
    }

}  // namespace diamond
