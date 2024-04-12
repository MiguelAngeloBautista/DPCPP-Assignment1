// main.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "Game.h"
#include "game_title.h"
#include "util.h"

using namespace util;

int main()
{
    Game* g = new Game();
    std::string choice;
    std::vector<std::string> args;
    g->moonManager->regenerateWeather();

    std::cout << DEADLY_CORP_TITLE << std::endl;

    std::cout << "Welcome!" << std::endl;
    std::cout << "We trust you will be a great asset to the corporation!" << std::endl;
    std::cout << std::endl;

    g->printNewDay();
    std::cout << "Currently orbiting: " << g->getCurrentMoon()->name() << std::endl;
    while (true) {
        if (g->daysLeft == 0) {
            if (g->getBalance() < g->getQuota()) {
                break;
            }
            else if (g->getBalance() >= g->getQuota()) {
                g->madeQuota();
            }
            
            
        }

        std::cout << "\n> ";
        std::getline(std::cin, choice);
        lower(choice);
        splitArguments(choice, args);
        /*int daysLeft = 4 - (g->getCurrentDay() % 4);*/


          // ================================================================ MOONS
        if (choice == "moons") {

            std::cout << "\nWelcome to the exomoons catalogue. \nTo route the autopilot to a moon, use the word ROUTE." << std::endl;
            std::cout << "---------------------------------------" << std::endl;

            for (auto& moon : g->moonManager->moons()) {
                std::cout << "* " << moon.first;
                if (moon.second->weather() != "Clear") {
                    std::cout << " (" << moon.second->weather() << ")";
                }
                if (moon.second->type() == "Paid") {
                    std::cout << ": $" << moon.second->price();
                }
                std::cout << std::endl;
            }

            std::cout << "\nBalance: $" << g->getBalance() << std::endl;

        } // ================================================================ ROUTE
        else if (choice == "route") {
            if (args.empty()) {
                std::cout << "\nBad command; the syntax is: \"route moonName\"" << std::endl;
                continue;
            }
            args[0][0] = toupper(args[0][0]); // Makes first letter uppercase

            if (g->moonManager->route(args[0]) == nullptr) {
                std::cout << "\nInvalid Moon" << std::endl;
                continue;
            }
            else if (g->getCurrentMoon()->name() == args[0]) {
                std::cout << "\nAlready orbiting " << args[0] << std::endl;
                continue;
            }
            if (g->moonManager->moons().at(args[0])->type() == "Paid") {
                std::cout << "\nThe cost of going to " << args[0] << " is $" << g->moonManager->moons().at(args[0])->price() << std::endl;
                std::cout << "You have $" << g->getBalance() << ". Confirm destination? [Yes/No]: ";
                std::string choice2;
                std::cin >> choice2;
                lower(choice2);

                if (choice2 == "Yes") {
                    if (g->getBalance() < g->moonManager->moons().at(args[0])->price()) {
                        std::cout << "Not enough funds. Trip cancelled." << std::endl;
                        std::cout << "Still orbiting " << g->getCurrentMoon()->name() << std::endl;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    g->addBalance(-g->moonManager->moons().at(args[0])->price());
                    std::cout << "New balance: $" << g->getBalance() << std::endl;

                }
                else {
                    std::cout << "Trip cancelled." << std::endl;
                    std::cout << "Still orbiting " << g->getCurrentMoon()->name() << std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            g->setCurrentMoon(g->moonManager->route(args[0]));
            std::cout << "\nNow orbiting " << g->getCurrentMoon()->name() << ". Use the LAND command to land." << std::endl;

        } // ================================================================ LAND
        else if (choice == "land" && g->getCurrentPhase() == ORBIT) {
            if (g->getCurrentPhase() == LAND) {
                std::cout << "\nAlready Landed" << std::endl;
            }

            g->land();

        } // ================================================================ SEND
        else if (choice == "send") {
            if (args.empty()) {
                std::cout << "\nBad command; the syntax is: \"send numberOfEmployees\"" << std::endl;
                continue;
            }
            else if (g->getCurrentPhase() != LAND or g->getCurrentMoon()->name() == "Corporation") {
                std::cout << "\nThis command is not available at this time." << std::endl;
                continue;
            }
            // Checks if Number
            try {
                std::stoi(args[0]);
            }
            catch (const std::exception&) {
                std::cout << "\nBad command; Invalid Number" << std::endl;
                continue;
            }
            // Checks if player has enough alive employees
            if (std::stoi(args[0]) > g->getAliveEmployees()) {
                std::cout << "\nError: Not Enough employees" << std::endl;
                continue;
            }

            g->getCurrentMoon()->sendEmployees(*g, std::stoi(args[0]));
            

        } // ================================================================ SELL
        else if (choice == "sell") {
            if (args.empty()) {
                std::cout << "\nBad command; the syntax is: \"sell amount\"" << std::endl;
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

            // Checks if you have enough cargo to sell
            if (g->getCargoValue() >= std::stoi(args[0])) {
                g->getCurrentMoon()->sellCargo(*g, std::stoi(args[0]));
            }
            else {
                std::cout << "Error: not enought cargo" << std::endl;
            }

            std::cout << "Your service is invaluable to the corporation." << std::endl;
            std::cout << "New Balance: $" << g->getBalance() << " (quota is $" << g->getQuota() << ")" << std::endl;
            std::cout << "New cargo value: $" << g->getCargoValue() << std::endl;


            

        } // ================================================================ LEAVE
        else if (choice == "leave" && g->getCurrentPhase() == LAND) {
            g->leave();

            
           
            g->printNewDay();
            std::cout << "Currently orbiting: " << g->getCurrentMoon()->name() << std::endl;

        } // ================================================================ STORE
        else if (choice == "store") {
            std::unordered_map<std::string, AbstractItem*> allItems = g->itemManager->store();

            std::cout << "\nWelcome to the Corporation store.\n" << "Use the word Buy on any item." << std::endl;
            std::cout << "---------------------------------------" << std::endl;

            for (auto& item : allItems) {
                std::cout << "* " << item.first << " // Price: $" << item.second->price() << std::endl;
            }

            std::cout << "\nBalance: $" << g->getBalance() << std::endl;
        
        } // ================================================================ BUY
        else if (choice == "buy") {
            if (args.empty()) {
                std::cout << "\nBad command; the syntax is: \"buy itemName\"" << std::endl;
                continue;
            }

            args[0][0] = toupper(args[0][0]); // Makes first letter uppercase
            
            // Combines two word args into one string with a space included
            if (args.size() > 1) { 
                args[1][0] = toupper(args[1][0]);
                args[0] = args[0] + " " + args[1];
            }

            if (g->itemManager->buy(*g, args[0]) == false) {
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

    // Game Over Screen Outside of while loop
    std::cout << "\n-------------------------------------" << std::endl;
    std::cout << ">>>>>>>>>>>>> GAME OVER <<<<<<<<<<<<<" << std::endl;
    std::cout << "-------------------------------------\n" << std::endl;

    std::cout << "You did not meet quota in time, and your employees have been fired." << std::endl;
    std::cout << "You kept them alive for " << g->getCurrentDay() << " days." << std::endl;
    g->exit();

    delete g;
    g = nullptr;
    return 0;
}

void gameOver() {

}