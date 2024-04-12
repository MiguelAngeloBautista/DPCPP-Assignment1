#ifndef SHOVEL_H
#define SHOVEL_H
#include "AbstractItem.h"

class Shovel : public AbstractItem{
public:
    Shovel();
    ~Shovel() = default;
    std::unordered_map<std::string, float> multipliers() const override;
    int price() const override;
    std::string name() const override;
};

#endif //SHOVEL_H