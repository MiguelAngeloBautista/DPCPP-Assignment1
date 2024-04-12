#include "Insurance.h"

Insurance::Insurance() {
    moonName = "Insurance";
    currentWeatherCondition;
    baseSurvivalChance = 0.45;
    minScrapValue = 5;
    maxScrapValue = 50;
}

void Insurance::onDayBegin(Game& g) const {
    AbstractMoon::onDayBegin(g);
}

void Insurance::setWeather(MoonWeathers weather) {
    AbstractMoon::setWeather(weather);
}

const std::string& Insurance::name() const {
    return AbstractMoon::name();
}

void Insurance::sendEmployees(Game& g, int count) {
    AbstractMoon::sendEmployees(g, count);
}

std::tuple<int, int> Insurance::scrapValues() const {
    return AbstractMoon::scrapValues();
}

float Insurance::survivalChance() const {
    return AbstractMoon::survivalChance();
}

std::string Insurance::weather() const {
    return AbstractMoon::weather();
}