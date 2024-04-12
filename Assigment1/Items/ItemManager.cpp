#include "ItemManager.h"

std::unordered_map<std::string, AbstractItem*> ItemManager::store() {
    return allGameItems;
}

std::unordered_map<std::string, AbstractItem*> ItemManager::inventory() {
    return boughtItems;
}

void ItemManager::buy(std::string item) {
    AbstractItem* temp = allGameItems[item];
    boughtItems[temp->name()] = temp;
}

void ItemManager::registerItem(AbstractItem* item) {
    allGameItems[item->name()] = item;
}
