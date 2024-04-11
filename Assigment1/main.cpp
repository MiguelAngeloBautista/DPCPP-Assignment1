// main.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <string>
#include <vector>

#include "Game.h"
#include "game_title.h"
#include "util.h"

using namespace util;

int main()
{
    Game* g = new Game();
    std::string choice;
    std::vector<std::string> args;
    

    std::cout << DEADLY_CORP_TITLE << std::endl;

    std::cout << "Welcome!" << std::endl;
    std::cout << "We trust you will be a great asset to the corporation!" << std::endl;
    std::cout << std::endl;

    std::cout << "============= DAY " << g->getCurrentDay() << " =============" << std::endl;
    std::cout << "Current cargo value: $" << g->getCargoValue() << std::endl;
    std::cout << "Current balance: $" << g->getBalance() << std::endl;
    std::cout << "Current quota: $" << g->getQuota() << std::endl;
    std::cout << "Currently orbiting: " << g->getCurrentMoon()->name() << std::endl;


    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, choice);
        lower(choice);
        splitArguments(choice, args);

        if (choice == "moons") {

        }
        else if (choice == "route") {
            if (args.empty()) {
                std::cout << "\nMissing Argument: Moon" << std::endl;
                continue;
            }
            args[0][0] = toupper(args[0][0]); // Makes first letter uppercase

            if (g->moonManager->route(args[0]) == nullptr) {
                std::cout << "\nInvalid Moon" << std::endl;
                continue;
            } 
            

            g->setCurrentMoon(g->moonManager->route(args[0]));
            std::cout << "\nNow orbiting " << g->getCurrentMoon()->name() << ". Use the LAND command to land." << std::endl;

        }
        else if (choice == "land" && g->getCurrentPhase() == ORBIT) {
            g->land();

            std::cout << "\nWELCOME TO " << g->getCurrentMoon()->name() << "!" << std::endl;

        }
        else if (choice == "send" && g->getCurrentPhase() == LAND) {
            if (args.empty()) {
                std::cout << "\nMissing Argument: Number of Employees to send" << std::endl;
            }

            /*g->getCurrentMoon()->sendEmployees()*/
        }
        else if (choice == "sell") {

        }
        else if (choice == "leave" && g->getCurrentPhase() == LAND) {
            g->leave();

            std::cout << std::endl << "============= DAY " << g->getCurrentDay() << " =============" << std::endl;
            std::cout << "Current cargo value: $" << g->getCargoValue() << std::endl;
            std::cout << "Current balance: $" << g->getBalance() << std::endl;
            std::cout << "Current quota: $" << g->getQuota() << std::endl;
            std::cout << "Currently orbiting: " << g->getCurrentMoon()->name() << std::endl;
        }
        else if (choice == "store") {

        }
        else if (choice == "buy") {

        }
        else if (choice == "inventory") {

        }
        else if (choice == "exit") {
            g->exit();
            return false;
        }
        else {
            std::cout << "Unknown command." << std::endl;
        }
    }

    delete g;
    g = nullptr;
    return 0;
}