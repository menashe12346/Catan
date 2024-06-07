#include "tile.hpp"

namespace ariel {

    Tile::Tile(){}
    Tile::Tile(std::string terrain, int number) : terrain(terrain), number(number) {}

    bool Tile::operator==(const Tile& other) const {
        return this->terrain == other.terrain && this->number == other.number;
    }

    bool Tile::operator<(const Tile& other) const {
        if (this->terrain == other.terrain) {
            return this->number < other.number;
        }
        return this->terrain < other.terrain;
    }

}
