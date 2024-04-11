#include "Prototyping.h"

Prototyping::Prototyping() {
    moonName = "Prototyping";
    currentWeatherCondition;
    baseSurvivalChance = 0.5;
    minScrapValue = 3;
    maxScrapValue = 30;
}

void Prototyping::onDayBegin(Game& g) {
    std::cout << "Current Weather: " << weather() << std::endl;

    std::cout << "> "; // Make them do the commands thingy
    // Allowed Commands: Send

}

void Prototyping::setWeather(MoonWeathers weather) {
    AbstractMoon::setWeather(weather);
}

const std::string Prototyping::name() const {
    return AbstractMoon::name();
}

void Prototyping::sendEmployees(Game& g, int count) {
    AbstractMoon::sendEmployees(g, count);
}

std::tuple<int, int> Prototyping::scrapValues() const {
    return AbstractMoon::scrapValues();
}

float Prototyping::survivalChance() const {
    return AbstractMoon::survivalChance();
}

std::string Prototyping::weather() const {
    return AbstractMoon::weather();
}