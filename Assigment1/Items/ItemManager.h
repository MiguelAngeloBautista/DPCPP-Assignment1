#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H
#include <unordered_map>
#include "AbstractItem.h"

class Game;

class ItemManager {
public:
    ~ItemManager();
    std::unordered_map<std::string, AbstractItem*> store(); // Returns allGameItems
    std::unordered_map<std::string, AbstractItem*> inventory(); // Returns boughItems
    bool buy(Game& g, std::string item);
    void registerItem(AbstractItem* item);
private:
    std::unordered_map<std::string, AbstractItem*> allGameItems;
    std::unordered_map<std::string, AbstractItem*> boughtItems;
};

#endif //ITEMMANAGER_H