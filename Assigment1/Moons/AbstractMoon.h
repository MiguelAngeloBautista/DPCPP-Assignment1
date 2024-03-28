#ifndef ABSTRACTMOON_H
#define ABSTRACTMOON_H
#include <iostream>
#include <tuple>

#include "../Game.h"
#include "../Weather/Clear.h"
#include "../Weather/Eclipsed.h"
#include "../Weather/Flooded.h"
#include "../Weather/Stormy.h"

class AbstractMoon {
public:
    AbstractMoon();
    virtual ~AbstractMoon() = default;

    virtual void sendEmployees(Game& g, int count);

    virtual std::string name() const;

    virtual std::tuple<int, int> scrapValues() const;

    virtual float survivalChance() const;

    virtual Weather* weather() const;

    virtual void onDayBegin(Game& g);

protected:
    // Simulator simulator;
    std::string moonName;
    Weather* currentWeatherCondition;
    static enum MoonWeather {CLear = 0, Flooded, Eclipsed, Stormy};
    float baseSurvivalChance;
    int minScrapValue;
    int maxScrapValue;
};


#endif // ABSTRACTMOON_H