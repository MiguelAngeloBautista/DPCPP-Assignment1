#include "InverseTeleporter.h"

InverseTeleporter::InverseTeleporter() {
    itemName = "Inverse Teleporter";
    itemPrice = 400;
}

std::unordered_map<std::string, float> InverseTeleporter::multipliers() const
{
    return{ {"scrapMultiplier", 1.10},
        {"explorerSurvivalMultiplier", 0.8},
        {"operatorSurvivalMultiplier", 1.0},
        {"explorerSaveChange", 0.0},
        {"lootRecoveryMultiplier", 0.5}
    };
}

int InverseTeleporter::price() const {
    return AbstractItem::price();
}

std::string InverseTeleporter::name() const {
    return AbstractItem::name();
}