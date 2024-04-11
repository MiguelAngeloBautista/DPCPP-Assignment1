#ifndef CORPORATION_H
#define CORPORATION_H
#include "AbstractMoon.h"

class Game;

class Corporation : public AbstractMoon {
public:
    Corporation();
    void sellCargo(Game& g, int amount);
    void onDayBegin(Game& g) override;
    void setWeather(MoonWeathers weather) override;
    const std::string name() const;
    void sendEmployees(Game& g, int count) override;
    std::tuple<int, int> scrapValues() const override;
    float survivalChance() const override;
    std::string weather() const override;
////public:
//    std::string moonName;
//    MoonWeathers currentWeatherCondition;
//    float baseSurvivalChance;
//    int minScrapValue;
//    int maxScrapValue;
};

#endif // CORPORATION_H