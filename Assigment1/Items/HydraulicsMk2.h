#ifndef HYDRAULICS_H
#define HYDRAULICS_H
#include "AbstractItem.h"

class HydraulicsMk2 : public AbstractItem {
public:
    HydraulicsMk2();
    ~HydraulicsMk2() = default;
    std::unordered_map<std::string, float> multipliers() const override;
    int price() const override;
    std::string name() const override;
};

#endif //HYDRAULICS_H