#include "Pledge.h"

Pledge::Pledge() {
    moonName = "Pledge";
    currentWeatherCondition;
    baseSurvivalChance = 0.4;
    minScrapValue = 30;
    maxScrapValue = 50;
}

void Pledge::onDayBegin(Game& g) const {
    AbstractMoon::onDayBegin(g);
}

void Pledge::setWeather(MoonWeathers weather) {
    AbstractMoon::setWeather(weather);
}

const std::string& Pledge::name() const {
    return AbstractMoon::name();
}

void Pledge::sendEmployees(Game& g, int count) {
    AbstractMoon::sendEmployees(g, count);
}

std::tuple<int, int> Pledge::scrapValues() const {
    return AbstractMoon::scrapValues();
}

float Pledge::survivalChance() const {
    return AbstractMoon::survivalChance();
}

std::string Pledge::weather() const {
    return AbstractMoon::weather();
}

int Pledge::price() const {
    return AbstractMoon::price();
}

std::string Pledge::type() const {
    return AbstractMoon::type();
}
