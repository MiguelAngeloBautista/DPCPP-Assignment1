#ifndef TELEPORTER_H
#define TELEPORTER_H
#include "AbstractItem.h"

class Teleporter : public AbstractItem {
public:
    Teleporter();
    ~Teleporter() = default;
    std::unordered_map<std::string, float> multipliers() const override;
    int price() const override;
    std::string name() const override;
};

#endif //TELEPORTER_H