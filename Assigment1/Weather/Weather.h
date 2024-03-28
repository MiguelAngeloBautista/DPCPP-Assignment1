#ifndef WEATHER_H
#define WEATHER_H
#include <iostream>
#include <unordered_map>

class Weather {
private:
    std::string weatherName;
public:
    Weather();
    virtual ~Weather() = default;
    virtual std::unordered_map<std::string, float> multipliers() const = 0;
    virtual std::string name() const;
};

#endif // WEATHER_H