#ifndef ECLIPSED_H
#define ECLIPSED_H
#include "Weather.h"

class Eclipsed : public Weather {
private:
    std::string weatherName;
public:
    Eclipsed();
    ~Eclipsed() = default;
    std::unordered_map<std::string, float> multipliers() const override;
};

#endif // ECLIPSED_H
