#include "Game.h"

Game::Game() {
    // ItemManager itemManager = new ItemManager();
    
    // SimulatorManager simulator;
    // RandomNumberGenerator rng = new RandomNumberGenerator();
    
    moonManager = new MoonManager();
    moonManager->registerMoon(new Corporation());
    moonManager->registerMoon(new Prototyping());
    moonManager->registerMoon(new Insurance());
    moonManager->registerMoon(new Pledge());
    moonManager->registerMoon(new Defense());

    balance = 0;
    currentMoon = moonManager->moons().at("Corporation"); // new Corporation();
    currentPhase = ORBIT;
    currentDay = 1;
    cargoValue = 0;
    aliveEmployees = 4;
    quota = 150;

    

}

Game::~Game() {
    delete moonManager;
    //delete itemManager;
    //delete simulator;
    //delete rng;

    moonManager = nullptr;
    //itemManager = nullptr;
    //simulator = nullptr;
    //rng = nullptr;
}


void Game::land() {
    // Call the moon's onDayBegin
    currentPhase = LAND;
    // currentMoon->onDayBegin(*this);

    // if (getAliveEmployees == 0) {
    
    // }
}

void Game::leave() {
    moonManager->regenerateWeather();
    currentPhase = ORBIT;
    currentDay += 1;
}

void Game::exit() {
    //Exit process but not destructor

}

int Game::getAliveEmployees() {
    return aliveEmployees;
}

void Game::setAliveEmployees(int num) {
    aliveEmployees = num;
}

// Add Cargo Value by n Amount. Convert to negative to subtract
void Game::addCargoValue(int num) {
    cargoValue += num;
}

int Game::getCargoValue() {
    return cargoValue;
}

int Game::getQuota() {
    return quota;
}

// Add balance by n Amount. Convert to negative to subtract
void Game::addBalance(int num) {
    balance += num;
}

int Game::getBalance() {
    return balance;
}

int Game::getCurrentDay() {
    return currentDay;
}

void Game::setCurrentMoon(AbstractMoon* moon) {
    currentMoon = moon;
}

AbstractMoon* Game::getCurrentMoon() {
    return currentMoon;
}

 
phases Game::getCurrentPhase() const {
    return currentPhase;
}
