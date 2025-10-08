#include "darts.h"

#include <cmath>

using namespace std;

namespace darts {

const double outer_distance = 10.0;
const double middle_distance = 5.0;
const double inner_distance = 1.0;

int score(double x, double y) {
    double x_len = abs(x);
    double y_len = abs(y);

    double distance_to_center = sqrt(x_len*x_len + y_len*y_len);

    if (distance_to_center <= outer_distance && distance_to_center > middle_distance) {
        return 1;
    } else if (distance_to_center <= middle_distance && distance_to_center > inner_distance) {
        return 5;
    } else if (distance_to_center <= inner_distance) {
        return 10;
    } else {
        return 0;
    }
}


}  // namespace d