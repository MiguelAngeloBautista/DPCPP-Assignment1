#include "Corporation.h"
#include "../Game.h"

class Game;

Corporation::Corporation() {
    moonName = "Corporation";
    currentWeatherCondition = MoonWeathers::Clear();
    baseSurvivalChance = 1.0;
    minScrapValue = 0;
    maxScrapValue = 0;
}

void Corporation::sellCargo(Game& g, int amount) {
    g.addCargoValue(-amount); // add cargo value my (-amount)
    g.addBalance(amount);
}


void Corporation::onDayBegin(Game& g) {
    std::cout << "Current Weather: " << weather() << std::endl;

    std::cout << "> "; // Make them do the commands thingy
    // Allowed Commands: Sell

}

// Disable Setting weather for this moon
void Corporation::setWeather(MoonWeathers weather) {

}

const std::string Corporation::name() const {
    return AbstractMoon::name();
}

void Corporation::sendEmployees(Game& g, int count) {

}

std::tuple<int, int> Corporation::scrapValues() const {

    return AbstractMoon::scrapValues();
}

float Corporation::survivalChance() const {
    return AbstractMoon::survivalChance();
}

std::string Corporation::weather() const
{
    return AbstractMoon::weather();
}
