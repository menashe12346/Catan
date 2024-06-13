//326648532
//menashe7676@gmail.com

#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include <iostream>
#include <set>
#include <string>
#include "tile.hpp"

using namespace std;

namespace ariel {

class Settlement {
private:
    std::string nameOfOwner;
    std::set<Tile> nearby_areas;

public:
    /// @brief Parameterized constructor to initialize a Settlement
    /// @param nameOfOwner The name of the owner of the settlement
    /// @param tile1 The first nearby tile
    /// @param tile2 The second nearby tile
    /// @param tile3 The third nearby tile
    Settlement(std::string nameOfOwner, Tile tile1, Tile tile2, Tile tile3);

    /// @brief Getter for nearby_areas
    /// @return A constant reference to the set of nearby tiles
    const std::set<Tile>& getNearbyAreas() const;

    /// @brief Equality operator to compare two settlements
    /// @param other The other settlement to compare with
    /// @return True if the settlements are equal, false otherwise
    bool operator==(const Settlement& other) const;

    /// @brief Less-than operator to compare two settlements (for ordering)
    /// @param other The other settlement to compare with
    /// @return True if the current settlement is less than the other, false otherwise
    bool operator<(const Settlement& other) const;

    /// @brief Output operator to print a settlement
    /// @param os The output stream
    /// @param settlement The settlement object to print
    /// @return The output stream
    friend std::ostream& operator<<(std::ostream& os, const Settlement& settlement);
};

} // namespace ariel

#endif // SETTLEMENT_HPP
