#ifndef ROADBUILDINGCARD_HPP
#define ROADBUILDINGCARD_HPP

#include <vector>
#include <string>
#include "developmentCard.hpp"
#include "player.hpp"
#include "board.hpp"

namespace ariel {

class Player;
class Board;

class RoadBuildingCard : public DevelopmentCard {
public:
    /// @brief Play the RoadBuildingCard
    /// @param player The player using the card
    /// @param places1 The first set of place names for road placement
    /// @param placesNum1 The first set of place numbers for road placement
    /// @param places2 The second set of place names for road placement
    /// @param placesNum2 The second set of place numbers for road placement
    /// @param board The game board
    void play(Player& player, std::vector<std::string> places1, std::vector<int> placesNum1, std::vector<std::string> places2, std::vector<int> placesNum2, Board& board);
};

} // namespace ariel

#endif // ROADBUILDINGCARD_HPP
