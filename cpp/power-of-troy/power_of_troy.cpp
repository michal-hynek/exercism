#include "power_of_troy.h"

#include <memory>

namespace troy {

void give_new_artifact(human& holder, std::string artifact_name) {
    holder.possession = std::make_unique<troy::artifact>(artifact_name);
}

void exchange_artifacts(std::unique_ptr<artifact>& artifact1, std::unique_ptr<artifact>& artifact2) {
    std::swap(artifact1, artifact2);
}

void manifest_power(human& holder, std::string power_effect) {
    holder.own_power = std::make_shared<troy::power>(power_effect);
}

void use_power(human& caster, human &target) {
    target.influenced_by = caster.own_power;
}

int power_intensity(human& h) {
    return h.own_power.use_count();
}

}  // namespace troy

