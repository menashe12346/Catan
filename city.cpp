#include "city.hpp"

namespace ariel {

City::City() : nameOfOwner("") {
    std::cout << "City default constructor called" << std::endl;
}

City::City(std::string nameOfOwner, Tile tile1, Tile tile2, Tile tile3) {
    this->nearby_areas.insert(tile1);
    this->nearby_areas.insert(tile2);
    this->nearby_areas.insert(tile3);
    this->nameOfOwner = nameOfOwner;
        std::cout << "City constructor called for owner: " << nameOfOwner << std::endl;

}

bool City::operator==(const City& other) const {
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

bool City::operator<(const City& other) const {
        std::cout << "Comparing " << this->nameOfOwner << " with " << other.nameOfOwner << std::endl;

    return this->nameOfOwner < other.nameOfOwner;
}

// Output operator implementation
std::ostream& operator<<(std::ostream& os, const City& city) {
    os << "City(name of owner: " << city.nameOfOwner << "\n";
    os << "nearby_areas: [\n";
    for (const auto& tile : city.nearby_areas) {
        os << "  " << tile << ",\n";
    }
    os << "])\n";
    return os;
}

}  // namespace ariel
