#include "Stormy.h"

Stormy::Stormy() {
    weatherName = "Stormy";
}

std::unordered_map<std::string, float> Stormy::multipliers() const {
    return { {"scrapMultiplier", 0.75} };
}