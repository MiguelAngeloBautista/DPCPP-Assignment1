#ifndef INVERSETELEPORTER_H
#define INVERSETELEPORTER_H
#include "AbstractItem.h"

class InverseTeleporter : public AbstractItem {
public:
    InverseTeleporter();
    ~InverseTeleporter() = default;
    std::unordered_map<std::string, float> multipliers() const override;
    int price() const override;
    std::string name() const override;
};

#endif //INVERSETELEPORTER_H