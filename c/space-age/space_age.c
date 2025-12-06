#include "space_age.h"

static const float SECONDS_IN_YEAR = 365.25 * 24.0 * 60.0 * 60.0;

float orbital_period(planet_t planet) {
    switch (planet) {
        case MERCURY:
            return 0.2408467;
        case VENUS:
            return 0.61519726;
        case EARTH:
            return 1.0;
        case MARS:
            return 1.8808158;
        case JUPITER:
            return 11.862615;
        case SATURN:
            return 29.447498;
        case URANUS:
            return 84.016846;
        case NEPTUNE:
            return 164.79132;
        default:
            return -1.0;
    }
}

float age(planet_t planet, int64_t seconds) {
    float earth_years = seconds / SECONDS_IN_YEAR;
    float period = orbital_period(planet);

    if (period == -1.0) {
        return -1.0;
    }

    return earth_years / orbital_period(planet);
}