#include "speedywagon.h"

namespace speedywagon {

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

bool connection_check(pillar_men_sensor* sensor) {
    return sensor != nullptr;
}

int activity_counter(pillar_men_sensor* first_sensor, int sensor_count) {
    int activity = 0;
    pillar_men_sensor* current_sensor = first_sensor;

    for (int i = 0; i < sensor_count; ++i) {
        activity += current_sensor->activity;
        current_sensor++; 
    }

    return activity;
}

bool alarm_control(pillar_men_sensor* sensor) {
    if (connection_check(sensor)) {
        return sensor->activity > 0;
    } else {
        return false;
    }
}

bool uv_alarm(pillar_men_sensor* sensor) {
    if (connection_check(sensor)) {
        return uv_light_heuristic(&(sensor->data)) > sensor->activity;
    } else {
        return false;
    }
}

}  // namespace speedywagon
