#include "April.h"

April::April() {
    moonName = "April";
    currentWeatherCondition;
    baseSurvivalChance = 0.30;
    minScrapValue = 20;
    maxScrapValue = 120;
    moonPrice = 550;
    moonType = "Paid";
}

void April::onDayBegin(Game& g) const {
    AbstractMoon::onDayBegin(g);
}

void April::setWeather(MoonWeathers weather) {
    AbstractMoon::setWeather(weather);
}

const std::string& April::name() const {
    return AbstractMoon::name();
}

void April::sendEmployees(Game& g, int count) {
    AbstractMoon::sendEmployees(g, count);
}

std::tuple<int, int> April::scrapValues() const {
    return AbstractMoon::scrapValues();
}

float April::survivalChance() const {
    return AbstractMoon::survivalChance();
}

std::string April::weather() const {
    return AbstractMoon::weather();
}

int April::price() const {
    return AbstractMoon::price();
}

std::string April::type() const {
    return AbstractMoon::type();
}
