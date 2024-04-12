#include "ItemManager.h"
#include "../Game.h"

ItemManager::~ItemManager() {
    for (auto& item : boughtItems) {
        delete item.second;
        item.second = nullptr;
    }
    boughtItems.clear();

    for (auto& item : allGameItems) {
        delete item.second;
        item.second = nullptr;
    }
    allGameItems.clear();
}

std::unordered_map<std::string, AbstractItem*> ItemManager::store() {
    return allGameItems;
}

std::unordered_map<std::string, AbstractItem*> ItemManager::inventory() {
    return boughtItems;
}

bool ItemManager::buy(Game& g,std::string item) {
    AbstractItem* temp = allGameItems[item];
    if (temp == nullptr) {
        return false;
    }
    else {
        if (boughtItems.contains(temp->name())) {
            std::cout << "You already own a " << temp->name() << std::endl;
            return true;
        }

        boughtItems[temp->name()] = temp;
        g.addBalance(-temp->price());
        return true;
    }
    
}

void ItemManager::registerItem(AbstractItem* item) {
    allGameItems[item->name()] = item;
}
