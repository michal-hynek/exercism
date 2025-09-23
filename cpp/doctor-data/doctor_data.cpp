#include <string>
#include "doctor_data.h"

heaven::Vessel::Vessel(std::string name, int generation) {
    this->name = name;
    this->generation = generation;
    this->current_system = star_map::System::Sol;
    this->busters = 0;
}

heaven::Vessel::Vessel(std::string name, int generation, star_map::System system = star_map::System::Sol) {
    this->name = name;
    this->generation = generation;
    this->current_system = system;
    this->busters = 0;
}

heaven::Vessel heaven::Vessel::replicate(std::string name) {
    heaven::Vessel *replicated_vessel = new heaven::Vessel(name, this->generation + 1, this->current_system);
    return *replicated_vessel;
}

void heaven::Vessel::make_buster() {
    this->busters++;
}

bool heaven::Vessel::shoot_buster() {
    if (this->busters > 0)  {
        this->busters--;
        return true;
    } else {
        return false;
    }
}

std::string heaven::get_older_bob(heaven::Vessel vessel1, heaven::Vessel vessel2) {
    if (vessel1.generation < vessel2.generation) {
        return vessel1.name;
    } else {
        return vessel2.name;
    }
}

bool heaven::in_the_same_system(heaven::Vessel vessel1, heaven::Vessel vessel2) {
    return vessel1.current_system == vessel2.current_system;
}