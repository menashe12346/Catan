#ifndef MONOPOLYCARD_HPP
#define MONOPOLYCARD_HPP

#include <vector>
#include "developmentCard.hpp"
#include "player.hpp"

namespace ariel {

class Player;

class MonopolyCard : public DevelopmentCard {
public:
    void play(Player& player, std::vector<std::reference_wrapper<ariel::Player>> players, const string& resource);
};

} // namespace ariel

#endif // MONOPOLYCARD_HPP
