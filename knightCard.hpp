#ifndef KNIGHTCARD_HPP
#define KNIGHTCARD_HPP

#include "developmentCard.hpp"
#include "tile.hpp"
#include "player.hpp"
#include <string>

namespace ariel {

class KnightCard : public DevelopmentCard {
public:
    void play(Player& player);
    static void setKnight(const std::string& name, int number);
    static  Tile* getKnight();
private:
    static Tile* knight;
};

}  // namespace ariel

#endif // KNIGHTCARD_HPP
