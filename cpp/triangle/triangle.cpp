#include "triangle.h"

#include <stdexcept>

namespace triangle {

    bool is_triangle(double a, double b, double c) {
        if (a == 0 || b == 0 || c == 0) {
            return false;
        }

        return a + b >= c && a + c >= b && b + c >= a;
    }

    flavor kind(double a, double b, double c) {
        if (!is_triangle(a, b, c)) {
            throw std::domain_error("not a triangle");
        }

        if (a == b && b == c) {
            return flavor::equilateral;
        } else if (a == b || a == c || b == c) {
            return flavor::isosceles;
        } else {
            return flavor::scalene;
        }
    }


}  // namespace triangle
