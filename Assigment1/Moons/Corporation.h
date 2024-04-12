#ifndef CORPORATION_H
#define CORPORATION_H
#include "AbstractMoon.h"

class Game;

class Corporation : public AbstractMoon {
public:
    Corporation();
    void sellCargo(Game& g, int amount) override;
    void onDayBegin(Game& g) const override;
    void setWeather(MoonWeathers weather) override;
    const std::string& name() const;
    void sendEmployees(Game& g, int count) override;
    std::tuple<int, int> scrapValues() const override;
    float survivalChance() const override;
    std::string weather() const override;
    int price() const override;
    std::string type() const override;
};

#endif // CORPORATION_H