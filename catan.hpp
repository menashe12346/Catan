#ifndef CATAN_H
#define CATAN_H

#include <iostream>
#include "player.hpp"
#include "board.hpp"

namespace ariel {
    class Catan {
    private:
        Player& player1;
        Player& player2;
        Player& player3;
        Player currentPlayer;
        Board board;

    public:
        Catan(Player &player1, Player &player2, Player &player3);
        void ChooseStartingPlayer();
        Board getBoard();
        void printWinner();
    };
}

#endif // CATAN_H
