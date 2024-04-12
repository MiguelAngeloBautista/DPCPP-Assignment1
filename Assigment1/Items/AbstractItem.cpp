#include "AbstractItem.h"

AbstractItem::AbstractItem() {
    itemName = "ABSTRACT ITEM";
    itemPrice = 0;
}

std::unordered_map<std::string, float> AbstractItem::multipliers() const
{
    return{ {"scrapMultiplier", 1.0},
        {"explorerSurvivalMultiplier", 1.0},
        {"operatorSurvivalMultiplier", 1.0},
        {"explorerSaveChance", 0.0},
        {"lootRecoveryMultiplier", 0.5}
    };
}

int AbstractItem::price() const{
    return itemPrice;
}

std::string AbstractItem::name() const {
    return itemName;
}
