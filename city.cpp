#include "city.hpp"

namespace ariel {

    City::City() {}
    City::City(string nameOfOwner, Tile tile1, Tile tile2, Tile tile3) {
        this->nearby_areas.insert(tile1);
        this->nearby_areas.insert(tile2);
        this->nearby_areas.insert(tile3);
        this->nameOfOwner = nameOfOwner;
    }

    bool City::operator==(const City& other) const {
        return this->nameOfOwner == other.nameOfOwner && this->nearby_areas == other.nearby_areas;
    }

    bool City::operator<(const City& other) const 
    {
        return this->nameOfOwner< other.nameOfOwner;
    }
}