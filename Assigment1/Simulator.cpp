#include <random>
#include "Simulator.h"
#include "Game.h"

Simulator::Simulator() {

}

void Simulator::simulate(Game& g, int numExplorers) {
    int numOperators = g.getAliveEmployees() - numExplorers;
    float explorerSurvivalChanceMultiplier = 1.0;
    float operatorSurvivalChanceMultiplier = 1.0;
    float scrapMultiplier = 1.0;
    float explorerSaveChance = 0.0;
    float lootRecoveryMultiplier = 1.0;
    float explorerBaseSurvivalChance = g.getCurrentMoon()->survivalChance();
    std::tuple<int, int> scrapValues = g.getCurrentMoon()->scrapValues();
    int minScrap = std::get<0>(g.getCurrentMoon()->scrapValues());
    int maxScrap = std::get<1>(g.getCurrentMoon()->scrapValues());
    
    std::random_device rd;
    std::mt19937 gen(rd());

    // Parses Multipliers from weather
    std::string moonWeather = g.getCurrentMoon()->weather();

    if (moonWeather == "Clear") {

    }
    else if (moonWeather == "Flooded") {
        explorerSurvivalChanceMultiplier *= 0.7;
    }
    else if (moonWeather == "Stormy") {
        scrapMultiplier *= 0.75;
    }
    else if (moonWeather == "Eclipsed") {
        explorerSurvivalChanceMultiplier *= 0.9;
        operatorSurvivalChanceMultiplier *= 0.7;
    }

    //Parses multiplier from items
    for (auto& item : g.itemManager->inventory()) {
        
        std::unordered_map<std::string, float> multipliers = item.second->multipliers();

        explorerSurvivalChanceMultiplier *= multipliers["explorerSurvivalMultiplier"];
        operatorSurvivalChanceMultiplier *= multipliers["operatorSurvivalMultiplier"];
        explorerSaveChance = multipliers["explorerSaveChance"];
        lootRecoveryMultiplier *= multipliers["lootRecoveryMultiplier"];
    }

    float explorerSurvivalChance = explorerBaseSurvivalChance * explorerSurvivalChanceMultiplier;
    float operatorSurvivalChance = 1.0 * operatorSurvivalChanceMultiplier;
    int totalRevenue = 0;
    int deadExplorers = 0;
    
    //Random Number Generator for scrap value
    std::uniform_real_distribution<float> randScrap(minScrap * scrapMultiplier, maxScrap * scrapMultiplier);
    //Random Number generator for Explorer survival chance
    std::uniform_real_distribution<float> randExplorer(0.0, 1.0);
    //Random Number generator for Operator survival chance
    std::uniform_real_distribution<float> randOperator(0.0, 1.0);


    for (int i = 0; i < numExplorers; i++) {
        float randomNum = randScrap(gen);
        int revenue = static_cast<int>(randomNum);

        if (randExplorer(gen) <= explorerSurvivalChance) {
            //Employee Survives
            totalRevenue += revenue;
        }
        else if (randExplorer(gen) >= explorerSaveChance) {
            // Employee Dies and Not Saved
            totalRevenue += revenue * lootRecoveryMultiplier;
            deadExplorers += 1;
        }

    }

    int deadOperators = 0;
    for (int i = 0; i < numOperators; i++) {
        if (randOperator(gen) > operatorSurvivalChance) {
            //Operator Dies
            deadOperators += 1;
        }
    }

    if (numExplorers - deadExplorers == 0) {
        totalRevenue = 0;
    }
    
    g.addCargoValue(totalRevenue);
    g.setAliveEmployees(g.getAliveEmployees() - (deadExplorers + deadOperators));

    if (numExplorers - deadExplorers == 0) {
        std::cout << "\n" << (numExplorers - deadExplorers) << " employees managed to make it back. " << (deadExplorers + deadOperators) << " died" << std::endl;
    }
    else {
        std::cout << "\n" << (numExplorers - deadExplorers) << " employees made it back to the ship, bringing $" << totalRevenue << " worth of scrap. " << (deadExplorers + deadOperators) << " died" << std::endl;
    }
    if (g.getAliveEmployees() == 1) {
        std::cout << "\n1 employee left" << std::endl;
    }

}
