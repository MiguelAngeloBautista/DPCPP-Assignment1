#ifndef GAME_H
#define GAME_H
#include <iostream>
//#include "Moons/AbstractMoon.h"
#include "Moons/Corporation.h"
#include "Moons/Prototyping.h"
#include "Moons/Insurance.h"
#include "Moons/Pledge.h"
#include "Moons/Defense.h"
#include "Moons/MoonManager.h"

static enum phases { ORBIT, LAND };

class Game {
public:
	
	Game();
	virtual ~Game();
	void land();
	void leave();
	void exit();
	int getAliveEmployees();
	void setAliveEmployees(int num);
	void addCargoValue(int num);
	int getCargoValue();
	int getQuota();
	void addBalance(int num);
	int getBalance();
	int getCurrentDay();
	AbstractMoon* getCurrentMoon();
	phases getCurrentPhase() const;
private:
	MoonManager* moonManager;
	int balance;
	AbstractMoon* currentMoon;
	phases currentPhase;
	int currentDay;
	int cargoValue;
	int aliveEmployees;
	int quota;
};

#endif // GAME_H