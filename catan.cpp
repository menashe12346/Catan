//326648532
//menashe7676@gmail.com

#include "catan.hpp"

using namespace std;

namespace ariel {
    // Assuming player1 starts as written in the demo file
    Catan::Catan(Player player1, Player player2, Player player3)
        : player1(player1), player2(player2), player3(player3) {}  // Initializer List Approach

    void Catan::ChooseStartingPlayer(){
        currentPlayer = player1;
        cout << "Starting player is " << currentPlayer.name << endl;
    }

    Board Catan::getBoard(){
        return this->board;
    }

    void Catan::printWinner(){
        // Your logic to print the winner
    }
}
