#ifndef YEAROFPLENTYCARD_HPP
#define YEAROFPLENTYCARD_HPP

#include <string>
#include "developmentCard.hpp"
#include "player.hpp"

namespace ariel {

class Player;

class YearOfPlentyCard : public DevelopmentCard {
public:
    /// @brief Play the YearOfPlentyCard
    /// @param player The player using the card
    /// @param resource1 The first resource to be granted
    /// @param resource2 The second resource to be granted
    void play(Player& player, std::string resource1, std::string resource2);
};

} // namespace ariel

#endif // YEAROFPLENTYCARD_HPP
