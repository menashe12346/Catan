#ifndef CATAN_H
#define CATAN_H

#include <iostream>
#include "knightCard.hpp"
#include "player.hpp"
#include "board.hpp"
#include <ctime>

namespace ariel {

    class Catan {
    private:
        Player& player1;
        Player& player2;
        Player& player3;
        Player* currentPlayer;

    public:
        Catan(Player &player1, Player &player2, Player &player3);
        void rollDice(Player& player);
        void endTurn(Player& player);
        void trade(Player &First_Player, Player &Second_Player, string resource1, string resource2, int num1, int num2);
        void printWinner();
        
    };
}

#endif // CATAN_H
