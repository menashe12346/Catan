#ifndef KNIGHTCARD_HPP
#define KNIGHTCARD_HPP

#include "developmentCard.hpp"
#include "tile.hpp"
#include "player.hpp"
#include <string>

namespace ariel {

class KnightCard : public DevelopmentCard {
public:
    /// @brief Play the Knight Card
    /// @param player The player using the card
    void play(Player& player);

    /// @brief Set the knight tile
    /// @param name The name of the terrain
    /// @param number The number on the tile
    static void setKnight(const std::string& name, int number);

    /// @brief Get the knight tile
    /// @return A pointer to the knight tile
    static Tile* getKnight();

private:
    static Tile* knight; ///< Static pointer to the knight tile
};

}  // namespace ariel

#endif // KNIGHTCARD_HPP