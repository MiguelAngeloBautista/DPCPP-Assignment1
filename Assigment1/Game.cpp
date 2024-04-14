#include "Game.h"

Game::Game() {
    
    
    // Simulator simulator;
    
    // Register all Moons
    moonManager = new MoonManager();
    moonManager->registerMoon(new Corporation());
    moonManager->registerMoon(new Prototyping());
    moonManager->registerMoon(new Insurance());
    moonManager->registerMoon(new Pledge());
    moonManager->registerMoon(new Defense());
    moonManager->registerMoon(new April());
    moonManager->registerMoon(new Tore());
    moonManager->registerMoon(new Hyperion());

    // Register all items
    itemManager = new ItemManager();
    itemManager->registerItem(new Flashlight());
    itemManager->registerItem(new Shovel());
    itemManager->registerItem(new ProFlashlight());
    itemManager->registerItem(new Teleporter());
    itemManager->registerItem(new InverseTeleporter());
    itemManager->registerItem(new Backpack());
    itemManager->registerItem(new HydraulicsMk2());

    sim = new Simulator();

    balance = 50;
    currentMoon = moonManager->moons().at("Corporation");
    currentPhase = ORBIT;
    currentDay = 1;
    cargoValue = 0;
    aliveEmployees = 4;
    quota = 150;

    

}

Game::~Game() {
    delete moonManager;
    delete itemManager;
    delete sim;

    moonManager = nullptr;
    itemManager = nullptr;
    sim = nullptr;
}


void Game::land() {
    currentPhase = LAND;
    currentMoon->onDayBegin(*this);

}

void Game::leave() {
    setAliveEmployees(4);
    moonManager->regenerateWeather();
    currentPhase = ORBIT;
    currentDay += 1;
}

void Game::exit() {
    //Exit process but not destructor

}

int Game::getAliveEmployees() const{
    return aliveEmployees;
}

void Game::setAliveEmployees(int num) {
    aliveEmployees = num;
}

// Add Cargo Value by n Amount. Convert to negative to subtract
void Game::addCargoValue(int num) {
    cargoValue += num;
}

int Game::getCargoValue() const {
    return cargoValue;
}

int Game::getQuota() const {
    return quota;
}

// Add balance by n Amount. Convert to negative to subtract
void Game::addBalance(int num) {
    balance += num;
}

int Game::getBalance() const {
    return balance;
}

int Game::getCurrentDay() const {
    return currentDay;
}

void Game::addCurrentDay() {
    currentDay += 1;
}

void Game::setCurrentMoon(AbstractMoon* moon) {
    currentMoon = moon;
}

void Game::printNewDay() {
    daysLeft = 4 - (getCurrentDay() % 4);

    std::cout << "\n============= DAY " << getCurrentDay() << " =============" << std::endl;
    std::cout << "Current cargo value: $" << getCargoValue() << std::endl;
    std::cout << "Current balance: $" << getBalance() << std::endl;
    std::cout << "Current quota: $" << getQuota() << " (" << daysLeft << " days left to meet quota)" << std::endl;

    std::cout << "\n>MOONS" << "\nTo see the list of moons the autopilot can route to." << std::endl;
    std::cout << "\n>STORE" << "\nTo see the company store's selection of useful items." << std::endl;
    std::cout << "\n>INVENTORY" << "\nTo see the list of items you've already bought." << std::endl;


    
}

void Game::madeQuota() {
    quota += static_cast<int>(quota * 0.5);
    std::cout << "\n\n-------------------------------------" << std::endl;
    std::cout << "CONGRATULATIONS ON MAKING QUOTA!" << std::endl;
    std::cout << "New quota: $" << quota << std::endl;
    std::cout << "-------------------------------------\n" << std::endl;
}

AbstractMoon* Game::getCurrentMoon() {
    return currentMoon;
}

 
phases Game::getCurrentPhase() const {
    return currentPhase;
}
