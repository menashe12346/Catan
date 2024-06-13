#ifndef CATAN_H
#define CATAN_H

#include <iostream>
#include "knightCard.hpp"
#include "MonopolyCard.hpp"
#include "RoadBuildingCard.hpp"
#include "YearOfPlentyCard.hpp"
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
    Board board; 

public:
    /// @brief Constructor to initialize the Catan game with three players
    /// @param player1 Reference to the first player
    /// @param player2 Reference to the second player
    /// @param player3 Reference to the third player
    Catan(Player &player1, Player &player2, Player &player3);

    /// @brief Get the board
    /// @return Reference to the board
    Board& getBoard();

    /// @brief Roll the dice for a player
    /// @param player The player rolling the dice
    void rollDice(Player& player);

    /// @brief End the turn for a player
    /// @param player The player ending their turn
    void endTurn(Player& player);

    /// @brief Handle trading between two players
    /// @param First_Player The player initiating the trade
    /// @param Second_Player The player receiving the trade
    /// @param resource1 The resource being traded by the first player
    /// @param resource2 The resource being traded by the second player
    /// @param num1 The quantity of resource1
    /// @param num2 The quantity of resource2
    void trade(Player &First_Player, Player &Second_Player, std::string resource1, std::string resource2, int num1, int num2);

    /// @brief Play a Monopoly card
    /// @param player The player playing the card
    /// @param resource The resource to monopolize
    void playDevelopmentCard(Player &player, std::string resource);

    /// @brief Play a Road Building card
    /// @param player The player playing the card
    /// @param places1 The first set of place names for road placement
    /// @param placesNum1 The first set of place numbers for road placement
    /// @param places2 The second set of place names for road placement
    /// @param placesNum2 The second set of place numbers for road placement
    /// @param board The game board
    void playDevelopmentCard(Player &player, std::vector<std::string> places1, std::vector<int> placesNum1, std::vector<std::string> places2, std::vector<int> placesNum2, Board& board);

    /// @brief Play a Year of Plenty card
    /// @param player The player playing the card
    /// @param resource1 The first resource to be granted
    /// @param resource2 The second resource to be granted
    void playDevelopmentCard(Player& player, const std::string& resource1, const std::string& resource2);

    /// @brief Play a Knight card
    /// @param player The player playing the card
    void playDevelopmentCard(Player& player);

    /// @brief Print the winner of the game
    void printWinner();
};

} // namespace ariel

#endif // CATAN_H