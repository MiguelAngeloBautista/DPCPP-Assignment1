#include "MoonManager.h"

MoonManager::MoonManager() : allGameMoons() {

}

MoonManager::~MoonManager() {
    for (auto& moon : MoonManager::allGameMoons) {
        delete moon.second;
        moon.second = nullptr;
    }
    MoonManager::allGameMoons.clear();
}

// Returns a new moon based on inputted name which will be the new currentMoon in Game
AbstractMoon* MoonManager::route(std::string moonName) {
    if (allGameMoons.empty()) {
        std::cerr << "ERROR: allGameMoons vector is empty!" << std::endl;
        return nullptr;
    }
    
    try
    {
        return allGameMoons.at(moonName);
    }
    catch (const std::exception&)
    {
        return nullptr;
    }
    

}

// returns hashmap of all moons
const std::unordered_map<std::string, AbstractMoon*> MoonManager::moons() const{

    return allGameMoons;
}

// Call only on first load
void MoonManager::registerMoon(AbstractMoon* moon) {
    allGameMoons[moon->name()] = moon;

}

// Call at first load and every time player leaves moon
void MoonManager::regenerateWeather() {
    for (auto& moon : allGameMoons) {
        MoonWeathers temp = static_cast<MoonWeathers>(rand() % 4);
        int weatherNumber = static_cast<int>(temp);
        
        moon.second->setWeather(MoonWeathers(weatherNumber));
    }
}
