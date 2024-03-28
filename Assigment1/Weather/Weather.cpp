#include "Weather.h"

Weather::Weather() {
    weatherName = "Abstract Weather";
}

std::unordered_map<std::string, float> multipliers() {
    return { {"scrapMultiplier", 1.0},{"explorerSurvivalMultiplier", 1.0},{"operatorSurvivalMultiplier", 1.0} };
}

std::string Weather::name() const {
    return weatherName;
}