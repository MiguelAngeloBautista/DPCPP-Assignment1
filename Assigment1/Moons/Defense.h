#ifndef DEFENSE_H
#define DEFENSE_H
#include "AbstractMoon.h"

class Defense : public AbstractMoon {
public:
    Defense();
    void onDayBegin(Game& g) const override;
    void setWeather(MoonWeathers weather) override;
    const std::string& name() const;
    void sendEmployees(Game& g, int count) override;
    std::tuple<int, int> scrapValues() const override;
    float survivalChance() const override;
    std::string weather() const override;
};

#endif // DEFENSE_H
