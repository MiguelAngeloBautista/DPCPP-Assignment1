#ifndef FLOODED_H
#define FLOODED_H
#include "Weather.h"

class Flooded : public Weather {
private:
    std::string weatherName;
public:
    Flooded();
    ~Flooded() = default;
    std::unordered_map<std::string, float> multipliers() const override;
};

#endif // FLOODED_H
