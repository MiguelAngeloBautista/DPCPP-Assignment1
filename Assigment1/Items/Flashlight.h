#ifndef FLASHLIGHT_H
#define FLASHLIGHT_H
#include "AbstractItem.h"

class Flashlight : public AbstractItem {
public:
    Flashlight();
    ~Flashlight() = default;
    std::unordered_map<std::string, float> multipliers() const override;
    int price() const override;
    std::string name() const override;
};

#endif //FLASHLIGHT_H