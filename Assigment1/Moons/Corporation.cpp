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


void Corporation::onDayBegin(Game& g) const {
    std::cout << "\nWELCOME TO " << name() << "!\n" << std::endl;
    g.printNewDay();
    std::cout << "Number of employees: " << g.getAliveEmployees() << std::endl;
    
    std::cout << "\nType SELL to sell your cargo contents and increase your balance and achieve quota. " <<
        "\nSpecify the amount to sell after the SELL word to only sell a portion of your cargo." << std::endl;
    std::cout << "Type LEAVE to leave the planet" << std::endl;

}

// Disable Setting weather for this moon
void Corporation::setWeather(MoonWeathers weather) {

}

const std::string& Corporation::name() const {
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
