#include "tile.hpp"
#include <iostream>

namespace ariel {
    // Default constructor
    Tile::Tile() : terrain(""), number(0) {}

    // Parameterized constructor
    Tile::Tile(const std::string& terrain, int number) : terrain(terrain), number(number) {}

    // Copy constructor
    Tile::Tile(const Tile& other) : terrain(other.terrain), number(other.number) {
        //std::cout << "Tile copy constructor called" << std::endl;
        for (auto tile : other.nearby_areas) {
            nearby_areas.insert(tile);
        }
    }

    // Assignment operator
    Tile& Tile::operator=(const Tile& other) {
        std::cout << "Tile assignment operator called" << std::endl;
        if (this != &other) {
            terrain = other.terrain;
            number = other.number;
            nearby_areas.clear();
            for (auto tile : other.nearby_areas) {
                nearby_areas.insert(tile);
            }
        }
        return *this;
    }

    // Destructor
    Tile::~Tile() {}

    // Equality operator
    bool Tile::operator==(const Tile& other) const {
        return terrain == other.terrain && number == other.number;
    }

    bool Tile::operator!=(const Tile& other) const {
        return !(*this == other);
    }

    // Less-than operator
    bool Tile::operator<(const Tile& other) const {
        if (terrain == other.terrain) {
            return number < other.number;
        }
        return terrain < other.terrain;
    }

    // Output operator implementation
    std::ostream& operator<<(std::ostream& os, const Tile& tile) {
        os << "Tile(terrain: " << tile.terrain << ", number: " << tile.number << ",\n";
        os << "nearby_areas: [\n";
        for (const auto& nearby_tile : tile.nearby_areas) {
            os << "  " << *nearby_tile << ",\n";
        }
        os << "])";
        return os;
    }
}
