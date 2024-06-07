#include "road.hpp"

namespace ariel {

    Road::Road(string nameOfOwner, Tile tile1, Tile tile2) {
        this->nearby_areas.insert(tile1);
        this->nearby_areas.insert(tile2);
        this->nameOfOwner = nameOfOwner;
    }

    bool Road::operator==(const Road& other) const {
        return this->nearby_areas == other.nearby_areas;
    }

    bool Road::operator<(const Road& other) const {
        return true;
       }
}