#include "Shovel.h"

Shovel::Shovel() {
    itemName = "Shovel";
    itemPrice = 100;
}

std::unordered_map<std::string, float> Shovel::multipliers() const
{
    return{ {"scrapMultiplier", 1.0},
        {"explorerSurvivalMultiplier", 1.05},
        {"operatorSurvivalMultiplier", 1.0},
        {"explorerSaveChange", 0.0},
        {"lootRecoveryMultiplier", 0.5}
    };
}

int Shovel::price() const {
    return AbstractItem::price();
}

std::string Shovel::name() const {
    return AbstractItem::name();
}