#include "Flooded.h"

Flooded::Flooded() {
    weatherName = "Flooded";
}

std::unordered_map<std::string, float> Flooded::multipliers() const {
    return { {"explorerSurvivalMultiplier", 0.7} };
}