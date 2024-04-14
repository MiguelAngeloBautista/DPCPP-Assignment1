#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Moons/Corporation.h"
#include "Moons/Prototyping.h"
#include "Moons/Insurance.h"
#include "Moons/Pledge.h"
#include "Moons/Defense.h"
#include "Moons/April.h"
#include "Moons/Tore.h"
#include "Moons/Hyperion.h"
#include "Moons/MoonManager.h"

#include "Items/Backpack.h"
#include "Items/Flashlight.h"
#include "Items/HydraulicsMk2.h"
#include "Items/InverseTeleporter.h"
#include "Items/ProFlashlight.h"
#include "Items/Shovel.h"
#include "Items/Teleporter.h"
#include "Items/ItemManager.h"

#include "Simulator.h"

enum phases { ORBIT, LAND };

class Game {
public:
	Game();
	virtual ~Game();
	void land();
	void leave();
	void exit();
	int getAliveEmployees() const;
	void setAliveEmployees(int num);
	void addCargoValue(int num);
	int getCargoValue() const;
	int getQuota() const;
	void addBalance(int num);
	int getBalance() const;
	int getCurrentDay() const;
	void addCurrentDay();
	void setCurrentMoon(AbstractMoon* moon);
	void printNewDay();
	void madeQuota();
	AbstractMoon* getCurrentMoon();
	phases getCurrentPhase() const;
	MoonManager* moonManager;
	ItemManager* itemManager;
	Simulator* sim;
	int daysLeft;
private:
	int balance;
	AbstractMoon* currentMoon;
	phases currentPhase;
	int currentDay;
	int cargoValue;
	int aliveEmployees;
	int quota;
};

#endif // GAME_H