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
        if (this->nearby_areas.size() != other.nearby_areas.size()) {
            return false;
        }

        auto it1 = this->nearby_areas.begin();
        auto it2 = other.nearby_areas.begin();
        while (it1 != this->nearby_areas.end() && it2 != other.nearby_areas.end()) {
            if (!(*it1 == *it2)) {
                return false;
            }
            ++it1;
            ++it2;
        }
        return true;
    }

    bool Settlement::operator<(const Settlement& other) const 
    {
        return this->nameOfOwner< other.nameOfOwner;
    }

    // Output operator implementation
    std::ostream& operator<<(std::ostream& os, const Settlement& settlement) {
        os << "Settlement(name of owner: " << settlement.nameOfOwner << "\n";
        os << "nearby_areas: [\n";
        for (const auto& tile : settlement.nearby_areas) {
            os << "  " << tile << ",\n";
        }
        os << "])\n";
        return os;
    }
}