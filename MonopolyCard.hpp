#ifndef MONOPOLYCARD_HPP
#define MONOPOLYCARD_HPP

#include <vector>
#include "developmentCard.hpp"
#include "player.hpp"

namespace ariel {

class Player;

class MonopolyCard : public DevelopmentCard {
public:
    void play(Player& player, std::vector<Player*>& players);
};

} // namespace ariel

#endif // MONOPOLYCARD_HPP
