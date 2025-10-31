#include "secret_handshake.h"

#include <algorithm>

namespace secret_handshake {

    const vector<string> command_codes{"wink", "double blink", "close your eyes", "jump"};

    vector<string> commands(int num) {
        vector<string> commands{};

        for (unsigned int i = 0; i < 4; ++i) {
            if (((1 << i) & num) != 0) {
                commands.push_back(command_codes[i]);
            }
        }

        bool should_reverse = ((1 << 4) & num) != 0;

        if (should_reverse) {
            reverse(commands.begin(), commands.end());
        }

        return commands;
    }

}  // namespace secret_handshake
