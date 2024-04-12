#include "Teleporter.h"

Teleporter::Teleporter() {
    itemName = "Teleporter";
    itemPrice = 300;
}

std::unordered_map<std::string, float> Teleporter::multipliers() const
{
    return{ {"scrapMultiplier", 1.0},
        {"explorerSurvivalMultiplier", 1.0},
        {"operatorSurvivalMultiplier", 1.0},
        {"explorerSaveChange", 0.33},
        {"lootRecoveryMultiplier", 0.5}
    };
}

int Teleporter::price() const {
    return AbstractItem::price();
}

std::string Teleporter::name() const {
    return AbstractItem::name();
}