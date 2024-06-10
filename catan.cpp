#include "catan.hpp"
#include <iostream>

namespace ariel {
    Catan::Catan(Player& p1, Player& p2, Player& p3) : player1(p1), player2(p2), player3(p3),currentPlayer(&player1) {
        std::srand(std::time(nullptr)); // Seed the random number generator once
        std::cout << "Catan game constructor called." << std::endl;
        std::cout << "Catan game initialized with players: " << player1.name << ", " << player2.name << ", " << player3.name << std::endl;
        std::cout << "Starting player is " << (*currentPlayer).name << std::endl;
    }

    void Catan::rollDice(Player& player) {
        if(*currentPlayer == player)
        {
            // Generate two random numbers between 1 and 6
            int die1 = rand() % 6 + 1;
            int die2 = rand() % 6 + 1;
            int sum = die1 + die2;        
            cout << player.name << " rolled the dices and got " << sum << endl;
            if(sum == 7){
                player1.discardCards();
                player2.discardCards();
                player3.discardCards();
                string terrain;
                int num;
                std::cout << "Enter a resource and a number of a tile you want to put the knight on (e.g., Agricultural Land 4 ): ";
                std::cin >> terrain >> num;
                Tile knight(terrain, num);
                this->knight = &knight;
            } else{
                player1.distributeResources(sum, *(this->knight));
                player2.distributeResources(sum, *(this->knight));
                player3.distributeResources(sum, *(this->knight));
            }
        }else{
            cout << "its not " + player.getName() + "'s turn, its now " + (*currentPlayer).getName() + "'s turn" << endl;
        }
    }

    void Catan::endTurn(Player& player) {
        if (currentPlayer == &player) {
            std::cout << player.getName() << "'s turn has ended." << std::endl;
            if (currentPlayer == &player1) {
                currentPlayer = &player2;
            } else if (currentPlayer == &player2) {
                currentPlayer = &player3;
            } else {
                currentPlayer = &player1;
            }
            std::cout << "It's now " << currentPlayer->getName() << "'s turn." << std::endl;
        } else {
            std::cout << "It's not your turn to end, it's now " << currentPlayer->getName() << "'s turn" << std::endl;
        }
    }

    void Catan::trade(Player First_Player, Player Second_Player, string resource1, string resource2, int num1, int num2){
        if((*this->currentPlayer) == First_Player && First_Player.resource_exist(resource1, num1) && Second_Player.resource_exist(resource2, num2))
        {
        First_Player.getCards(resource1, num1*(-1)); //remove this resource
        First_Player.getCards(resource2, num2);
        Second_Player.getCards(resource2, num2*(-1)); //remove this resource
        Second_Player.getCards(resource1, num1);
        } else {
            cout << "its not " + First_Player.getName() + "'s turn, its now " + (*currentPlayer).getName() + "'s turn" << endl;
        }
    }

    void Catan::printWinner() {
        // Your logic to print the winner
    }
}
