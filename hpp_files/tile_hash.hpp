//326648532
//menashe7676@gmail.com
/*
#ifndef TILE_HASH_HPP
#define TILE_HASH_HPP

#include <functional> // Include this for std::hash
#include "tile.hpp"

// Hash function for Tile
namespace std { // defined inside the std namespace because we are extending the standard template std::hash to work with our custom Tile class (it's designed for basic types like integers and strings so that's why we are extending it)
    // Templates are a feature in C++ that allow functions and classes to operate with generic types
    template <> // Here I use template specialization, it allows you to provide a specific implementation of a template for a particular type
    
   // This line declares a specialization of the std::hash template for the ariel::Tile type.
   // The empty angle brackets (<>) indicate that this is a specialization, not a general template.
    
    struct hash<ariel::Tile> {
        std::size_t operator()(const ariel::Tile& t) const; // Takes a Tile object and returns the hash value of it
    };
}

#endif

namespace std {
    template <>
    struct hash<ariel::Settlement> {
        std::size_t operator()(const ariel::Settlement& settlement) const {
            std::size_t seed = 0;
            for (const auto& tile : settlement.nearby_areas) {
                seed ^= std::hash<ariel::Tile>()(tile);
            }
            //combining the previously calculated seed with the hash value of the owner member of the Settlement
            return seed ^ std::hash<ariel::Player*>()(settlement.owner);
        }
    };
}


namespace std {
    template <>
    struct hash<ariel::City> {
        std::size_t operator()(const ariel::Settlement& city) const {
            std::size_t seed = 0;
            for (const auto& tile : city.nearby_areas) {
                seed ^= std::hash<ariel::Tile>()(tile);
            }
            //combining the previously calculated seed with the hash value of the owner member of the Settlement
            return seed ^ std::hash<ariel::Player*>()(city.owner);
        }
    };
}

// Hash function for Road
namespace std {
    template <>
    struct hash<ariel::Road> {
        std::size_t operator()(const ariel::Road& other) const { //The function call operator operator() allows an instance of a class or struct to be used as if it were a function.
            std::size_t seed = 0;
            for (const auto& tile : other.nearby_areas) {
                seed ^= std::hash<ariel::Tile>()(tile); //seed ^= XOR (^=) operator. used to combine the hash value of each Tile with the seed.
            }
            return seed;
        }
    };
}

*/