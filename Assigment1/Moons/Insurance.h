#ifndef INSURANCE_H
#define INSURANCE_H
#include "AbstractMoon.h"

class Insurance : public AbstractMoon {
public:
    Insurance();
    void onDayBegin(Game& g) override;
    void setWeather(MoonWeathers weather) override;
    const std::string name() const;
    void sendEmployees(Game& g, int count) override;
    std::tuple<int, int> scrapValues() const override;
    float survivalChance() const override;
    std::string weather() const override;
};

#endif // INSURANCE_H
