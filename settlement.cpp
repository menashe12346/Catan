#include "settlement.hpp"

namespace ariel {

    Settlement::Settlement() {}
    Settlement::Settlement(string nameOfOwner, Tile tile1, Tile tile2, Tile tile3) {
        this->nearby_areas.insert(tile1);
        this->nearby_areas.insert(tile2);
        this->nearby_areas.insert(tile3);
        this->nameOfOwner = nameOfOwner;
    }

    bool Settlement::operator==(const Settlement& other) const {
        return this->nameOfOwner == other.nameOfOwner && this->nearby_areas == other.nearby_areas;
    }

    bool Settlement::operator<(const Settlement& other) const 
    {
        return this->nameOfOwner< other.nameOfOwner;
    }

    // Output operator implementation
    std::ostream& operator<<(std::ostream& os, const Settlement& settlement) {
        os << "Settlement(name of owner: " << settlement.nameOfOwner << ", nearby_areas: [";
        for (const auto& tile : settlement.nearby_areas) {
            os << tile << ", ";
        }
        os << "])";
        return os;
    }
}