#include "knightCard.hpp"

namespace ariel {

Tile* KnightCard::knight = nullptr;

    Tile* KnightCard::getKnight() {
        return knight;
    }

    void KnightCard::setKnight(const std::string& terrain, int number) {
        if (knight == nullptr) {
            knight = new Tile(terrain, number);
        } else {
            // Update the existing knight object
            knight->setTerrain(terrain);
            knight->setNumber(number);
        }
    }

    void KnightCard::play(Player& player) {
        string terrain;
        int num;
        std::cout << "Enter a resource and a number of a tile you want to put the knight on (e.g., Agricultural Land 4 ): ";
        std::cin >> terrain >> num;
        Tile knight(terrain, num);
        this->knight = &knight;
        std::cout << "Knight card played by " << player.getName() << ": Move the robber to tile with " << terrain << " and number " << num << std::endl;
    }

}  // namespace ariel
