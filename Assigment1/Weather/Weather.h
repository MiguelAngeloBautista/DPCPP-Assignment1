#ifndef WEATHER_H
#define WEATHER_H
#include <iostream>
#include <unordered_map>

class Weather {
protected:
    std::string weatherName;
public:
    Weather();
    std::unordered_map<std::string, float> multipliers();
    ~Weather() = default;
    /*virtual std::unordered_map<std::string, float> multipliers() const;*/
    std::string name() const;
};

#endif // WEATHER_H