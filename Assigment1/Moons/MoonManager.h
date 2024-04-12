#ifndef MOONMANAGER_H
#define MOONMANAGER_H
#include <unordered_map>
#include "AbstractMoon.h"



class MoonManager {
public:
    MoonManager();
    ~MoonManager();
    const std::unordered_map<std::string, AbstractMoon*> moons() const;
    AbstractMoon* route(std::string moon);
    void registerMoon(AbstractMoon* moon);
    void regenerateWeather();
private:
    std::unordered_map<std::string, AbstractMoon*> allGameMoons;
};

#endif // MOONMANAGER_H