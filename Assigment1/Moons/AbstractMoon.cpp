#include "AbstractMoon.h"


AbstractMoon::AbstractMoon() {
    moonName = "Abstract Moon";
    currentWeatherCondition = nullptr;
    baseSurvivalChance = 1.0;
    minScrapValue = 0;
    maxScrapValue= 0;
}

void AbstractMoon::sendEmployees(Game& g, int count) {
    // Calls the simulate() in Simulator
}

std::string AbstractMoon::name() const {
    std::cout << "Moon: " << moonName << std::endl;
}

std::tuple<int, int> AbstractMoon::scrapValues() const {
    return std::make_tuple(minScrapValue, maxScrapValue);
}

float AbstractMoon::survivalChance() const {
    return baseSurvivalChance;
}

Weather* AbstractMoon::weather() const {
    return currentWeatherCondition;

}

void AbstractMoon::onDayBegin(Game& g) {
    std::cout << "> "; // Make them do the commands thingy

    // Calls sendEmployees(g)
}