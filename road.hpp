//326648532
//menashe7676@gmail.com

#ifndef ROAD_HPP
#define ROAD_HPP

#include <iostream>
#include <set>
#include "tile.hpp"

using namespace std;

namespace ariel {
    class Road {
    private:


    public:
        string nameOfOwner;
        set<Tile>nearby_areas;

        Road(string nameOfOwner, Tile tile1, Tile tile2);

        bool operator==(const Road& other) const;
        bool operator<(const Road& other) const; // Less-than operator

        friend std::ostream& operator<<(std::ostream& os, const Road& road);
    };
}


#endif
