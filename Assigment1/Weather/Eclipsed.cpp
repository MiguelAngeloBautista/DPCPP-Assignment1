#include "Eclipsed.h"

Eclipsed::Eclipsed() {
    weatherName = "Eclipsed";
}

std::unordered_map<std::string, float> Eclipsed::multipliers() const {
    return { {"explorerSurvivalMultiplier", 0.9}, {"operatorSurvivalMultiplier", 0.7} };
}