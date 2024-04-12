#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <unordered_map>
#include "Moons/AbstractMoon.h"
#include "Items/AbstractItem.h"


class Game;

class Simulator {
public:
    Simulator();
    ~Simulator() = default;
    void simulate(Game& g, int numExplorers);
};

#endif //SIMULATOR_H