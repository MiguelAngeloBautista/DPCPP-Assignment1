#include "AbstractMoon.h"
#include "../Game.h"


AbstractMoon::AbstractMoon() {
    moonName = "ABSTRACT MOON";
    currentWeatherCondition = MoonWeathers::Clear();
    baseSurvivalChance = 1.0;
    minScrapValue = 0;
    maxScrapValue = 0;
    moonPrice = 0;
    moonType = "Free";
}

void AbstractMoon::sendEmployees(Game& g, int count) {
    g.sim->simulate(g, count);

    if (g.getAliveEmployees() == 0) {
        g.addCargoValue(-g.getCargoValue());
        g.leave();

        std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
        std::cout << "All the employees died and the scrap is lost." << std::endl;
        std::cout << "Autopilot will now bring the ship back to orbit." << std::endl;
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;

        g.printNewDay();
        std::cout << "Currently orbiting: " << g.getCurrentMoon()->name() << std::endl;
    }

    
}

const std::string& AbstractMoon::name() const {
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

void AbstractMoon::onDayBegin(Game& g) const {
    std::cout << "\nWELCOME TO " << name() << "!\n" << std::endl;
    g.printNewDay();
    std::cout << "Number of employees: " << g.getAliveEmployees() << std::endl;

        std::cout << "\nType SEND followed by the number of employees you wish to send inside the facility." <<
            "\nAll the other employees will stay on the ship. " << std::endl;
    std::cout << "Type LEAVE to leave the planet" << std::endl;
}

void AbstractMoon::setWeather(MoonWeathers weather) {
    currentWeatherCondition = weather;
}

void AbstractMoon::sellCargo(Game& g, int amount) {

}

int AbstractMoon::price() const {
    return moonPrice;
}

std::string AbstractMoon::type() const {
    return moonType;
}
