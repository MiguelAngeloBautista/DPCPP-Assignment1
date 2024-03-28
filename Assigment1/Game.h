#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Game.h"

class Game {
private:
	// ItemManager itemManager
	// MooonManager moonManager
	// SimulatorManager simulatorManager
	// RandomNumberGenerator rng

	int balance;
	// AbstractMoon* currentMoon
	std::string currentPhase;
	int currentDay;
	int cargoValue;
	int aliveEmployees;


public:
	Game();
	virtual ~Game();

	void land() {

	}

	void leave() {

	}

	void exit() {

	}
};

#endif // GAME_H