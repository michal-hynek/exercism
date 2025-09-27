#include "lasagna_master.h"

namespace lasagna_master {

    int preparationTime(std::vector<std::string> layers) {
        return preparationTime(layers, 2);
    }

    int preparationTime(std::vector<std::string> layers, int layerPrepTime=2) {
        return layers.size() * layerPrepTime;
    }

    amount quantities(std::vector<std::string> layers) {
        int noodles = 0;
        double sauce = 0.0;

        for (unsigned int i = 0; i < layers.size(); ++i) {
            if (layers.at(i) == "noodles") {
                noodles += 50;
            }

            if (layers.at(i) == "sauce") {
                sauce += 0.2;
            }
        }

        return amount{ noodles, sauce };
    }

    void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendsList) {
        myList.at(myList.size() - 1) = friendsList.at(friendsList.size() - 1);
    }

    void addSecretIngredient(std::vector<std::string>& myList, std::string secretIngredient) {
        myList.at(myList.size() - 1) = secretIngredient;
    }

    std::vector<double> scaleRecipe(std::vector<double> quantities, int portions) {
        double ratio = static_cast<double>(portions) / 2.0;
        std::vector<double> scaledQuantities{};

        for (unsigned int i = 0; i < quantities.size(); ++i) {
            scaledQuantities.emplace_back(quantities.at(i) * ratio);
        }

        return scaledQuantities;
    }

}  // namespace lasagna_master
