#include "Pledge.h"

Pledge::Pledge() {
    moonName = "Pledge";
    currentWeatherCondition;
    baseSurvivalChance = 0.4;
    minScrapValue = 30;
    maxScrapValue = 50;
}

void Pledge::onDayBegin(Game& g) {
    std::cout << "Current Weather: " << weather() << std::endl;

    std::cout << "> "; // Make them do the commands thingy
    // Allowed Commands: Send

}

void Pledge::setWeather(MoonWeathers weather) {
    AbstractMoon::setWeather(weather);
}

const std::string Pledge::name() const {
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