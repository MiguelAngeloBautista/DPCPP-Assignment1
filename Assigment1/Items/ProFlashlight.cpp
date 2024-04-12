#include "ProFlashlight.h"

ProFlashlight::ProFlashlight() {
    itemName = "Pro Flashlight";
    itemPrice = 200;
}

std::unordered_map<std::string, float> ProFlashlight::multipliers() const
{
    return{ {"scrapMultiplier", 1.0},
        {"explorerSurvivalMultiplier", 1.10},
        {"operatorSurvivalMultiplier", 1.0},
        {"explorerSaveChange", 0.0},
        {"lootRecoveryMultiplier", 0.5}
    };
}

int ProFlashlight::price() const {
    return AbstractItem::price();
}

std::string ProFlashlight::name() const {
    return AbstractItem::name();
}