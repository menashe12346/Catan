//326648532
//menashe7676@gmail.com

#ifndef ROAD_HPP
#define ROAD_HPP

#include <iostream>
#include <set>
#include <string>
#include "tile.hpp"

using namespace std;

namespace ariel {

    class Road {
    private:
        string nameOfOwner;
        set<Tile> nearby_areas;

    public:
        /// @brief Parameterized constructor to initialize a Road
        /// @param nameOfOwner The name of the owner of the road
        /// @param tile1 The first nearby tile
        /// @param tile2 The second nearby tile
        Road(string nameOfOwner, Tile tile1, Tile tile2);

        /// @brief Getter for nearby_areas
        /// @return A constant reference to the set of nearby tiles
        const std::set<Tile>& getNearbyAreas() const;

        /// @brief Equality operator to compare two roads
        /// @param other The other road to compare with
        /// @return True if the roads are equal, false otherwise
        bool operator==(const Road& other) const;

        /// @brief Less-than operator to compare two roads (for ordering)
        /// @param other The other road to compare with
        /// @return True if the current road is less than the other, false otherwise
        bool operator<(const Road& other) const;

        /// @brief Output operator to print a road
        /// @param os The output stream
        /// @param road The road object to print
        /// @return The output stream
        friend std::ostream& operator<<(std::ostream& os, const Road& road);
    };

}

#endif // ROAD_HPP