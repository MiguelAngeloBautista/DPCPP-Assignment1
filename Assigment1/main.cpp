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

    std::cout << "\n>MOONS" << "\nTo see the list of moons the autopilot can route to." << std::endl;
    std::cout << "\n>STORE" << "\nTo see the company store's selection of useful items." << std::endl;
    std::cout << "\n>INVENTORY" << "\nTo see the list of items you've already bought." << std::endl;



    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, choice);
        lower(choice);
        splitArguments(choice, args);

          // ================================================================ MOONS
        if (choice == "moons") {

            std::cout << "\nWelcome to the exomoons catalogue. \nTo route the autopilot to a moon, use the word ROUTE." << std::endl;
            std::cout << "---------------------------------------" << std::endl;

            for (auto& moon : g->moonManager->moons()) {
                std::cout << "* " << moon.first;
                if (moon.second->weather() != "Clear") {
                    std::cout << "(" << moon.second->weather() << ")";
                }
                std::cout << std::endl;
            }

            std::cout << "\nBalance: $" << g->getBalance() << std::endl;

        } // ================================================================ ROUTE
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

        } // ================================================================ LAND
        else if (choice == "land" && g->getCurrentPhase() == ORBIT) {
            g->land();

            std::cout << "\nWELCOME TO " << g->getCurrentMoon()->name() << "!\n" << std::endl;
            std::cout << "Current cargo value: $" << g->getCargoValue() << std::endl;
            std::cout << "Current balance: $" << g->getBalance() << std::endl;
            std::cout << "Current quota: $" << g->getQuota() << std::endl;
            std::cout << "Number of employees: " << g->getAliveEmployees() << std::endl;

            if (g->getCurrentMoon()->name() != "Corporation") {
                std::cout << "\nType SEND followed by the number of employees you wish to send inside the facility." <<
                    "All the other employees will stay on the ship. ";
            }
            else {

            }

            std::cout << "Type LEAVE to leave the planet" << std::endl;

        } // ================================================================ SEND
        else if (choice == "send") {
            if (args.empty()) {
                std::cout << "\nMissing Argument: Number of Employees to send" << std::endl;
                continue;
            }
            else if (g->getCurrentPhase() != LAND or g->getCurrentMoon()->name() == "Corporation") {
                std::cout << "\nThis command is not available at this time." << std::endl;
                continue;
            }

            /*g->getCurrentMoon()->sendEmployees()*/

        } // ================================================================ SELL
        else if (choice == "sell") {
            if (args.empty()) {
                std::cout << "\nMissing Argument: Sell Amount" << std::endl;
                continue;
            }
            else if (g->getCurrentMoon()->name() != "Corporation" or g->getCurrentPhase() == ORBIT) {
                std::cout << "\nThis command is not available at this time." << std::endl;
                continue;
            }
            
            try {
                std::stoi(args[0]);
            }
            catch (const std::exception&) {
                std::cout << "\nInvalid Number" << std::endl;
                continue;
            }

            g->getCurrentMoon()->sellCargo(*g, std::stoi(args[0]));

        } // ================================================================ LEAVE
        else if (choice == "leave" && g->getCurrentPhase() == LAND) {
            g->leave();

            std::cout << std::endl << "============= DAY " << g->getCurrentDay() << " =============" << std::endl;
            std::cout << "Current cargo value: $" << g->getCargoValue() << std::endl;
            std::cout << "Current balance: $" << g->getBalance() << std::endl;
            std::cout << "Current quota: $" << g->getQuota() << std::endl;
            std::cout << "Currently orbiting: " << g->getCurrentMoon()->name() << std::endl;

        } // ================================================================ STORE
        else if (choice == "store") {
            std::unordered_map<std::string, AbstractItem*> allItems = g->itemManager->store();

            std::cout << "\nWelcome to the Corporation store.\n" << "Use the word Buy on any item." << std::endl;
            std::cout << "---------------------------------------" << std::endl;

            for (auto& item : allItems) {
                std::cout << "* " << item.first << "// Price: $" << item.second->price() << std::endl;
            }

            std::cout << "\nBalance: $" << g->getBalance() << std::endl;
        
        } // ================================================================ BUY
        else if (choice == "buy") {
            if (args.empty()) {
                std::cout << "\nMissing Argument: Item Name" << std::endl;
                continue;
            }

            args[0][0] = toupper(args[0][0]); // Makes first letter uppercase
            
            // Combines two word args into one string with a space included
            if (args.size() > 1) { 
                args[1][0] = toupper(args[1][0]);
                args[0] = args[0] + " " + args[1];
            }

            if (g->itemManager->buy(args[0]) == false) {
                std::cout << "\nInvalid Item Name" << std::endl;
                continue;
            }


        } // ================================================================ INVENTORY
        else if (choice == "inventory") {
            std::unordered_map<std::string, AbstractItem*> inventory = g->itemManager->inventory();

            std::cout << "\nThe following items are available." << std::endl;
            std::cout << "---------------------------------------" << std::endl;

            for (auto& item : inventory) {
                std::cout << "* " << item.first << std::endl;
            }

            std::cout << "\nBalance: $" << g->getBalance() << " (quota is $" << g->getQuota() << ")" << std::endl;
            std::cout << "Cargo value: $" << g->getCargoValue() << std::endl;

        } // ================================================================ EXIT
        else if (choice == "exit") {
            g->exit();
            return false;
        } // ================================================================ INVALID
        else {
            std::cout << "Unknown command." << std::endl;
        }
    }

    delete g;
    g = nullptr;
    return 0;
}