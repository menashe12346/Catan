#ifndef MONOPOLYCARD_HPP
#define MONOPOLYCARD_HPP

#include <vector>
#include <string>
#include "developmentCard.hpp"
#include "player.hpp"

namespace ariel {

class Player;

class MonopolyCard : public DevelopmentCard {
public:
    /// @brief Play the MonopolyCard
    /// @param player The player using the card
    /// @param players A vector of all players in the game
    /// @param resource The resource to monopolize
    void play(Player& player, std::vector<std::reference_wrapper<ariel::Player>> players, const std::string& resource);
};

} // namespace ariel

#endif // MONOPOLYCARD_HPP