#include "Backpack.h"

Backpack::Backpack() {
    itemName = "Backpack";
    itemPrice = 500;
}

std::unordered_map<std::string, float> Backpack::multipliers() const
{
    return{ {"scrapMultiplier", 1.0},
        {"explorerSurvivalMultiplier", 1.0},
        {"operatorSurvivalMultiplier", 1.0},
        {"explorerSaveChange", 0.0},
        {"lootRecoveryMultiplier", 1.25}
    };
}

int Backpack::price() const {
    return AbstractItem::price();
}

std::string Backpack::name() const {
    return AbstractItem::name();
}