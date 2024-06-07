#include "city.hpp"

namespace ariel {

    City::City(){}
    City::City(string nameOfOwner) : nameOfOwner(nameOfOwner) {}

    bool City::operator==(const City& other) const {
        return this->nameOfOwner == other.nameOfOwner && this->nearby_areas == other.nearby_areas;
    }

    bool City::operator<(const City& other) const {
        return true;
    }
}