#include "catan.hpp"
#include <iostream>

namespace ariel {
    Catan::Catan(Player& p1, Player& p2, Player& p3) : player1(p1), player2(p2), player3(p3),currentPlayer(player1) {
        std::cout << "Catan game constructor called." << std::endl;
        std::cout << "Catan game initialized with players: " << player1.name << ", " << player2.name << ", " << player3.name << std::endl;
        std::cout << "Starting player is " << currentPlayer.name << std::endl;
    }

    void Catan::printWinner() {
        // Your logic to print the winner
    }
}
