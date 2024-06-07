#ifndef TILE_HPP
#define TILE_HPP

#include <set>
#include <string>

namespace ariel {

/*
enum class Terrain {
    Mountains,
    Forest,
    Pasture_Land,
    Agricultural_Land,
    Hills
};
*/

class Tile {
public:
    Tile(); // Default constructor
    Tile(std::string terrain, int number); // Parameterized constructor
    
    bool operator==(const Tile& other) const; // Equality operator
    bool operator<(const Tile& other) const; // Less-than operator

    std::string terrain;
    int number;
    std::set<Tile> nearby_areas; 
};

}

#endif
