#pragma once

#include <vector>
#include <string>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(std::vector<std::string> layers);
int preparationTime(std::vector<std::string> layers, int prep_time);
amount quantities(std::vector<std::string> layers);
void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendsList);
void addSecretIngredient(std::vector<std::string>& myList, std::string secretIngredient);
std::vector<double> scaleRecipe(std::vector<double> quantities, int portions);

}  // namespace lasagna_master
