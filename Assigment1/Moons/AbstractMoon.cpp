#include "AbstractMoon.h"
#include "../Game.h"


AbstractMoon::AbstractMoon() {
    moonName = "ABSTRACT MOON";
    currentWeatherCondition = MoonWeathers::Clear();
    baseSurvivalChance = 1.0;
    minScrapValue = 0;
    maxScrapValue= 0;
}

void AbstractMoon::sendEmployees(Game& g, int count) {
    // Calls the simulate() in Simulator
    //g.setAliveEmployees(from result in simulate());
    // g.addCargoValue(result from simulate());
}

const std::string AbstractMoon::name() const {
    return moonName;
}

std::tuple<int, int> AbstractMoon::scrapValues() const {
    return std::make_tuple(minScrapValue, maxScrapValue);
}

float AbstractMoon::survivalChance() const {
    return this->baseSurvivalChance;
}

std::string AbstractMoon::weather() const{
    /*const char* to_string(MoonWeathers weather) {*/
        switch (currentWeatherCondition) {
        case MoonWeathers::Clear:
            return "Clear";
        case MoonWeathers::Flooded:
            return "Flooded";
        case MoonWeathers::Eclipsed:
            return "Eclipsed";
        case MoonWeathers::Stormy:
            return "Stormy";
        }
        return "N/A";
    /*}*/
    
    /*return currentWeatherCondition;*/

}

void AbstractMoon::onDayBegin(Game& g) {
    std::cout << "Current Weather: " << weather() << std::endl;

    std::cout << "> "; // Make them do the commands thingy

    // Calls sendEmployees(g)
}

void AbstractMoon::setWeather(MoonWeathers weather) {
    currentWeatherCondition = weather;
}

void AbstractMoon::sellCargo(Game& g, int amount) {

}
