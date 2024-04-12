#include "Hyperion.h"

Hyperion::Hyperion() {
    moonName = "Hyperion";
    currentWeatherCondition;
    baseSurvivalChance = 0.20;
    minScrapValue = 100;
    maxScrapValue = 150;
    moonPrice = 900;
    moonType = "Paid";
}

void Hyperion::onDayBegin(Game& g) const {
    AbstractMoon::onDayBegin(g);
}

void Hyperion::setWeather(MoonWeathers weather) {
    AbstractMoon::setWeather(weather);
}

const std::string& Hyperion::name() const {
    return AbstractMoon::name();
}

void Hyperion::sendEmployees(Game& g, int count) {
    AbstractMoon::sendEmployees(g, count);
}

std::tuple<int, int> Hyperion::scrapValues() const {
    return AbstractMoon::scrapValues();
}

float Hyperion::survivalChance() const {
    return AbstractMoon::survivalChance();
}

std::string Hyperion::weather() const {
    return AbstractMoon::weather();
}

int Hyperion::price() const {
    return AbstractMoon::price();
}

std::string Hyperion::type() const {
    return AbstractMoon::type();
}