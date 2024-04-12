#include "ItemManager.h"

std::unordered_map<std::string, AbstractItem*> ItemManager::store() {
    return allGameItems;
}

std::unordered_map<std::string, AbstractItem*> ItemManager::inventory() {
    return boughtItems;
}

bool ItemManager::buy(std::string item) {
    AbstractItem* temp = allGameItems[item];
    if (temp == nullptr) {
        return false;
    }
    else {
        boughtItems[temp->name()] = temp;
        return true;
    }
    
}

void ItemManager::registerItem(AbstractItem* item) {
    allGameItems[item->name()] = item;
}
