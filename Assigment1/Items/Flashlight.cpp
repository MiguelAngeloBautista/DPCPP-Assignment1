#include "Flashlight.h"

Flashlight::Flashlight() {
    itemName = "Flashlight";
    itemPrice = 60;
}

std::unordered_map<std::string, float> Flashlight::multipliers() const
{
    return{ {"scrapMultiplier", 1.0},
        {"explorerSurvivalMultiplier", 1.05},
        {"operatorSurvivalMultiplier", 1.0},
        {"explorerSaveChange", 0.0},
        {"lootRecoveryMultiplier", 0.5}
    };
}

int Flashlight::price() const {
    return AbstractItem::price();
}

std::string Flashlight::name() const {
    return AbstractItem::name();
}
