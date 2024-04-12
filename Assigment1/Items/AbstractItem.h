#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H
#include <iostream>
#include <unordered_map>

class AbstractItem {
public:
    AbstractItem();
    ~AbstractItem() = default;
    virtual std::unordered_map<std::string, float> multipliers() const = 0;
    virtual int price() const = 0;
    virtual std::string name() const = 0;
protected:
    std::string itemName;
    int itemPrice;
    
};

#endif //ABSTRACTITEM_H