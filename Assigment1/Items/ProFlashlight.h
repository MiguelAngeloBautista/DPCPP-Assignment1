#ifndef PROFLASHLIGHT_H
#define PROFLASHLIGHT_H
#include "AbstractItem.h"

class ProFlashlight : public AbstractItem {
public:
    ProFlashlight();
    ~ProFlashlight() = default;
    std::unordered_map<std::string, float> multipliers() const override;
    int price() const override;
    std::string name() const override;
};

#endif //PROFLASHLIGHT_H