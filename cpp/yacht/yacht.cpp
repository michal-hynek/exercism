#include "yacht.h"

#include <unordered_map>

namespace yacht {

    unordered_map<int, int> dice_value_counts(vector<int> dice_vals) {
        unordered_map<int, int> counts{};

        for (auto val : dice_vals) {
            if (counts.find(val) == counts.end()) {
                counts.emplace(val, 1);
            } else {
                counts.at(val)++;
            }
        }

        return counts;
    }

    int score_vals(vector<int> dice_vals, int target_val) {
        int score = 0;

        for (auto val : dice_vals) {
            if (val == target_val) {
                score += val;
            }
        }

        return score;
    }

    int score_full_house(vector<int> dice_vals) {
        auto val_counts = dice_value_counts(dice_vals);

        if (val_counts.size() != 2) {
            return 0;
        }

        int score = 0;
        for (const auto &pair : val_counts) {
            if (pair.second != 2 && pair.second != 3) {
                return 0;
            }

            score += pair.first * pair.second;
        }


        return score;
    }

    int score_n_of_kind(vector<int> dice_vals, int n) {
        auto val_counts = dice_value_counts(dice_vals);

        for (const auto& pair : val_counts) {
            if (pair.second >= n) {
                return pair.first * n;
            }
        }

        return 0;
    }

    int score_straight(vector<int> dice_values, int start) {
        auto val_counts = dice_value_counts(dice_values);

        if (val_counts.size() != 5 || val_counts.find(start) == val_counts.end()) {
            return 0;
        }

        int max_val = start + 4;

        for (const auto &pair : val_counts) {
            if (pair.first < start || pair.first > max_val) {
                return 0;
            }
        }

        return 30;
    }

    int score_choice(vector<int> dice_vals) {
        int score = 0;

        for (auto val : dice_vals) {
            score += val;
        }

        return score;
    }

    int score(vector<int> dice_vals, string category) {
        if (category == "ones") {
            return score_vals(dice_vals, 1);
        } else if (category == "twos") {
            return score_vals(dice_vals, 2);
        } else if (category == "threes") {
            return score_vals(dice_vals, 3);
        } else if (category == "fours") {
            return score_vals(dice_vals, 4);
        } else if (category == "fives") {
            return score_vals(dice_vals, 5);
        } else if (category == "sixes") {
            return score_vals(dice_vals, 6);
        } else if (category == "full house") {
            return score_full_house(dice_vals);
        } else if (category == "four of a kind") {
            return score_n_of_kind(dice_vals, 4);
        } else if (category == "little straight") {
            return score_straight(dice_vals, 1);
        } else if (category == "big straight") {
            return score_straight(dice_vals, 2);
        } else if (category == "choice") {
            return score_choice(dice_vals);
        } else if (category == "yacht" && score_n_of_kind(dice_vals, 5) > 0) {
            return 50;
        }

        return 0;
    }

}  // namespace yacht
