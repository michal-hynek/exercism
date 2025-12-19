#include <stdlib.h>
#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len) {
    if (scores_len == 0) {
        return 0;
    }

    return scores[scores_len-1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
    if (scores_len == 0) {
        return 0;
    }

    int32_t best = scores[0];

    for (size_t i = 1; i < scores_len; i++) {
        if (scores[i] > best) {
            best = scores[i];
        }
    }

    return best;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output) {
    size_t output_len = 0;

    if (scores_len <= 3) {
        output_len = scores_len;
    } else {
        output_len = 3;
    }

    for (size_t i = 0; i < output_len; i++) {
        output[i] = 0;
    }

    size_t used_indices[] = {-1, -1, -1};

    for (size_t i = 0; i < output_len; i++) {
        int index = -1;

        for (size_t j = 0; j < scores_len; j++) {
            if (output[i] < scores[j] && j != used_indices[0] && j != used_indices[1]) {
                output[i] = scores[j];
                index = j;
            }
        }

        used_indices[i] = index;
    }

    return output_len;
}
