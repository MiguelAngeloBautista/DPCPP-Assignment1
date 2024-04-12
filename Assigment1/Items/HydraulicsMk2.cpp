#include "HydraulicsMk2.h"

HydraulicsMk2::HydraulicsMk2() {
    itemName = "HydraulicsMk2";
    itemPrice = 1000;
}

std::unordered_map<std::string, float> HydraulicsMk2::multipliers() const
{
    return{ {"scrapMultiplier", 1.0},
        {"explorerSurvivalMultiplier", 1.0},
        {"operatorSurvivalMultiplier", 1.25},
        {"explorerSaveChange", 0.0},
        {"lootRecoveryMultiplier", 0.5}
    };
}

int HydraulicsMk2::price() const {
    return AbstractItem::price();
}

std::string HydraulicsMk2::name() const {
    return AbstractItem::name();
}