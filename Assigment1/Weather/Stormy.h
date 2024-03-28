#ifndef STORMY_H
#define STORMY_H
#include "Weather.h"

class Stormy : public Weather {
private:
    std::string weatherName;
public:
    Stormy();
    ~Stormy() = default;
    std::unordered_map<std::string, float> multipliers() const override;
};

#endif // STORMY_H
