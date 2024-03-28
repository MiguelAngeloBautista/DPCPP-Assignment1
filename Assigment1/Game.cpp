#include "Game.h"

Game::Game() {
    // ItemManager itemManager
    // MooonManager moonManager
    // SimulatorManager simulatorManager
    // RandomNumberGenerator rng

    balance = 0;
    // AbstractMoon* currentMoon
    currentPhase;
    currentDay = 0;
    cargoValue = 0;
    aliveEmployees = 4;
}


void Game::land() {
    // Call the moon's onDayBegin
}

void Game::leave() {

}

void Game::exit() {

}
