#ifndef BACKPACK_H
#define BACKPACK_H
#include "AbstractItem.h"

class Backpack : public AbstractItem {
public:
    Backpack();
    ~Backpack() = default;
    std::unordered_map<std::string, float> multipliers() const override;
    int price() const override;
    std::string name() const override;
};

#endif //BACKPACK_H