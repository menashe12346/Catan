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

    public:
        string nameOfOwner;
        set<Tile> nearby_areas;

        City();
        City(string nameOfOwner, Tile tile1, Tile tile2, Tile tile3);

        bool operator==(const City& other) const;
        bool operator<(const City& other) const;

        // Output operator
        friend std::ostream& operator<<(std::ostream& os, const City& city);
    };

}

#endif
