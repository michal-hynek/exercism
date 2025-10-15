#include "matching_brackets.h"

namespace matching_brackets {

    bool check(string input) {
        unsigned int last_bracket = 0;
        string opening_brackets = "";

        for (unsigned int i = 0; i < input.length(); ++i) {
            char c = input.at(i);

            if (c == '(' || c == '{' || c == '[') {
                if (last_bracket >= input.length()) {
                    input.push_back(c);
                } else {
                    input[last_bracket] = c;
                }

                last_bracket++;
            } else if (c == ')' || c == '}' || c == ']') {
                if (last_bracket == 0) {
                    return false;
                }

                char bracket = input.at(last_bracket-1);

                if ((c == ')' && bracket != '(') || (c == '}' && bracket != '{') || (c == ']' && bracket != '[')) {
                    return false;
                }

                last_bracket--;
            }

        }

        return last_bracket == 0;
    }

}  // namespace matching_brackets
