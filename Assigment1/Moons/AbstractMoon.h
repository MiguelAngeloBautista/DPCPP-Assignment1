#ifndef ABSTRACTMOON_H
#define ABSTRACTMOON_H
#include <iostream>
#include <tuple>

//#include "../Weather/Clear.h"
//#include "../Weather/Eclipsed.h"
//#include "../Weather/Flooded.h"
//#include "../Weather/Stormy.h"

class Game;

enum class MoonWeathers { Clear = 0, Flooded, Eclipsed, Stormy };



class AbstractMoon {
public:
    AbstractMoon();
    virtual ~AbstractMoon() = default;
    virtual void sendEmployees(Game& g, int count) = 0;
    virtual const std::string name() const = 0;
    virtual std::tuple<int, int> scrapValues() const = 0;
    virtual float survivalChance() const = 0;
    virtual std::string weather() const = 0;
    virtual void onDayBegin(Game& g) = 0;
    virtual void setWeather(MoonWeathers weather) = 0;
    virtual void sellCargo(Game& g, int amount);
protected:
    std::string moonName;
    MoonWeathers currentWeatherCondition;
    float baseSurvivalChance;
    int minScrapValue;
    int maxScrapValue;
};


#endif // ABSTRACTMOON_H