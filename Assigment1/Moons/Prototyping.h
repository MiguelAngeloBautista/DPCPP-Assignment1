#ifndef PROTOTYPING_H
#define PROTOTYPING_H
#include "AbstractMoon.h"

class Game;

class Prototyping : public AbstractMoon {
public:
    Prototyping();
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

#endif // PROTOTYPING_H