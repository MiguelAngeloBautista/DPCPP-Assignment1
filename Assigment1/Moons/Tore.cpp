#include "Tore.h"

Tore::Tore() {
    moonName = "Tore";
    currentWeatherCondition;
    baseSurvivalChance = 0.25;
    minScrapValue = 100;
    maxScrapValue = 130;
    moonPrice = 700;
    moonType = "Paid";
}

void Tore::onDayBegin(Game& g) const {
    AbstractMoon::onDayBegin(g);
}

void Tore::setWeather(MoonWeathers weather) {
    AbstractMoon::setWeather(weather);
}

const std::string& Tore::name() const {
    return AbstractMoon::name();
}

void Tore::sendEmployees(Game& g, int count) {
    AbstractMoon::sendEmployees(g, count);
}

std::tuple<int, int> Tore::scrapValues() const {
    return AbstractMoon::scrapValues();
}

float Tore::survivalChance() const {
    return AbstractMoon::survivalChance();
}

std::string Tore::weather() const {
    return AbstractMoon::weather();
}

int Tore::price() const {
    return AbstractMoon::price();
}

std::string Tore::type() const {
    return AbstractMoon::type();
}