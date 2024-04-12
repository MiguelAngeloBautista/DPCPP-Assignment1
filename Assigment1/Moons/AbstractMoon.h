#ifndef ABSTRACTMOON_H
#define ABSTRACTMOON_H
#include <iostream>
#include <tuple>

class Game;

enum class MoonWeathers { Clear = 0, Flooded, Eclipsed, Stormy };



class AbstractMoon {
public:
    AbstractMoon();
    virtual ~AbstractMoon() = default;
    virtual void sendEmployees(Game& g, int count) = 0;
    virtual const std::string& name() const = 0;
    virtual std::tuple<int, int> scrapValues() const = 0;
    virtual float survivalChance() const = 0;
    virtual std::string weather() const = 0;
    virtual void onDayBegin(Game& g) const = 0;
    virtual void setWeather(MoonWeathers weather) = 0;
    virtual void sellCargo(Game& g, int amount);
    virtual int price() const = 0;
    virtual std::string type() const = 0;
protected:
    std::string moonName;
    MoonWeathers currentWeatherCondition;
    float baseSurvivalChance;
    int minScrapValue;
    int maxScrapValue;
    int moonPrice;
    std::string moonType;
};


#endif // ABSTRACTMOON_H