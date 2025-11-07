#include "pascals_triangle.h"

namespace pascals_triangle {

    vector<vector<int>> generate_rows(int num_of_rows) {
        vector<vector<int>> rows{};

        for (int i = 0; i < num_of_rows; ++i) {
            if (i == 0) {
                rows.push_back(vector<int>{1});
                continue;
            }

            vector<int> row{1};

            for (unsigned int j = 1; j < rows.at(i-1).size(); ++j) {
                row.push_back(rows.at(i-1).at(j-1) + rows.at(i-1).at(j));
            }

            row.push_back(1);

            rows.push_back(row);
        }

        return rows;
    }

}  // namespace pascals_triangle
