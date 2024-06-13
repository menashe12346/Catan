//326648532
//menashe7676@gmail.com

#ifndef CITY_HPP
#define CITY_HPP

#include <iostream>
#include <set>
#include "tile.hpp"

using namespace std;

namespace ariel {

    class City {
    private:
        string nameOfOwner; 
        set<Tile> nearby_areas;

    public:

        /// @brief Parameterized constructor
        /// @param nameOfOwner Name of the owner of the city
        /// @param tile1 First tile near the city
        /// @param tile2 Second tile near the city
        /// @param tile3 Third tile near the city
        City(string nameOfOwner, Tile tile1, Tile tile2, Tile tile3);

        /// @brief Getter for nearby_areas
        /// @return A constant reference to the set of nearby tiles
        const std::set<Tile>& getNearbyAreas() const;

        /// @brief Equality operator
        /// @param other The city object to compare with
        /// @return True if the cities are equal, false otherwise
        bool operator==(const City& other) const;

        /// @brief Less-than operator (to make a set)
        /// @param other The city object to compare with
        /// @return True if the current city is less than the other, false otherwise
        bool operator<(const City& other) const;

        /// @brief Output operator
        /// @param os The output stream
        /// @param city The city object to output
        /// @return The output stream
        friend std::ostream& operator<<(std::ostream& os, const City& city);
    };

}

#endif
