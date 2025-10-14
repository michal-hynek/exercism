#include "space_age.h"

#include <unordered_map>

namespace space_age {

    enum class Planet {
        mercury,
        venus,
        earth,
        mars,
        jupiter,
        saturn,
        uranus,
        neptune,
    };

    const double seconds_in_earth_year = 31557600.0;

    const std::unordered_map<Planet, double> orbital_periods = {
        { Planet::mercury, 0.2408467 },
        { Planet::venus, 0.61519726 },
        { Planet::earth, 1.0 },
        { Planet::mars, 1.8808158 },
        { Planet::jupiter, 11.862615 },
        { Planet::saturn, 29.447498 },
        { Planet::uranus, 84.016846 },
        { Planet::neptune, 164.79132 },
    };

    double years_on_planet(long seconds, Planet planet) {
        double years_on_earth = seconds / seconds_in_earth_year;

        return years_on_earth / orbital_periods.at(planet);
    }

    space_age::space_age(long seconds) {
        this->age_seconds = seconds;
    }

    double space_age::on_mercury() const {
        return years_on_planet(this->age_seconds, Planet::mercury);
    }

    double space_age::on_venus() const {
        return years_on_planet(this->age_seconds, Planet::venus);
    }

    double space_age::on_earth() const {
        return years_on_planet(this->age_seconds, Planet::earth);
    }

    double space_age::on_mars() const {
        return years_on_planet(this->age_seconds, Planet::mars);
    }

    double space_age::on_jupiter() const {
        return years_on_planet(this->age_seconds, Planet::jupiter);
    }

    double space_age::on_saturn() const {
        return years_on_planet(this->age_seconds, Planet::saturn);
    }

    double space_age::on_uranus() const {
        return years_on_planet(this->age_seconds, Planet::uranus);
    }

    double space_age::on_neptune() const {
        return years_on_planet(this->age_seconds, Planet::neptune);
    }

    int space_age::seconds() const {
        return this->age_seconds;
    }

}  // namespace space_age
