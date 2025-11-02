#pragma once

#include <vector>
#include <map>

using namespace std;

namespace etl {

    map<char, int> transform(map<int, vector<char>> old_map);

}  // namespace etl
