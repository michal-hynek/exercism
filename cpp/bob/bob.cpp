#include "bob.h"

#include <cctype>

namespace bob {

    string trim(string input) {
        string trimmed = "";

        bool found_start = false;

        for (unsigned int i = 0; i < input.length(); ++i) {
            if (!found_start && isspace(input.at(i))) {
                continue;
            }

            found_start = true;
            trimmed.push_back(input.at(i));
        }

        int rightmost_char_index = trimmed.length()-1;
        while (rightmost_char_index >= 0 && isspace(input.at(rightmost_char_index))) {
            rightmost_char_index--;
        }

        return trimmed.erase(rightmost_char_index+1);
    }

    bool is_question(string phrase) {
        if (phrase.length() == 0) {
            return false;
        }

        return phrase.at(phrase.length()-1) == '?';
    }

    bool yelling(string phrase) {
        bool found_upper_case = false;

        for (unsigned int i = 0; i < phrase.length(); i++) {
            if (islower(phrase.at(i))) {
                return false;
            }

            if (isupper(phrase.at(i))) {
                found_upper_case = true;
            }
        }

        return found_upper_case;
    }

    bool silence(string phrase) {
        for (unsigned int i = 0; i < phrase.length(); i++) {
            if (!isspace(phrase.at(i))) {
                return false;
            }
        }

        return true;
    }

    string hey(string phrase) {
        string trimmed_phrase = trim(phrase);

        if (is_question(trimmed_phrase) && yelling(trimmed_phrase)) {
            return "Calm down, I know what I'm doing!";
        }

        if (is_question(trimmed_phrase)) {
            return "Sure.";
        }

        if (yelling(trimmed_phrase)) {
            return "Whoa, chill out!";
        }

        if (silence(trimmed_phrase)) {
            return "Fine. Be that way!";
        }

        return "Whatever.";
    }

}  // namespace bob
