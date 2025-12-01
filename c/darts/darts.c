#include <stdlib.h>
#include <math.h>

#include "darts.h"

float distance_to_center(coordinate_t pos) {
    float x_dist = fabs(pos.x);
    float y_dist = fabs(pos.y);

    return sqrt(x_dist*x_dist + y_dist*y_dist);
}

int score(coordinate_t pos) {
    float dist = distance_to_center(pos);

    if (dist <= 1.0) {
        return 10;
    } else if (dist <= 5.0) {
        return 5;
    } else if (dist <= 10.0) {
        return 1;
    } else {
        return 0;
    }
}