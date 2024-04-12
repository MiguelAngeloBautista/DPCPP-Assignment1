#include "Defense.h"

Defense::Defense() {
    moonName = "Defense";
    currentWeatherCondition;
    baseSurvivalChance = 0.35;
    minScrapValue = 10;
    maxScrapValue = 70;
}

void Defense::onDayBegin(Game& g) const {
    AbstractMoon::onDayBegin(g);
}

void Defense::setWeather(MoonWeathers weather) {
    AbstractMoon::setWeather(weather);
}

const std::string& Defense::name() const {
    return AbstractMoon::name();
}

void Defense::sendEmployees(Game& g, int count) {
    AbstractMoon::sendEmployees(g, count);
}

std::tuple<int, int> Defense::scrapValues() const {
    return AbstractMoon::scrapValues();
}

float Defense::survivalChance() const {
    return AbstractMoon::survivalChance();
}

std::string Defense::weather() const {
    return AbstractMoon::weather();
}