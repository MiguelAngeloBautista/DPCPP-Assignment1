#ifndef APRIL_H
#define APRIL_H
#include "AbstractMoon.h"

class April : public AbstractMoon {
public:
    April();
    void onDayBegin(Game& g) const override;
    void setWeather(MoonWeathers weather) override;
    const std::string& name() const;
    void sendEmployees(Game& g, int count) override;
    std::tuple<int, int> scrapValues() const override;
    float survivalChance() const override;
    std::string weather() const override;
    int price() const;
    std::string type() const override;
};

#endif //APRIL_H