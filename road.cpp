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
        return this->nameOfOwner< other.nameOfOwner;
    }

    // Output operator implementation
    std::ostream& operator<<(std::ostream& os, const Road& road) {
        os << "Road(name of owner: " << road.nameOfOwner << ", nearby_areas: [";
        for (const auto& tile : road.nearby_areas) {
            os << tile << ", ";
        }
        os << "])";
        return os;
    }

}